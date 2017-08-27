#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;
int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./copy image\n");
        return 1;
    }
    // remember filenames
    char *infile = argv[1];
    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    //*****************************************************************************
    int count = 0;
    // BYTE *buffer = malloc(512 * sizeof(BYTE));
    BYTE buffer[512];
    int eof = 0;
    do{
    //*****************************************************************************
    // read the card buffer by buffer
        // for(int i = 0; i < 512; i++){
        //     buffer[i] = 0;
        // }
        eof = fread(&buffer, sizeof(BYTE), 512, inptr);
    // ensure the buffer is the beginning of one JPEG
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0){
            //JPEG found
            // create the output JPEGs
            //****************************************************
            char filename[50];
            sprintf(filename, "%03i.jpg", count);
            // char *outfile = filename[0];
            FILE *outptr = fopen(filename, "w");
            if (outptr == NULL){
            fclose(inptr);
            fprintf(stderr, "Could not create %s.\n", filename);
            return 3;
            }
            //****************************************************
            do{
                fwrite(&buffer, sizeof(BYTE), 512, outptr);
                // for(int i = 0; i < 512; i++){
                //     buffer[i] = 0;
                // }
                // BYTE *buffer = malloc(512 * sizeof(BYTE));
                eof = fread(&buffer, sizeof(BYTE), 512, inptr);

            }while(((buffer[0] == 0xff &&
                    buffer[1] == 0xd8 &&
                    buffer[2] == 0xff &&
                    (buffer[3] & 0xf0) == 0xe0) == false) && (eof == 512));

            if ((buffer[0] == 0xff &&
                buffer[1] == 0xd8 &&
                buffer[2] == 0xff &&
                (buffer[3] & 0xf0) == 0xe0)){
                fclose(outptr);
                count = count + 1;
            }
            if( eof != 512){
                fwrite(&buffer, sizeof(BYTE), eof, outptr);
                fclose(outptr);

            }
            fseek(inptr, -(512 * sizeof(BYTE)), SEEK_CUR);
        }

    }while(eof == 512);

    fclose(inptr);
    return 0;
}

