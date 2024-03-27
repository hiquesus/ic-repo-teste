#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //checking if everything is okay with the user input
    if (argc != 2)
    {
        printf("Usage: ./recover (image)\n");
        return 1;
    }
    //checking if the input is valid
    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("Could not open the file\n");
        return 1;
    }

    int imgcount = 0;
    FILE *output = NULL;
    unsigned char buffer[512];
    char *filename = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(char), 512, input))
    {
        //checks if it's a jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //checks if there was already another formed image, and if there is, it's closed so we can open the new one
            if (imgcount > 0)
            {
                fclose(output);
            }
            //writes the jpg and names it
            sprintf(filename, "%03i.jpg", imgcount);
            output = fopen(filename, "w");
            //add 1 to the image counter so we can name the 50 images correctly
            imgcount += 1;
        }
        if (output != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output);
        }
    }
    free(filename);
    fclose(output);
    fclose(input);
}