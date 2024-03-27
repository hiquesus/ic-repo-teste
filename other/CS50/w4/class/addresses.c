#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char *s = "HELLO!";

    for(int i = 0; i < strlen(s); i += 1)
    {
        printf("%c\n", *(s + i));
    }
    printf("\n");
}