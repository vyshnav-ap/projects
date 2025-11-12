#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "decode.h"
#include "types.h"

/* Function Definitions */

/* Read and validate decode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    // Check if stego image file is provided
    if (argv[2] == NULL)
    {
        printf("Error: Stego image file not provided\n");
        return e_failure;
    }

    // Validate stego image has .bmp extension
    if (strstr(argv[2], ".bmp") == NULL)
    {
        printf("Error: Stego image should have .bmp extension\n");
        return e_failure;
    }
    decInfo->stego_image_fname = argv[2];

    // Handle optional output filename
    if (argv[3] == NULL)
    {
        decInfo->secret_fname = "decoded_secret";
    }
    else
    {
        decInfo->secret_fname = argv[3];
    }

    return e_success;
}

/* Open files for decoding */
Status open_files_dec(DecodeInfo *decInfo)
{
    // Stego Image file
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "rb");
    if (decInfo->fptr_stego_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->stego_image_fname);
        return e_failure;
    }

    // Secret file will be opened after we decode the extension
    return e_success;
}

/* Skip BMP header (54 bytes) */
Status skip_bmp_header(FILE *fptr_stego_image)
{
    fseek(fptr_stego_image, 54, SEEK_SET);
    printf("BMP header skipped successfully\n");
    return e_success;
}

/* Decode byte from LSB */
Status decode_byte_from_lsb(char *data, char *image_buffer)
{
    *data = 0;
    for (int i = 0; i < 8; i++)
    {
        *data |= ((image_buffer[i] & 1) << (7 - i));
    }
    return e_success;
}

/* Decode data from image */
Status decode_data_from_image(int size, FILE *fptr_stego_image, char *data)
{
    char image_buffer[8];
    for (int i = 0; i < size; i++)
    {
        fread(image_buffer, 8, 1, fptr_stego_image);
        decode_byte_from_lsb(&data[i], image_buffer);
    }
    return e_success;
}

/* Decode magic string */
Status decode_magic_string(DecodeInfo *decInfo)
{
    printf("Decoding magic string\n");
    char magic_string[3];
    magic_string[2] = '\0';
    
    decode_data_from_image(2, decInfo->fptr_stego_image, magic_string);
    
    if (strcmp(magic_string, "#*") != 0)
    {
        printf("Error: Invalid magic string. This may not be an encoded image.\n");
        printf("Expected: #*, Got: %s\n", magic_string);
        return e_failure;
    }
    
    printf("Magic string decoded successfully\n");
    return e_success;
}

/* Decode size from LSB */
Status decode_size_from_lsb(char *buffer, int *size)
{
    *size = 0;
    for (int i = 0; i < 32; i++)
    {
        *size |= ((buffer[i] & 1) << (31 - i));
    }
    return e_success;
}

/* Decode secret file extension size */
Status decode_secret_file_extn_size(DecodeInfo *decInfo)
{
    printf("Decoding secret file extension size\n");
    char buffer[32];
    int extn_size;
    
    fread(buffer, 32, 1, decInfo->fptr_stego_image);
    decode_size_from_lsb(buffer, &extn_size);
    
    printf("Extension size: %d bytes\n", extn_size);
    return e_success;
}

/* Decode secret file extension */
Status decode_secret_file_extn(int extn_size, DecodeInfo *decInfo)
{
    printf("Decoding secret file extension\n");
    
    if (extn_size <= 0 || extn_size > MAX_FILE_SUFFIX)
    {
        printf("Error: Invalid extension size %d\n", extn_size);
        return e_failure;
    }
    
    decode_data_from_image(extn_size, decInfo->fptr_stego_image, decInfo->extn_secret_file);
    decInfo->extn_secret_file[extn_size] = '\0';
    
    printf("Extension decoded: %s\n", decInfo->extn_secret_file);
    return e_success;
}

/* Decode secret file size */
Status decode_secret_file_size(DecodeInfo *decInfo)
{
    printf("Decoding secret file size\n");
    char buffer[32];
    int file_size;
    
    fread(buffer, 32, 1, decInfo->fptr_stego_image);
    decode_size_from_lsb(buffer, &file_size);
    
    if (file_size <= 0)
    {
        printf("Error: Invalid file size\n");
        return e_failure;
    }
    
    decInfo->size_secret_file = file_size;
    printf("Secret file size: %ld bytes\n", decInfo->size_secret_file);
    
    return e_success;
}

/* Decode secret file data */
Status decode_secret_file_data(DecodeInfo *decInfo)
{
    printf("Decoding secret file data\n");
    
    // Allocate buffer for secret data
    char *buffer = malloc(decInfo->size_secret_file + 1);
    if (buffer == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return e_failure;
    }
    
    // Decode the secret data
    decode_data_from_image(decInfo->size_secret_file, decInfo->fptr_stego_image, buffer);
    buffer[decInfo->size_secret_file] = '\0';
    
    // Create output filename with extension
    char output_filename[256];
    strcpy(output_filename, decInfo->secret_fname);
    strcat(output_filename, decInfo->extn_secret_file);
    
    // Open output file and write decoded data
    decInfo->fptr_secret = fopen(output_filename, "wb");
    if (decInfo->fptr_secret == NULL)
    {
        printf("Error: Unable to create output file %s\n", output_filename);
        free(buffer);
        return e_failure;
    }
    
    fwrite(buffer, decInfo->size_secret_file, 1, decInfo->fptr_secret);
    fclose(decInfo->fptr_secret);
    
    printf("Secret file decoded successfully\n");
    printf("Output file: %s\n", output_filename);
    
    free(buffer);
    return e_success;
}

/* Perform the decoding */
Status do_decoding(DecodeInfo *decInfo)
{
    printf("\n========================================\n");
    printf("## Decoding Procedure Started ##\n");
    printf("========================================\n\n");
    
    // Open stego image file
    printf("Opening files\n");
    if (open_files_dec(decInfo) == e_failure)
    {
        printf("Error: Failed to open stego image file\n");
        return e_failure;
    }
    printf("Stego image file opened successfully\n\n");
    
    // Skip BMP header
    if (skip_bmp_header(decInfo->fptr_stego_image) == e_failure)
    {
        printf("Error: Failed to skip BMP header\n");
        fclose(decInfo->fptr_stego_image);
        return e_failure;
    }
    printf("\n");
    
    // Decode magic string
    if (decode_magic_string(decInfo) == e_failure)
    {
        printf("Error: Failed to decode magic string\n");
        fclose(decInfo->fptr_stego_image);
        return e_failure;
    }
    printf("\n");
    
    // Decode extension size
    int extn_size;
    char buffer[32];
    printf("Decoding file extension size\n");
    fread(buffer, 32, 1, decInfo->fptr_stego_image);
    decode_size_from_lsb(buffer, &extn_size);
    printf("Extension size: %d bytes\n\n", extn_size);
    
    // Decode extension
    if (decode_secret_file_extn(extn_size, decInfo) == e_failure)
    {
        printf("Error: Failed to decode file extension\n");
        fclose(decInfo->fptr_stego_image);
        return e_failure;
    }
    printf("\n");
    
    // Decode file size
    if (decode_secret_file_size(decInfo) == e_failure)
    {
        printf("Error: Failed to decode file size\n");
        fclose(decInfo->fptr_stego_image);
        return e_failure;
    }
    printf("\n");
    
    // Decode file data
    if (decode_secret_file_data(decInfo) == e_failure)
    {
        printf("Error: Failed to decode file data\n");
        fclose(decInfo->fptr_stego_image);
        return e_failure;
    }
    
    // Close stego image file
    fclose(decInfo->fptr_stego_image);
    
    printf("\n========================================\n");
    printf("## Decoding Completed Successfully ##\n");
    printf("========================================\n");
    
    return e_success;
}