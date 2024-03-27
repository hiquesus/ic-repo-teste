#include <cs50.h>
#include <stdio.h>

int main(void)

// ASKING FOR HEIGHT LOOP
{
    printf("\n");

    int hei, row, col, spa;
    do
    {
        hei = get_int("Height: ");
    }
    while (hei < 1 || hei > 8);
//lil space
    printf("\n");
//MARIO
//left stairs
    for (row = 0; row < hei; row += 1)
    {
        for (spa = 0; spa < hei - row - 1; spa += 1)
        {
            printf(" ");
        }
        for (col = 0; col <= row; col += 1)
        {
            printf("#");
        }
// two spaces between stairs
        printf("  ");
// right stairs
        for (col = 0; col <= row; col += 1)
        {
            printf("#");
        }

        printf("\n");
    }
}