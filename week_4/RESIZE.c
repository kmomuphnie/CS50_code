/**
 * Copies a BMP piece by piece, just because.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4 || (atoi(argv[1]) > 100) || (atoi(argv[1]) < 0))
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    int factor = atoi(argv[1]);

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }




    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);


    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    int padding1 = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    LONG widthOriginal = bi.biWidth;
    LONG heightOriginal = abs(bi.biHeight);

    bi.biWidth = bi.biWidth * factor;
    bi.biHeight = bi.biHeight * factor;

    int padding2 = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    // determine padding for scanlines

    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding2) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);





    int index = 0;
    // iterate over infile's scanlines
    for (int i = 0; i < heightOriginal; i++)
    {
        RGBTRIPLE *copy = malloc(sizeof(RGBTRIPLE) * widthOriginal);
        index = 0;


             // iterate over pixels in scanline
        for (int j = 0; j < widthOriginal; j++){
            // temporary storage
            RGBTRIPLE triple;
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            // // write RGB triple to outfile
            // fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            copy[index] = triple;
            index = index + 1;
            for(int t = 0; t < factor ; t++){
                // write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }
        // skip over padding, if any
        fseek(inptr, padding1, SEEK_CUR);
        // then add it back (to demonstrate how)
        for (int k = 0; k < padding2; k++){
            fputc(0x00, outptr);
        }

        //output the copy of this line
        for(int h = 0; h < factor - 1; h++){
            for(int x = 0; x < widthOriginal; x++){

                for(int t = 0; t < factor ; t++){
                // write RGB triple to outfile
                fwrite(&copy[x], sizeof(RGBTRIPLE), 1, outptr);
                }

            }
            //print padding
            for (int k = 0; k < padding2; k++){
                fputc(0x00, outptr);
            }
        }

        free(copy);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
