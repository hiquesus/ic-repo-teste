#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree in selling your soul to me? \n");

    if (c == 'y' || c == 'Y')
    {
        printf("Thanks for your soul.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Why not???? Ok then, might as well steal it from you! :) .\n");
    }
}