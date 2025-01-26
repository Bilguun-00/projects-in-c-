#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string letter);
int count_words(string word);
int count_sentences(string sentence);
int main(void)
{
    string text = get_string("texxt: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = letters / (float) words * 100;
    float S = sentences / (float) words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
int count_letters(string letter)
{
    int letters = 0;
    for (int i = 0; i < strlen(letter); i++)
        if (isalpha(letter[i]))
        {
            letters++;
        }
    return letters;
}
int count_words(string word)
{
    int space = 1;
    for (int j = 0; j < strlen(word); j++)
        if (word[j] == ' ')
        {
            space++;
        }
    return space;
}
int count_sentences(string sentence)
{
    int sentences = 0;
    for (int m = 0; m < strlen(sentence); m++)
        if (sentence[m] == '.' || sentence[m] == '?' || sentence[m] == '!')
        {
            sentences++;
        }
    return sentences;
}
