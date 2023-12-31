#include <cs50.h>
#include <stdio.h>

int height = 0;

int main(void)
{
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    int counter = 1;

    while (counter <= height)
    {
        int space = height - counter;

        for (int i = 0; i < space; i++)
        {
            printf(" ");
        }
        for (int j = 0; j < counter; j++)
        {
            printf("#");
        }
        printf("\n");
        counter++;
    }
}
