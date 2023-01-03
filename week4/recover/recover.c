#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;
int BLOCK_SIZE = 512;
bool firstjpeg = true;

int main(int argc, char *argv[])
{
    //check for correct command line input
    if (argc != 2)
    {
        printf("Usage: recover IMAGE\n");
        return 1;
    }

    //open memory card file
    FILE *file = fopen(argv[1], "r");

    //if the file can't be read, return an error message
    if (file == NULL)
    {
        printf("Error: File cannot be opened for reading/n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    char filename[8];
    int imageNumber = 0;
    FILE *img;

    //Repeat until end of card: Read 512 bytes into a buffer using fread(data, size, number, inptr)
    while (fread(buffer, 1, BLOCK_SIZE, /*raw_file*/ file) == BLOCK_SIZE)
    {
        //Look for JPEGS: First 3 bytes 0xFF Oxd8 0xff and Last byte 0xe0-f.
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if first jpeg, open a new JPEG file and start writing Filenames: ###.jpg starting at 000.jpg
            if (firstjpeg == true)
            {
                sprintf(filename, "%03i.jpg", imageNumber);
                img = fopen(filename, "w");
                //write the first block of data
                fwrite(buffer, 1, BLOCK_SIZE, img);
                //increment the number of images by 1
                imageNumber++;
                //change firstjpeg to false, so you can keep writing
                firstjpeg = false;
            }
            else
                //same steps as before, but close the old file, so you can start writing a new one
            {
                //close the image file
                fclose(img);
                sprintf(filename, "%03i.jpg", imageNumber);
                img = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, img);
                imageNumber++;
            }
        }
        //if you've found the first jpeg, just keep writing because the images are contiguous
        else if (firstjpeg == false)
        {
            //Write data in 512 byte chunks until a new jpeg file is found
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }
//close any remaining files
    fclose(img);
    fclose(file);
    return 0;
}
