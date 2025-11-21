#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static uint32_t be32(const uint8_t *b) {
    return (b[0] << 24) | (b[1] << 16) | (b[2] << 8) | b[3];
}

static uint32_t syncsafe(const uint8_t *b) {
    return ((b[0] & 0x7F) << 21) |
           ((b[1] & 0x7F) << 14) |
           ((b[2] & 0x7F) << 7)  |
           (b[3] & 0x7F);
}

/* ID3v2.3 text decoding */
static void decode_text(const uint8_t *data, uint32_t size, char *out, int outlen) {
    if (size == 0) { out[0] = 0; return; }

    uint8_t encoding = data[0];
    const uint8_t *p = data + 1;
    size--;

    if (encoding == 0) {
        /* ISO-8859-1 → copy directly */
        int n = (size < outlen - 1) ? size : outlen - 1;
        memcpy(out, p, n);
        out[n] = 0;
    } 
    else if (encoding == 1) {
        /* UTF-16 → skip BOM and copy low bytes (simple fallback) */
        if (size < 2) { out[0] = 0; return; }

        p += 2;  /* skip BOM FF FE or FE FF */
        size -= 2;

        int o = 0;
        for (uint32_t i = 0; i + 1 < size && o < outlen - 1; i += 2)
            out[o++] = p[i];  /* low byte only */

        out[outlen - 1] = 0;
    } 
    else {
        strcpy(out, "<unsupported-encoding>");
    }
}

static void read_id3v23(const char *file) {
    FILE *fp = fopen(file, "rb");
    if (!fp) { puts("Cannot open file"); return; }

    uint8_t hdr[10];
    if (fread(hdr, 1, 10, fp) != 10) return;

    if (memcmp(hdr, "ID3", 3) != 0) {
        puts("No ID3 tag found");
        fclose(fp);
        return;
    }

    int version = hdr[3];
    if (version != 3) {
        printf("This file is ID3v2.%d, not v2.3\n", version);
        fclose(fp);
        return;
    }

    uint32_t tag_size = syncsafe(hdr + 6);

    printf("=== ID3v2.3 Tag Found (%u bytes) ===\n", tag_size);

    uint32_t pos = 0;
    while (pos + 10 < tag_size) {
        uint8_t fh[10];
        fread(fh, 1, 10, fp);
        pos += 10;

        if (fh[0] == 0) break; // padding

        char id[5];
        memcpy(id, fh, 4);
        id[4] = 0;

        uint32_t size = be32(fh + 4);

        if (size == 0) break;
        if (pos + size > tag_size) break;

        uint8_t *buf = malloc(size);
        fread(buf, 1, size, fp);
        pos += size;

        char out[1024] = {0};

        if (id[0] == 'T') {
            decode_text(buf, size, out, sizeof(out));

            if (strcmp(id, "TIT2") == 0) printf("Title : %s\n", out);
            if (strcmp(id, "TPE1") == 0) printf("Artist: %s\n", out);
            if (strcmp(id, "TALB") == 0) printf("Album : %s\n", out);
            if (strcmp(id, "TYER") == 0) printf("Year  : %s\n", out);
            if (strcmp(id, "TRCK") == 0) printf("Track : %s\n", out);
            if (strcmp(id, "TCON") == 0) printf("Genre : %s\n", out);
        }

        free(buf);
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s file.mp3\n", argv[0]);
        return 1;
    }

    read_id3v23(argv[1]);
    return 0;
}
