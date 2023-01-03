#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//define variables
string plaintext;
int total;
int uccipher[26];
int lccipher[26];
string ucalphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string lcalphabet = "abcdefghijklmnopqrstuvwxyz";

//define functions
bool only_alpha(string s);
bool all_letters(void);
void applycipher();
int no_mult(string s);

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
    //create a lowercase cipher
    for (int i = 0; i < 26; i++)
    {
        lccipher[i] = tolower(argv[1][i]);
    }
    //create an uppercase cipher
    for (int i = 0; i < 26; i++)
    {
        uccipher[i] = toupper(argv[1][i]);
    }
    //Make sure key cointains all 26 letters
    if (all_letters() == 0 || no_mult(argv[1]) != 2847)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    //Get plaintext from the user
    plaintext = get_string("Plaintext: ");
    //print the phrase "ciphertext: " along with the completed algorithm and a line break
    printf("ciphertext: ");
    applycipher();
    printf("\n");
    //end the program
    return 0;
}

bool only_alpha(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        //check to see if all the argv[1] is only alphabetic characters
        if (isalpha(s[i]) == false)
        {
            return false;
            break;
        }
    }
    return true;
}

bool all_letters(void)
{
    //iterate through the cipher input and see if any letter is duplicated by giving each letter match a point. If there are 2 points, you know the letter is duplicated.
    for (int i = 0; i < 26; i++)
    {
        total = 0;
        for (int j = 0; j < 26; j++)
        {
            if (lccipher[i] == lccipher[j])
            {
                total++;
                if (total != 1)
                {
                    return false;
                    break;
                }
            }
        }
    }
    return true;
}

int no_mult(string s)
{
    //this was my original method for checking for duplicates, but the checker found a way to beat it >( . The code still works with it present and I'm afraid to take it out.
    //it works by adding up all the lowercase letters in the cipher and checking it against the total values of the alphabet A thru Z. Apparently there are ways around this.
    total = 0;
    for (int i = 0, sl = strlen(s); i < sl; i++)
    {
        total = tolower(s[i]) + total;
    }
    return total;
}

void applycipher()
{
    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
        //first, check to see if the plaintext is alphabetic
        if (isalpha(plaintext[i]))
        {
            //if the plaintext is alphabetic, check to see whether it's uppercase or not
            if (isupper(plaintext[i]))
            {
                for (int j = 0; j < 26; j++)
                {
                    //iterate through the cipher and assign the plaintext its ciphertext equivalent
                    if (plaintext[i] == ucalphabet[j])
                    {
                        printf("%c", uccipher[j]);
                        break;
                    }
                }
            }
            //follow the same process about for uppercase above, but for lowercase
            else if (islower(plaintext[i]))
            {
                for (int j = 0; j < 26; j++)
                {
                    if (plaintext[i] == lcalphabet[j])
                    {
                        printf("%c", lccipher[j]);
                        break;
                    }
                }
            }
        }
        //if the plaintext is NOT alphabetic, leave it alone and print it out as a character
        else
        {
            printf("%c", plaintext[i]);
        }
    }
}