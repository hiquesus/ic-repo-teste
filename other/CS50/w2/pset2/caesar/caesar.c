#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //validate argv / get key
    if (argc != 2) //must be 2
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string key = argv[1];
    int keylen = strlen(argv[1]);
    //make a loop that ends whenever it's the same size as the key
    for (int i = 0; i < keylen; i += 1)
    {
        // "!" for not a digit, making it not a valid key
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //convert argv to int
    int keyformula = atoi(key);
    //get plaintext
    string text = get_string("plaintext: ");
    //encipher
    int len = strlen(text);
    //print ciphertext
    printf("ciphertext: ");
    //loop that stops when the text is finished (i < len)
    for (int i = 0; i < len; i += 1)
    {
        //calculate the cipher's formula with uppercased letters
        if (isupper(text[i]))
        {
            printf("%c", (((text[i] - 65) + keyformula) % 26) + 65);
        }
        //calculate the cipher's formula with lowercased letters
        else if (islower(text[i]))
        {
            printf("%c", (((text[i] - 97) + keyformula) % 26) + 97);
        }
        //make things that are not letters stay the same
        else
        {
            printf("%c", text[i]);
        }
    }
    //put the $ below the ciphertext line
    printf("\n");
}