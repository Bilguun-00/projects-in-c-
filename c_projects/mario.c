#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int n, i, j, s;
    do
    {
        n = get_int("hight: ");
    }
    while(n < 1 || n > 8);
    for (i = 0; i < n; i++)
    {
        for (s = 0; s < n - i - 1; s++)
    {
        printf(" ");
    }
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for(j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}
