#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//define variables and functions
string plaintext;
int cipher;
bool only_digits(string s);
void rotate(string s, int n);

int main(int argc, string argv[])
{
// Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Please run in the following format ./caesar [number]\n");
        return 1;
    }
    // Make sure every character in argv[1] is a digit
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Get plaintext from the user
    plaintext = get_string("Plaintext: ");
    // Convert argv[1] from a `string` to an `int`
    cipher = atoi(argv[1]);

    //print the phrase "ciphertext: " along with the completed algorithm and a line break
    printf("ciphertext: ");
    rotate(plaintext, cipher);
    printf("\n");

    //end the program
    return 0;
}

bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        //check to see if all the argv[1] is digits
        if (isdigit(s[i]) == false)
        {
            return false;
            break;
        }
    }
    return true;
}

void rotate(string s, int n)
{
    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
        //find out if it's upper or lowercase
        if (isupper(plaintext[i]))
        {
            //apply the algorithm
            char conversion = plaintext[i] - 39 + cipher;
            char output = conversion % 26;
            //you have to add 65 to uppercase letters
            printf("%c", output + 65);
        }
        else if (islower(plaintext[i]))
        {
            char conversion = plaintext[i] - 71 + cipher;
            char output = conversion % 26;
            //you have to add 97 to lowercase letters
            printf("%c", output + 97);
        }
        else
        {
            //don't do anything to stuff that isn't in the alphabet
            printf("%c", plaintext[i]);
        }
    }
}