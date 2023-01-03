#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate over the image columns 1 row at a time
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //create a RGBTRIPLE variable for each RGB pixel
            RGBTRIPLE rgb = image[i][j];
            //make a variable that holds the greyscale value after you average everything together
            float grey = ((rgb.rgbtRed + rgb.rgbtGreen + rgb.rgbtBlue) / 3.0);
            //assign the rounded grey scale to each RGB value in the actual image
            image[i][j].rgbtRed = round(grey);
            image[i][j].rgbtGreen = round(grey);
            image[i][j].rgbtBlue = round(grey);
        }
    }
    return;
}

// Convert image to sepiacheck50
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate over the image columns 1 row at a time
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //create a RGBTRIPLE variable for each RGB pixel
            RGBTRIPLE rgb = image[i][j];
            //make variables that hold the sepia value for each color after you apply the algorithm
            float sepiaRed = .393 * rgb.rgbtRed + .769 * rgb.rgbtGreen + .189 * rgb.rgbtBlue;
            float sepiaGreen = .349 * rgb.rgbtRed + .686 * rgb.rgbtGreen + .168 * rgb.rgbtBlue;
            float sepiaBlue = .272 * rgb.rgbtRed + .534 * rgb.rgbtGreen + .131 * rgb.rgbtBlue;
            //make sure nothing is higher than 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            //assign the rounded sepia tones to each RGB value in the actual image
            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterate one row at a time over each column
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //store the front pixel
            RGBTRIPLE rgbfront = image[i][j];
            //move the back pixel to the front
            image[i][j] = image[i][width - j - 1];
            //take the stored front pixel and move it to the back
            image[i][width - j - 1] = rgbfront;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // //make a temporary "holding area" for the image you make so you don't change the values of the surrounding pixels
    // RGBTRIPLE tempimage[x][y];

    // //Iterate one row at a time over each column to make the temporary image
    //     for(int i = 0; i < height; i++)
    // {
    //     for(int j = 0; j < width; j++)
    //     {
    //         image[i][j] = tempimage[i][j];
    //     }
    // }
    //     for(int k = -1; k < 2; k++)
    //     {
    //         for(int l = -1; l < 2; l++)
    //     }
    //         if (image[i] = 0 && image[j] = 0)
    //         {
    //                 tempimage[i][j] = (image[i - 1][j - 1] + image[i - 1][j - 1] +
    //                                    image[i - 1][j - 1] + image[i - 1][j - 1])/4
    //         }
    //         else if (image[i] = 0 && image[j] != 0 image[j] != width - 1)
    //         {
    //             tempimage[i][j] = (image[i - 1][j - 1] + image[i - 1][j - 1] + image[i - 1][j - 1] +
    //         //take the stored front pixel and move it to the back
    //         image[i][width - j - 1] = rgbfront;
    //     }
    // }
    return;
}
