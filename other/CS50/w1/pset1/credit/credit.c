//libraries

#include <cs50.h>
#include <stdio.h>

//notes

// AMEX -> 15 digits + starts w/ 34/37
// VISA -> 13 or 16 digits + starts w/ 4
// MASTERCARD -> 16 digits + starts w/ 51/52/53/54/55

long card;

//card number question

int main(void)
{
    do
    {
        card = get_long("Card: ");
    }
    while (card <= 0);

//getting sum (luhn algorithm)

//1digit

    long count = 0;
    long divisor = 10;
    int sum = 0;
    long workingcard = card;

    while (workingcard > 0)
    {
        int lastdigit = workingcard % 10;
        sum = sum + lastdigit;
        workingcard = workingcard / 100;
    }

//2digitnumbers

    workingcard = card / 10;
    while (workingcard > 0)
    {
        int lastdigit = workingcard % 10;
        int x2 = lastdigit * 2;
        sum = sum + (x2 % 10) + (x2 / 10);
        workingcard = workingcard / 100;
    }

    workingcard = card;

    while (workingcard != 0)
    {
        workingcard = workingcard / 10;
        count ++;
    }

    for (int i = 0; i < count - 2; i ++)
    {
        divisor = divisor * 10;
    }

    int firstd = card / divisor;
    int first2d = card / (divisor / 10);

//sum checking
//card type
    if (sum % 10 == 0)
    {
        if ((first2d == 34 || first2d == 37) && count == 15)
        {
            printf("AMEX\n");
        }
        else if (firstd == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        else if ((first2d >= 51 && first2d <= 55) && count == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}