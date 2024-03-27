#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);
int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse [input file] [output file]\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2

    char *infile = argv[1];

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not read %s\n", infile);
        return 1;
    }

    // Read header into an array
    // TODO #3

    const int headersize = sizeof(WAVHEADER);
    WAVHEADER header;
    fread(&header, headersize, 1, inptr);

    // Use check_format to ensure WAV format
    // TODO #4

    if (check_format(header) == 1)
    {
        printf("Input should be a .wav file\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5

    char *outfile = argv[2];

    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        printf("Could not create %s\n", outfile);
        return 1;
        fclose(inptr);
    }

    // Write header to file
    // TODO #6

    fwrite(&header, headersize, 1, outptr);

    // Use get_block_size to calculate size of block
    // TODO #7
    int blocksize = header.numChannels * (header.bitsPerSample * 0.125);
    //int blocksize = get_block_size(header);

    // Write reversed audio to file
    // TODO #8

//    uint16_t buffer;
    BYTE array[blocksize];
    fseek(inptr, 0, SEEK_END);
    fseek(outptr, sizeof(WAVHEADER), SEEK_SET);
    while (ftell(inptr) > sizeof(WAVHEADER))
    {
        fseek(inptr, -(blocksize * 2), SEEK_CUR);
        fread(&array, sizeof(blocksize), 1, inptr);
        fwrite(&array, sizeof(blocksize), 1, outptr);
//        fseek(inptr, -2, SEEK_CUR);
    }

    fclose(inptr);
    fclose(outptr);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//int get_block_size(WAVHEADER header)
//{
    // TODO #7
    //int blocksize = header.numChannels * (header.bitsPerSample * 0.125);
    //return blocksize;
//}