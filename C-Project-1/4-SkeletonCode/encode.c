#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encode.h"
#include "types.h"

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3;
}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "rb");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);
        return e_failure;
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);
        return e_failure;
    }

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "wb");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);
        return e_failure;
    }

    // No failure return e_success
    return e_success;
}

Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    // Check if required arguments exist
    if (argv[2] == NULL || argv[3] == NULL)
    {
        printf("Error: Missing required arguments\n");
        return e_failure;
    }
    
    // Validate source image file has .bmp extension
    if (strstr(argv[2], ".bmp") == NULL)
    {
        printf("Error: Source image should have .bmp extension\n");
        return e_failure;
    }
    encInfo->src_image_fname = argv[2];

    // Validate secret file has an extension
    if (strchr(argv[3], '.') == NULL)
    {
        printf("Error: Secret file should have an extension\n");
        return e_failure;
    }
    encInfo->secret_fname = argv[3];
    strcpy(encInfo->extn_secret_file, strchr(argv[3], '.'));

    // Handle optional output filename
    if (argv[4] == NULL)
    {
        encInfo->stego_image_fname = "stego.bmp";
    }
    else if (strstr(argv[4], ".bmp") == NULL)
    {
        printf("Error: Output file should be in .bmp format\n");
        return e_failure;
    }
    else
    {
        encInfo->stego_image_fname = argv[4];
    }
    
    return e_success;
}

uint get_file_size(FILE *fptr_image)
{
    fseek(fptr_image, 0, SEEK_END);
    long size = ftell(fptr_image);
    rewind(fptr_image);
    return size;
}

Status check_capacity(EncodeInfo *encInfo)
{
    encInfo->image_capacity = get_image_size_for_bmp(encInfo->fptr_src_image);
    encInfo->size_secret_file = get_file_size(encInfo->fptr_secret);
    
    // Calculate required size: magic string(2) + extn_size(4) + extension + file_size(4) + file_data
    int required_size = (2 + 4 + strlen(encInfo->extn_secret_file) + 4 + encInfo->size_secret_file) * 8;
    
    if (encInfo->image_capacity > required_size)
    {
        printf("Image has enough capacity for encoding\n");
        return e_success;
    }
    else
    {
        printf("Error: Image doesn't have enough capacity for encoding\n");
        return e_failure;
    }
}

Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{
    char buffer[54];
    fseek(fptr_src_image, 0, SEEK_SET);
    fread(buffer, 54, 1, fptr_src_image);
    fwrite(buffer, 54, 1, fptr_dest_image);
    printf("BMP header copied successfully\n");
    return e_success;
}

Status encode_byte_to_lsb(char data, char *image_buffer)
{
    for (int i = 0; i < 8; i++)
    {
        image_buffer[i] &= 0xFE;  // Clear LSB
        image_buffer[i] |= ((data >> (7 - i)) & 1);  // Set LSB with data bit
    }
    return e_success;
}

// Match header: char *data (not const char *)
Status encode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image)
{
    char image_buffer[8];
    for (int i = 0; i < size; i++)
    {
        fread(image_buffer, 8, 1, fptr_src_image);
        encode_byte_to_lsb(data[i], image_buffer);
        fwrite(image_buffer, 8, 1, fptr_stego_image);
    }
    return e_success;
}

Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
    printf("Encoding magic string\n");
    encode_data_to_image((char *)magic_string, strlen(magic_string), encInfo->fptr_src_image, encInfo->fptr_stego_image);
    return e_success;
}

Status encode_size_to_lsb(int size, char *image_buffer)
{
    for (int i = 0; i < 32; i++)
    {
        image_buffer[i] &= 0xFE;  // Clear LSB
        image_buffer[i] |= ((size >> (31 - i)) & 1);  // Set LSB with size bit
    }
    return e_success;
}

// Match header: const char *file_extn
Status encode_secret_file_extn_size(const char *file_extn, EncodeInfo *encInfo)
{
    printf("Encoding secret file extension size\n");
    char buffer[32];
    int extn_size = strlen(file_extn);
    fread(buffer, 32, 1, encInfo->fptr_src_image);
    encode_size_to_lsb(extn_size, buffer);
    fwrite(buffer, 32, 1, encInfo->fptr_stego_image);
    return e_success;
}

// Match header: const char *file_extn
Status encode_secret_file_extn(const char *file_extn, EncodeInfo *encInfo)
{
    printf("Encoding secret file extension\n");
    encode_data_to_image((char *)file_extn, strlen(file_extn), 
                        encInfo->fptr_src_image, encInfo->fptr_stego_image);
    return e_success;
}

// Match header: long file_size
Status encode_secret_file_size(long file_size, EncodeInfo *encInfo)
{
    printf("Encoding secret file size\n");
    char buffer[32];
    fread(buffer, 32, 1, encInfo->fptr_src_image);
    encode_size_to_lsb((int)file_size, buffer);
    fwrite(buffer, 32, 1, encInfo->fptr_stego_image);
    return e_success;
}

OperationType check_operation_type(char *argv[])
{
    if (argv[1] == NULL)
    {
        return e_unsupported;
    }
    
    if (strcmp(argv[1], "-e") == 0)
    {
        return e_encode;
    }
    else if (strcmp(argv[1], "-d") == 0)
    {
        return e_decode;
    }
    else
    {
        return e_unsupported;
    }
}

Status encode_secret_file_data(EncodeInfo *encInfo)
{
    printf("Encoding secret file data\n");
    char *buffer = malloc(encInfo->size_secret_file);
    if (buffer == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return e_failure;
    }
    
    fseek(encInfo->fptr_secret, 0, SEEK_SET);
    fread(buffer, encInfo->size_secret_file, 1, encInfo->fptr_secret);
    encode_data_to_image(buffer, encInfo->size_secret_file, 
                        encInfo->fptr_src_image, encInfo->fptr_stego_image);
    free(buffer);
    return e_success;
}

Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest)
{
    char ch;
    while (fread(&ch, 1, 1, fptr_src) > 0)
    {
        fwrite(&ch, 1, 1, fptr_dest);
    }
    return e_success;
}

Status do_encoding(EncodeInfo *encInfo)
{
    // Open files
    if (open_files(encInfo) == e_failure)
    {
        printf("Error: Failed to open files\n");
        return e_failure;
    }
    printf("Files opened successfully\n");

    // Check capacity
    if (check_capacity(encInfo) == e_failure)
    {
        printf("Error: Capacity check failed\n");
        return e_failure;
    }

    // Copy BMP header
    if (copy_bmp_header(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_failure)
    {
        printf("Error: Failed to copy BMP header\n");
        return e_failure;
    }

    // Encode magic string (use "#*" as default magic string)
    if (encode_magic_string("#*", encInfo) == e_failure)
    {
        printf("Error: Failed to encode magic string\n");
        return e_failure;
    }

    // Encode secret file extension size
    if (encode_secret_file_extn_size(encInfo->extn_secret_file, encInfo) == e_failure)
    {
        printf("Error: Failed to encode extension size\n");
        return e_failure;
    }

    // Encode secret file extension
    if (encode_secret_file_extn(encInfo->extn_secret_file, encInfo) == e_failure)
    {
        printf("Error: Failed to encode file extension\n");
        return e_failure;
    }

    // Encode secret file size
    if (encode_secret_file_size(encInfo->size_secret_file, encInfo) == e_failure)
    {
        printf("Error: Failed to encode file size\n");
        return e_failure;
    }

    // Encode secret file data
    if (encode_secret_file_data(encInfo) == e_failure)
    {
        printf("Error: Failed to encode file data\n");
        return e_failure;
    }

    // Copy remaining image data
    if (copy_remaining_img_data(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_failure)
    {
        printf("Error: Failed to copy remaining data\n");
        return e_failure;
    }

    printf("Encoding completed successfully\n");
    return e_success;
}