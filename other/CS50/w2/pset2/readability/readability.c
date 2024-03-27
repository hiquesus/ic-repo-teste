#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_senteces(string text);

int main(void)
{
    string text = get_string("Text: \n");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_senteces(text);
//useless    float L = (words / letters) * 100;
//useless    float S = (words / sentences) * 100;
//calculationg float
    float calc = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;
//rounding the index
    int index = round(calc);

    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//count the amount of letters, ignoring pontuation marks and spaces.

int count_letters(string text)
{
    int letters = 0;

    int len = strlen(text);

    for (int i = 0; i < len; i += 1)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
        else
        {
            letters += 0;
        }
    }
    return letters;
}

//figure out the amount of words (with spaces!)

int count_words(string text)
{
// it starts at 1 since there's no space after the last words, so the amount of words is the amount of spaces + 1
    int words = 1;

    int len = strlen(text);

    for (int i = 0; i < len; i += 1)
    {
//basically not considering a "paragraph space" as a word, for example:
//" Hello!" would be 1 word, but without this it would be 2 words (the first space + 1 ~~from line 66/67~~)
        if (isspace(text[i]) && i == 0)
        {
            words += 0;
        }
        else if (isspace(text[i]))
        {
            words += 1;
        }
    }
    return words;
}

//getting the amount of sentences (whenever there's a ".", a "!" or a "?" a new sentence starts)

int count_senteces(string text)
{
    int sentences = 0;

    int len = strlen(text);

    for (int i = 0; i < len; i += 1)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }
    }
    return sentences;
}