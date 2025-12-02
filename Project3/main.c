#include <stdio.h>
#include <string.h>
#include "mp3.h"



void print_help()
{
    printf("--------------------------------------------------------------\n");
    printf(" MP3 TAG READER AND EDITOR\n");
    printf("--------------------------------------------------------------\n");
    printf("USAGE:\n");
    printf("  View Tags:\n");
    printf("      ./a.out -v <filename.mp3>\n\n");
    printf("  Edit Tags:\n");
    printf("      ./a.out -e <option> \"text\" <filename.mp3>\n\n");
    printf("OPTIONS:\n");
    printf("   -t   Edit Title\n");
    printf("   -a   Edit Artist\n");
    printf("   -A   Edit Album\n");
    printf("   -y   Edit Year\n");
    printf("   -c   Edit Comment\n");
    printf("   -m   Edit Track Number\n\n");
    printf("   --help   Show Help\n");
    printf("--------------------------------------------------------------\n");
}



int main(int argc, char *argv[])
{
    if (argc < 2) {
        print_help();
        return 1;
    }

    // ---------------------------
    // Handle --help
    // ---------------------------
    if (strcmp(argv[1], "--help") == 0) {
        print_help();
        return 0;
    }

    // ---------------------------
    // Handle View Tag: -v file.mp3
    // ---------------------------
    if (strcmp(argv[1], "-v") == 0)
    {
        if (argc < 3) {
            printf("ERROR: Missing filename.\n");
            printf("Usage: ./a.out -v file.mp3\n");
            return 1;
        }

        mp3_view(argv[2]);
        return 0;
    }

    // ---------------------------
    // Handle Edit Options
    // Format: ./a.out -e -t  "NEW TITLE"  file.mp3
    // ---------------------------
    if (strcmp(argv[1], "-e") == 0)
    {
        if (argc < 5) {
            printf("ERROR: Not enough arguments for edit operation.\n");
            printf("Usage: ./a.out -e -t/-a/-A/-m/-y/-c \"text\" file.mp3\n");
            return 1;
        }

        char *operation = argv[2];
        char *text = argv[3];
        char *filename = argv[4];

        if (strcmp(operation, "-t") == 0)
            mp3_edit_title(text, filename);

        else if (strcmp(operation, "-a") == 0)
            mp3_edit_artist(text, filename);

        else if (strcmp(operation, "-A") == 0)
            mp3_edit_album(text, filename);

        else if (strcmp(operation, "-y") == 0)
            mp3_edit_year(text, filename);

        else if (strcmp(operation, "-c") == 0)
            mp3_edit_comment(text, filename);

        else if (strcmp(operation, "-m") == 0)
            mp3_edit_track(text, filename);

        else {
            printf("ERROR: Invalid edit option: %s\n", operation);
            print_help();
        }

        return 0;
    }

    // ---------------------------
    // Invalid argument
    // ---------------------------
    printf("ERROR: Invalid argument!\n");
    print_help();
    return 1;
}


// ------------------------------------------------
// Function Implementations
// ------------------------------------------------

void mp3_view(const char *filename)
{
    mp3tag_reader(filename);
}

void mp3_edit_title(const char *text, const char *filename)
{
    printf("Editing TITLE...\n");
    edit_text_frame(filename, "TIT2", text);
}

void mp3_edit_artist(const char *text, const char *filename)
{
    printf("Editing ARTIST...\n");
    edit_text_frame(filename, "TPE1", text);
}

void mp3_edit_album(const char *text, const char *filename)
{
    printf("Editing ALBUM...\n");
    edit_text_frame(filename, "TALB", text);
}

void mp3_edit_year(const char *text, const char *filename)
{
    printf("Editing YEAR...\n");
    edit_text_frame(filename, "TYER", text);
}

void mp3_edit_comment(const char *text, const char *filename)
{
    printf("Editing COMMENT...\n");
    edit_text_frame(filename, "COMM", text);
}

void mp3_edit_track(const char *text, const char *filename)
{
    printf("Editing TRACK NUMBER...\n");
    edit_text_frame(filename, "TRCK", text);
}



