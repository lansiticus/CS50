#include <cs50.h>
#include <stdio.h>

int main(void)
{
//make height variable
    int height;

//exclude negative numbers and numbers higher than 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

//make algorithm for the pyramid
    for (int i = 0; i < height; i++)
    {
// Declare variables for steps and spaces. You have to start with one block at the top, not 0, so I added plus one to the width
        int width = i + 1;
        int spaces = height - width;

//make for loops the spaces and steps. Spaces have to come first
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < width; k++)
        {
            printf("#");
        }

//move the "typewriter head"
        printf("\n");
    }
}