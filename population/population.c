#include <cs50.h>
#include <stdio.h>

int size = 0;
int population = 0;
int years = 0;

int main(void)
{
    // TODO: Prompt for start size
    do
    {
        population = get_int("Start size: ");
    }
    while (population < 9);

    // TODO: Prompt for end size
    do
    {
        size = get_int("End size: ");
    }
    while (size < population);

    // TODO: Calculate number of years until we reach threshold
    while (population < size)
    {
        population += (population / 3) - (population / 4);
        years++;
        if (population >= size)
        {
            break;
        }
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
