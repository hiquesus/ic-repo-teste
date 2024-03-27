#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    // n = strlen(s) pra o código ler o tamanho do texto somente uma vez, não toda vez (como seria se fosse "int i=0; i < strlen(s);...")
    for (int i = 0, n = strlen(s); i < n; i += 1)
    // if (islower(s[i])); // ou if (s[i] >= 'a' && s[i] <= 'z')
    {
        printf("%c", toupper (s[i])); // or printf("%c", s[i] - 32);
    }
    // else
    // {
    //     printf("%c", s[i]);
    // }
    printf("\n");
}