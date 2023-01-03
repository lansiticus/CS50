#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//define variables and functions
int total;
string plaintext;
int uccipher[26];
int lccipher[26];
string ucalphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string lcalphabet = "abcdefghijklmnopqrstuvwxyz";

bool only_alpha(string s);
int all_letters(string s);
void applycipher();
// SMALL DIFFS!!!!! RUN IT IN A "SANDBOX" FILE THEN BRING IT IN.

//make the key all caps
//when checking to see if the answer is uppercase or lowercase, change the key to all caps or all lc

//do 2 arrays each with 26 letters and set plainalpha[i] = cipheralpha[i]

//plaintext, ciphertext

int main(int argc, string argv[])
{
// Make sure program has 2 command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Make sure every character in argv[1] is alphabetic
    if (only_alpha(argv[1]) == false)
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    //Make sure key cointains 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //Make sure key cointains all 26 letters
    if (all_letters(argv[1]) != 2847)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    //Get plaintext from the user
    plaintext = get_string("Plaintext: ");

    //print the phrase "ciphertext: " along with the completed algorithm and a line break
    printf("ciphertext: ");
    printf("\n");

    //end the program
    return 0;
}

bool only_alpha(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        //check to see if all the argv[1] is digits
        if (isalpha(s[i]) == false)
        {
            return false;
            break;
        }
    }
    return true;
}

int all_letters(string s)
{
    total = 0;
    for (int i = 0, sl = strlen(s); i < sl; i++)
    {
        total = tolower(s[i]) + total;
    }
    return total;
}