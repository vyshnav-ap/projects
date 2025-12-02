#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "mp3.h"

// Convert syncsafe ID3 size
static uint32_t syncsafe_to_int(const uint8_t b[4]) {
    return ((b[0] & 0x7F) << 21) |
           ((b[1] & 0x7F) << 14) |
           ((b[2] & 0x7F) << 7)  |
            (b[3] & 0x7F);
}

//
// ------------ READ ID3 TAG (VIEW MODE) -------------
//
void print_frame_text(FILE *fp, const char *label, uint32_t frame_size)
{
    uint8_t encoding;
    fread(&encoding, 1, 1, fp);
    frame_size--;

    uint8_t buf[2048] = {0};
    fread(buf, 1, frame_size, fp);

    printf("%s: ", label);

    if (encoding == 0) {
        printf("%s\n", buf);
    }
    else if (encoding == 1) {
        printf("(UTF-16) ");
        for (int i = 2; i < frame_size; i += 2)
            putchar(buf[i]);
        printf("\n");
    }
}

void mp3tag_reader(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("ERROR: Cannot open file: %s\n", filename);
        return;
    }

    uint8_t header[10];
    if (fread(header, 1, 10, fp) != 10) {
        printf("ERROR: Cannot read ID3 header\n");
        fclose(fp);
        return;
    }

    if (memcmp(header, "ID3", 3) != 0) {
        printf("ERROR: No ID3 tag found\n");
        fclose(fp);
        return;
    }

    uint32_t tag_size = syncsafe_to_int(&header[6]);
    printf("Tag Size: %u bytes\n", tag_size);

    uint32_t bytes_read = 0;

    while (bytes_read < tag_size)
    {
        uint8_t fh[10];
        if (fread(fh, 1, 10, fp) != 10)
            break;

        if (fh[0] == 0)
            break; // padding

        char id[5] = {0};
        memcpy(id, fh, 4);

        uint32_t frame_size =
            (fh[4] << 24) |
            (fh[5] << 16) |
            (fh[6] <<  8) |
             fh[7];

        bytes_read += 10 + frame_size;

        // matching frames
        if (strcmp(id, "TPE1") == 0)
        {
            print_frame_text(fp, "ARTIST", frame_size);
            continue;
        }
        if (strcmp(id, "TIT2") == 0)
        {
            print_frame_text(fp, "TITLE", frame_size);
            continue;
        }
        if (strcmp(id, "TALB") == 0)
        {
            print_frame_text(fp, "ALBUM", frame_size);
            continue;
        }
        if (strcmp(id, "TYER") == 0)
        {
            print_frame_text(fp, "YEAR", frame_size);
            continue;
        }
        if (strcmp(id, "TCON") == 0)
        {
            print_frame_text(fp, "GENRE", frame_size);
            continue;
        }
        if (strcmp(id, "TCOM") == 0)
        {
            print_frame_text(fp, "COMPOSER", frame_size);
            continue;
        }

        // not a frame we care about → skip
        fseek(fp, frame_size, SEEK_CUR);
    }

    fclose(fp);
}

//
// ------------ EDIT ANY TEXT FRAME (TIT2, TPE1, etc.) ------------
//
void edit_text_frame(const char *filename, const char *frame_id, const char *new_text)
{
    FILE *fp = fopen(filename, "r+b");
    if (!fp) {
        printf("ERROR: Cannot open %s\n", filename);
        return;
    }

    uint8_t header[10];
    fread(header, 1, 10, fp);

    if (memcmp(header, "ID3", 3) != 0) {
        printf("ERROR: No ID3 tag found\n");
        fclose(fp);
        return;
    }

    uint32_t tag_size = syncsafe_to_int(&header[6]);
    long pos = 10;

    while (pos < tag_size)
    {
        uint8_t frame_header[10];
        fseek(fp, pos, SEEK_SET);

        if (fread(frame_header, 1, 10, fp) != 10)
            break;

        if (frame_header[0] == 0)
            break;

        char id[5] = {0};
        memcpy(id, frame_header, 4);

        uint32_t frame_size =
            (frame_header[4] << 24) |
            (frame_header[5] << 16) |
            (frame_header[6] << 8)  |
             frame_header[7];

        if (strcmp(id, frame_id) == 0)
        {
            printf("Found %s → Editing...\n", frame_id);

            fseek(fp, pos + 10, SEEK_SET);

            uint8_t encoding = 0;  // ISO-8859-1
            fwrite(&encoding, 1, 1, fp);

            fwrite(new_text, 1, strlen(new_text), fp);

            // pad remaining bytes
            int remain = frame_size - 1 - strlen(new_text);
            while (remain-- > 0)
                fputc(0, fp);

            printf("Updated %s successfully!\n", frame_id);
            fclose(fp);
            return;
        }

        pos += 10 + frame_size;
    }

    printf("ERROR: Frame %s not found.\n", frame_id);
    fclose(fp);
}
