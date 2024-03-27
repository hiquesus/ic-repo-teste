#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float amount = get_float ("R$ amount: ");
    int cents = round (amount * 100);
    printf ("Cents: %i\n", cents);
}