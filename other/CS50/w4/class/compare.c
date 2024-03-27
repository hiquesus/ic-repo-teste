#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

//you could do that instead of using strcmp but it's kinda pointless since you can just use strcmp

    //int test = 0;
    //for(int i = 0; i < strlen(s); i += 1)
    //{
    //    if (*(s+i) == *(t+i))
    //    {
    //        test += 1;
    //    }
    //}
    //if (test == strlen(s))

    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}