#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size]

    long popstart;
    long endpop;
    long years = 0;
    do
    {
        popstart = get_long("Start Size: ");
    }
    while (popstart < 9);

    // TODO: Prompt for end size

    do
    {
        endpop = get_long("End Size: ");
    }
    while (endpop < popstart);

    // TODO: Calculate number of years until we reach threshold

    for (years = 0; popstart < endpop; years += 1)

    {
        popstart = popstart + (popstart / 3) - (popstart / 4);
    }

    // TODO: Print number of years

    {
        printf("Years: %ld\n", years);
    }

}
