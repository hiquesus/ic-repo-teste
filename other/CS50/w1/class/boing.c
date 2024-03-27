#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string resposta = get_string("qual teu nome?\n ");
    printf("boing %s boing\n", resposta);
}