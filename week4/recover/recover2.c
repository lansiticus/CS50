//This is David Emily's solution to recover
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCKSIZE 512

//you shouldn't repeat yourself in code, so he made a function
int inputError()
{
    printf ("Usage: ./recover image\n");
    return 1;
}

//in case you need to use this again it's good to make a function
int fileError(char filename[])
{
    printf("Unable to open file: %s\n", filename);
    return 1;
}

//in order not to iterate over the same conditions over and over, he made a funciton
bool isJpgHeader(uint8_t buffer[])
{
    return  buffer[0] == 0xff
            && buffer[1] == 0xd8
            && buffer[2] == 0xff
            && (buffer[3] & 0xf0) == 0xe0;
}

// typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check that there is one input
    if(argc != 2)
    {
        return inputError();
    }

    //assign argv to a pointer
    char* inputFile = argv[1];

    //check that the file can be read
    if(inputFile == NULL)
    {
        return inputError();
    }

    //open memory card
    FILE* inputPtr = fopen(inputFile, "r");

    if(inputPtr == NULL)
    {
        return fileError(inputFile);
    }

    //create an output filename
    char filename[8]; //xxx.jpeg'\0' is 8 characters long + the null character
    FILE* outputPtr = NULL;
    uint8_t buffer[BLOCKSIZE];
    int jpgCounter = 0;

    //repeat until end of card:
        //read 512 bytes into a buffer
    while(fread(buffer, sizeof(uint8_t), BLOCKSIZE, inputPtr) || feof(inputPtr)==0)
    {
        if(isJpgHeader(buffer))
        {
            if(outputPtr != NULL)
            {
                fclose(outputPtr);
            }
            sprintf(filename, "%03i.jpg", jpgCounter);
            outputPtr = fopen(filename, "w");
            jpgCounter++;
        }
        if(outputPtr != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, outputPtr);
        }
    }
        //if start of new jpeg
            //if first jpeg
                //write new jpeg
            //else
                //close current file
                //open new file
        //else
            //if already found jpeg
                //keep writing to jpeg
    //end of memory card

    //close all open files
    if(inputPtr == NULL)
    {
        fclose(inputPtr);
    }
    if(outputPtr == NULL)
    {
    fclose(outputPtr);
    }
    return 0;
}
