#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = get_string("What's your name? \n");
    int n = strlen(name);
    printf("''%s'' has %i characters\n", name, n);
}