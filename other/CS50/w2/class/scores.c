#include <cs50.h>
#include <stdio.h>

const int n = 3;

float average(int length, int array[]);

int main(void)
{
    int scores[n];
    for (int i = 0; i < n; i += 1)
    {
        int boing = i + 1;
        scores[i] = get_int("Score %i: \n", boing);
    }
    printf("Average: %f\n", average(n, scores));
}

float average(int length, int array[])
{
    int sum = 0;
    for(int i = 0; i < length; i += 1)
    {
        sum = sum + array[i]; // (could be "sum += array[i];" too)
    }
    return sum / (float) length;
}