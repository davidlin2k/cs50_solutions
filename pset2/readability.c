#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_sentences(string text);
int count_words(string text);
void readability_level(string text);

int main(void)
{
    string str = get_string("Text: ");
    readability_level(str);
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    
    return count;
}

int count_words(string text)
{
    int count = 0;
    
    if (text[0] != '\0')
    {
        count++;
    }
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    
    return count;
}

void readability_level(string text)
{
    int words = count_words(text);
    int sentences = count_sentences(text);
    int letters = count_letters(text);
    
    float L = 100.0 * letters / words;
    float S = 100.0 * sentences / words;
    
    float index = 0.0588 * L - 0.296 * S - 15.8;
    
    int level = (int)(index < 0 ? (index - 0.5) : (index + 0.5));
    
    if (level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", level);
    }
}
