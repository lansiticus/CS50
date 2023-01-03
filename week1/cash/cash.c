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
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    //define the variable "cents" so you can perform a do-while loop on it
    int cents;
    //make a do-while loop such that the amount of change rejects negative values
    do
    {
        cents = get_int("How much change? ");
    }
    while (cents < 0);
    //return the number of cents
    return cents;

}

int calculate_quarters(int cents)
{
    //create a variable for quarters so you can use it
    int quarters;
    //determine how many quarters to return so it can be added up
    return quarters = cents / 25;
    //determine how many cents to pass on to the next calculation
    cents = cents % 25;
}

int calculate_dimes(int cents)
{
    //copy and paste what you did for quarters
    int dimes;
    return dimes = cents / 10;
    cents = cents % 10;
}

int calculate_nickels(int cents)
{
    //copy and paste what you did for quarters
    int nickels;
    return nickels = cents / 5;
    cents = cents % 5;
}

int calculate_pennies(int cents)
{
    //copy and paste what you did for quarters, but you don't need to pass on any more values
    int pennies;
    return pennies = cents / 1;
}
