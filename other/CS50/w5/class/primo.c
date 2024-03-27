#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int n;
int check = 0;

int main(void)
{
    n = get_int("número: ");
    if (n >= 1)
    {
        check = 1;
    }
    for (int i = 2; i <= n / 2; i += 1)
    {
        if (n % i == 0)
        {
            check += 1;
        }
    }
    if (check == 1)
    {
        printf("%i é um número primo!", n);
    }
    else
    {
        printf("%i não é um número primo!", n);
    }
    printf("\n");
    return 0;
}