#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x = get_long("Which number would you like to use?\n");

    if (x % 2 == 0)
    {
        printf("The Number %li is EVEN!\n", x);
    }
    else
    {
        printf("The Number %li is ODD!\n", x);
    }
}