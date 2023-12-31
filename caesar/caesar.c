#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cypher(char character, int key);

int main(int argc, string argv[])
{
    // Se o argc for diferente de [2] ou argv diferente de [0] imprima Usage: ./caesar key
    if (argc != 2 || !isdigit(argv[1][0]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string message = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(message); i < n; i++)
    {
        cypher(message[i], key);
    }
    printf("\n");

    return 0;
}

void cypher(char character, int key)
{
    // use +key para chegar ao caractere correto, lembre-se de limitar de 'A' a 'Z' e 'a' a 'z'.
    if (isalpha(character))
    {
        char base = isupper(character) ? 'A' : 'a';
        printf("%c", (character - base + key) % 26 + base);
    }
    else
    {
        printf("%c", character);
    }
}
