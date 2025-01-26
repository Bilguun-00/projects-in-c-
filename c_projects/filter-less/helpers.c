#include "helpers.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;
            int avr = round((blue + green + red)/3);
            image[i][j].rgbtBlue = avr;
            image[i][j].rgbtGreen = avr;
            image[i][j].rgbtRed = avr;
        }

    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j=0; j < width; j++)
        {
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;
            int sepiared = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepiagreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            int sepiablue = round(0.272 * red + 0.534 * green + 0.131 * blue);
            if (sepiared > 255)
            {
                sepiared = 255;
            }
             if (sepiablue > 255)
            {
                sepiablue = 255;
            }
             if (sepiagreen > 255)
            {
                sepiagreen = 255;
            }
            image[i][j].rgbtRed = sepiared;
            image[i][j].rgbtBlue = sepiablue;
            image[i][j].rgbtGreen = sepiagreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j=0; j < width / 2; j++)
        {
             RGBTRIPLE temp = image[i][j];
             image[i][j] = image[i][width - (j + 1)];
             image[i][width - (j + 1)] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalred, totalblue, totalgreen;
            totalred = totalblue = totalgreen = 0;
            float counter = 0;
            for(int x = -1; x < 2; x++)
            {
                for(int y = -1; y < 2; y++)
                {
                    int currentx = i +x;
                    int currenty = j+y;
                    if(currentx < 0 || currentx > (height -1) ||
                    currenty < 0 || currenty > (width - 1))
                    {
                        continue;
                    }
                    totalred += image[currentx][currenty].rgbtRed;
                    totalblue += image[currentx][currenty].rgbtBlue;
                    totalgreen += image[currentx][currenty].rgbyes
                    tGreen;
                    counter++;
                    temp[i][j].rgbtRed = round(totalred / counter);
                    temp[i][j].rgbtGreen = round(totalgreen / counter);
                    temp[i][j].rgbtBlue = round(totalblue / counter);
                }
            }
        }
     }
     for (int i =0; i < height; i++)
     {
        for(int j=0; j< width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
     }
    return;
}
