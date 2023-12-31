#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int checkPhrase(string text);
int checkWords(string text);
int checkLetters(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letter = (checkLetters(text));
    int words = (checkWords(text));
    int phrase = (checkPhrase(text));

    float L = (((float) letter / (float) words) * 100); // L = número médio de letras por 100 palavras
    float S = (((float) phrase / (float) words) * 100); // S = número médio de sentenças por 100 palavras.

    int index = lround(0.0588 * L - 0.296 * S - 15.8);
    if (index > 16)
    {
        printf("Above Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// verifica as frases por pontos "." "?" "!"
int checkPhrase(string text)
{
    int phrase = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            phrase++;
        }
    }
    return phrase;
}

// verificar as letras excluindo espaco
int checkLetters(string text)
{
    int letter = 0;
    for (int h = 0, n = strlen(text); h < n; h++)
    {
        if (isalpha(text[h]))
        {
            letter++;
        }
    }
    return letter;
}

// verifica as palavras delimitando pelo espaco
// numero de espacos + 1 igual o numero de palavras
int checkWords(string text)
{
    int words = 0;
    for (int j = 0, n = strlen(text); j < n; j++)
    {
        if (text[j] == ' ')
        {
            words++;
        }
    }
    return words + 1;
}
