#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 7;
void print_bulb(int bit);
void convertAsciiToBin(int ascii);

int main(void)
{
    // Receives the input and iterate each character in the string
    string message = get_string("Message: ");

    for (int i = 0, n = strlen(message); i < n; i++)
    {
        convertAsciiToBin(message[i]);
        printf("\n");
    }
}

void convertAsciiToBin(int ascii)
{
    // Convert ASCII to Binary using Bitwise
    int bitValue;
    for (int i = BITS_IN_BYTE; i >= 0; i--)
    {
        bitValue = (ascii >> i) & 1;
        print_bulb(bitValue);
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
