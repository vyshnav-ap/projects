#ifndef DECODE_H
#define DECODE_H

#include "types.h"

/* 
 * Structure to store information required for
 * decoding secret file from stego image
 */

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 10

typedef struct _DecodeInfo
{
    /* Stego Image Info */
    char *stego_image_fname;
    FILE *fptr_stego_image;

    /* Secret File Info */
    char *secret_fname;
    char extn_secret_file[MAX_FILE_SUFFIX];
    FILE *fptr_secret;
    long size_secret_file;

} DecodeInfo;

/* Decoding function prototypes */

/* Read and validate decode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* Perform the decoding */
Status do_decoding(DecodeInfo *decInfo);

/* Get File pointers for i/p and o/p files */
Status open_files_dec(DecodeInfo *decInfo);

/* Skip BMP header */
Status skip_bmp_header(FILE *fptr_stego_image);

/* Decode Magic String */
Status decode_magic_string(DecodeInfo *decInfo);

/* Decode byte from LSB */
Status decode_byte_from_lsb(char *data, char *image_buffer);

/* Decode data from image */
Status decode_data_from_image(int size, FILE *fptr_stego_image, char *data);

/* Decode secret file extension size */
Status decode_secret_file_extn_size(DecodeInfo *decInfo);

/* Decode size from LSB */
Status decode_size_from_lsb(char *buffer, int *size);

/* Decode secret file extension */
Status decode_secret_file_extn(int extn_size, DecodeInfo *decInfo);

/* Decode secret file size */
Status decode_secret_file_size(DecodeInfo *decInfo);

/* Decode secret file data */
Status decode_secret_file_data(DecodeInfo *decInfo);

#endif