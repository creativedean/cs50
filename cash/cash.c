#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents -= quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents -= dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents -= nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cash;
    do
    {
        cash = get_int("Change owed: ");
    }
    while (cash <= 0);

    return cash;
}

// Calculate the number of quarters to give the customer
int calculate_quarters(int cents)
{
    int quartersCount = 0;
    while (cents > 25 || cents == 25)
    {
        cents = cents - 25;
        quartersCount++;
    }
    return quartersCount;
}

// Calculate the number of dimes to give the customer
int calculate_dimes(int cents)
{
    // Calculate dimes first
    int dimesCount = 0;
    while (cents > 10 || cents == 10)
    {
        cents = cents - 10;
        dimesCount++;
    }
    return dimesCount;
}

// Calculate the number of nickels to give the customer
int calculate_nickels(int cents)
{
    // Calculate nickels after considering quarters and dimes
    int nickelsCount = 0;
    while (cents > 5 || cents == 5)
    {
        cents = cents - 5;
        nickelsCount++;
    }
    return nickelsCount;
}

// Calculate the number of pennies to give the customer
int calculate_pennies(int cents)
{
    int penniesCount = 0;
    while (cents > 1 || cents == 1)
    {
        cents = cents - 1;
        penniesCount++;
    }
    return penniesCount;
}
