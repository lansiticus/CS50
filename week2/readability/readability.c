#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//declare functions and variables
int count_letters(string text);
int totalLetters;
int count_words(string text);
int totalWords;
int count_sentences(string text);
int totalSentences;

//everything has to be a float in the equation or it doesn't work properly
float N = 100;

int main(void)
{
    //request a text to check grade level
    string text = get_string("Text: ");

    //run functions on text
    count_letters(text);
    count_words(text);
    count_sentences(text);

    //reassign results to floats so they can be used in the formula
    float fLetters = totalLetters;
    //you have to cheat on this one and add one, because the last word doesn't have any whitespace after it.
    float fWords = totalWords + 1;
    float fSentences = totalSentences;

    //letters per word
    float valueL = fLetters / fWords * N;

    //words per sentence
    float valueS = fSentences / fWords * N;

    //Coleman-Liau Grade Formula
    float index = 0.0588 * valueL - 0.296 * valueS - 15.8;

    //print the appropriate results
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
        printf("Grade %d\n", (int) round(index));
    }

}

int count_letters(string text)
{
    totalLetters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            totalLetters++;
        }
    }
    return totalLetters;
}

//this one counts white space, but the last word has a period at the end so you have to add one. See above.
int count_words(string text)
{
    totalWords = 0;
    for (int i = 0, len = strlen(text); i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            totalWords++;
        }
    }
    return totalWords;
}

int count_sentences(string text)
{
    totalSentences = 0;
    for (int i = 0, len = strlen(text); i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            totalSentences++;
        }
    }
    return totalSentences;
}