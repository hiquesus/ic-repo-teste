#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    people[0].name = "Cauã";
    people[0].number = "+55 (82) 99827-5231";

    people[1].name = "Pedro";
    people[1].number = "+55 (82) 99481-5209";

    string name = get_string("Name: ");
    for (int i = 0; i < 2; i += 1)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found - %s : %s\n", people[i].name, people[i].number);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}