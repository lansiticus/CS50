#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// string plaintext;
// int cipher;
// char rotate(string c, int n);
// bool only_digits (string s);

int main(void)
{
    string plaintext = get_string ("Type a phrase: ");
    int cipher = get_int ("Type a cipher: ");
    printf("Ciphertext: ");

    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
        if (isupper(plaintext[i]))
        {
        char conversion = plaintext[i] - 39 + cipher;
        char output = conversion % 26;
        printf("%c", output + 65);
        }
        else if (islower(plaintext[i]))
        {
        char conversion = plaintext[i] - 71 + cipher;
        char output = conversion % 26;
        printf("%c", output + 97);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}