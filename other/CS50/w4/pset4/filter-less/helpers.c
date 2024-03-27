#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {
            //float for each value of colour
            float r = image[i][j].rgbtRed;
            float g = image[i][j].rgbtBlue;
            float b = image[i][j].rgbtGreen;

            //rounds the average of the values
            int roundavrg = round((r + g + b) / 3.0);

            //implements the rounded average of the values of each colour into said colours, as their values are now the same, they'll be in a grey scale
            image[i][j].rgbtRed = roundavrg;
            image[i][j].rgbtBlue = roundavrg;
            image[i][j].rgbtGreen = roundavrg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {
            //float for each value
            float r = image[i][j].rgbtRed;
            float g = image[i][j].rgbtGreen;
            float b = image[i][j].rgbtBlue;

            //calculates the sepia formula for each value
            int sepiaRed = round((0.393 * r) + (0.769 * g) + (0.189 * b));
            int sepiaGreen = round((0.349 * r) + (0.686 * g) + (0.168 * b));
            int sepiaBlue = round((0.272 * r) + (0.534 * g) + (0.131 * b));

            //checks if the sepia value is larger than 255 (the limit), if it's higher than 255, then it'll be matched to 255
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
            //updates the values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int i = 0; i < height; i += 1)
    {
        for (int j = 0; j < width / 2; j += 1)
        {
            //swapping values of pixels and having a temporary thingy
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //temp thing for us to copy the image
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {
            //intigers of the total sum of each colour of the pixel + it's neighbours
            int red = 0;
            int green = 0;
            int blue = 0;
            float neighbours = 0.00;

            for (int x = -1; x < 2; x += 1)
            {
                for (int y = -1; y < 2; y += 1)
                {
                    int newX = i + x;
                    int newY = j + y;
                    //checks if there are neighbours on every corner of the pixel, if there isn't it'll run the loop again
                    //, not adding to the number of neighbours so we can divide correctly at the end
                    if (newX < 0 || newX > (height - 1) || newY < 0 || newY > (width - 1))
                    {
                        continue;
                    }

                    red = red + image[newX][newY].rgbtRed;
                    green = green + image[newX][newY].rgbtGreen;
                    blue = blue + image[newX][newY].rgbtBlue;

                    neighbours += 1;
                }

                //here we turn the temp image's pixels into the new, rounded and averaged pixels
                temp[i][j].rgbtRed = round(red / neighbours);
                temp[i][j].rgbtGreen = round(green / neighbours);
                temp[i][j].rgbtBlue = round(blue / neighbours);
            }
        }
    }
    for (int i = 0; i < height; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {
            //and here finally we make the image the same as the temp one, which is the changed one
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
