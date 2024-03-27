#include <cs50.h>
#include <stdio.h>

//poe o nome no ./make (nome); caso não tenha nome ou seja + que um, vai no hello world

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}