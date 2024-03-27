#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int MINE = 5;
    long x = get_long("How many points did you get?\n ");

    if (x < MINE)
    {
        printf("You got %li points! Less than me though.\n", x);
    }
    else if (x > MINE)
    {
        printf("You got %li points! Congrats! You beat me!\n", x);
    }
    else
    {
        printf("You got %li points! Guess we are the same!\n", x);
    }
}