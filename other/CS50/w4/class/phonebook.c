#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");

    string name = get_string("name: ");
    string number = get_string("number: ");

    fprintf(file, "%s, %s\n", name, number);

    fclose(file);
}