  
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height + i + 2; j++)
        {
            if (j != height && j != height + 1 && j >= height - i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
