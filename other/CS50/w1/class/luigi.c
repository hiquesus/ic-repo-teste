#include <stdio.h>
#include <cs50.h>

int main(void)
{
            printf("\n");

    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);

    for (int i = 0; i < n; i += 1)
    {
        for (int j = 0; j < n; j += 1)
        {
            printf("#");
        }
        printf ("\n");
    }
}