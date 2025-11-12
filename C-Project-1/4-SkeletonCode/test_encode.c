#include <stdio.h>
#include "encode.h"
#include "types.h"
#include "decode.h"

int main(int argc, char *argv[])
{
    int res = check_operation_type(argv);
    
    if (res == e_encode)
    {
        EncodeInfo encInfo;
        
        if (read_and_validate_encode_args(argv, &encInfo) == e_failure)
        {
            printf("Error: Validation failed\n");
            return 1;
        }
        
        if (do_encoding(&encInfo) == e_failure)
        {
            printf("Error: Encoding failed\n");
            return 1;
        }
    }
    else if (res == e_decode)
    {
    DecodeInfo decInfo;
    
    if (read_and_validate_decode_args(argv, &decInfo) == e_failure)
    {
        printf("Error: Decode validation failed\n");
        return 1;
    }
    
    if (do_decoding(&decInfo) == e_failure)
    {
        printf("Error: Decoding failed\n");
        return 1;
    }
    }
    else
    {
        printf("Invalid operation\n");
        printf("Usage:\n");
        printf("Encoding: ./a.out -e <source.bmp> <secret.txt> [output.bmp]\n");
        printf("Decoding: ./a.out -d <stego.bmp> [output.txt]\n");
        return 1;
    }
    
    return 0;
}



/*#include <stdio.h>
#include "encode.h"
#include "types.h"

int main()
{
    EncodeInfo encInfo;
    uint img_size;

    int res = check_operation_type(argv);
    return 0;
}
Status do_encoding();*/