#include <cs50.h>
#include <stdio.h>

//initialize functions
int firstsixteen(long);
int firsttwosixteen(long);
int firsttwofifteen(long);
int firstfourthirteen(long);

int main(void)
{
    //get card number
    long card_number = get_long("card_number: ");

    //initialize the sum of Luhn's Algorithm
    int sum = 0;

    //find the 2nd number from the end of each card, multiply it by two, separate the product into 2 digits and add them together
    long ten = card_number % 100 / 10 * 2;
    int add_ones = ten % 10;
    int add_tens = ten % 100 / 10;
    sum = sum + add_ones + add_tens;

    //do the same with every other card digit starting from the end of the card and add the sum returned from the previous digit
    long tho = card_number % 10000 / 1000 * 2;
    add_ones = tho % 10;
    add_tens = tho % 100 / 10;
    sum =  sum + add_ones + add_tens;

    long huntho = card_number % 1000000 / 100000 * 2;
    add_ones = huntho % 10;
    add_tens = huntho % 100 / 10;
    sum =  sum + add_ones + add_tens;

    long tenmil = card_number % 100000000 / 10000000 * 2;
    add_ones = tenmil % 10;
    add_tens = tenmil % 100 / 10;
    sum =  sum + add_ones + add_tens;

    long bil = card_number % 10000000000 / 1000000000 * 2;
    add_ones = bil % 10;
    add_tens = bil % 100 / 10;
    sum =  sum + add_ones + add_tens;

    long hunbil = card_number % 1000000000000 / 100000000000 * 2;
    add_ones = hunbil % 10;
    add_tens = hunbil % 100 / 10;
    sum =  sum + add_ones + add_tens;

    long tentril = card_number % 100000000000000 / 10000000000000 * 2;
    add_ones = tentril % 10;
    add_tens = tentril % 100 / 10;
    sum =  sum + add_ones + add_tens;

    long quad = card_number % 10000000000000000 / 1000000000000000 * 2;
    add_ones = quad % 10;
    add_tens = quad % 100 / 10;
    sum =  sum + add_ones + add_tens;

    //get every other digit starting from the last digit of the card
    long one = card_number % 10 / 1;
    long hun = card_number % 1000 / 100;
    long tentho = card_number % 100000 / 10000;
    long mil = card_number % 10000000 / 1000000;
    long hunmil = card_number % 1000000000 / 100000000;
    long tenbil = card_number % 100000000000 / 10000000000;
    long tril = card_number % 10000000000000 / 1000000000000;
    long huntril = card_number % 1000000000000000 / 100000000000000;

    //add these all these digits to the sum from above
    sum = sum + one + hun + tentho + mil + hunmil + tenbil + tril + huntril;

    //if the Luhn's algorithm from above is not divisible by 10, return the card as invalid and end the program
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //determine which card it is by using functions to ID the first few digits of each card
    if (firstsixteen(card_number) == 4 || firstfourthirteen(card_number) == 0004)
    {
        printf("VISA\n");
    }
    else if (firsttwosixteen(card_number) == 51 || firsttwosixteen(card_number) == 52 || firsttwosixteen(card_number) == 53
             || firsttwosixteen(card_number) == 54 || firsttwosixteen(card_number) == 55)
    {
        printf("MASTERCARD\n");
    }
    else if (firsttwofifteen(card_number) == 34 || firsttwofifteen(card_number) == 37)
    {
        printf("AMEX\n");
    }
    //if none of these cards are valid, print INVALID and end the program
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

//define functions to get the first few digits of the card number

//this one is for VISA
int firstsixteen(long card_number)
{
    return card_number % 10000000000000000 / 1000000000000000;
}

//This one is for MASTERCARD
int firsttwosixteen(long card_number)
{
    return card_number % 10000000000000000 / 100000000000000;
}

//This one is for AMEX
int firsttwofifteen(long card_number)
{
    return card_number % 1000000000000000 / 10000000000000;
}

//This one is for VISA as well
int firstfourthirteen(long card_number)
{
    return card_number % 10000000000000000 / 1000000000000;
}