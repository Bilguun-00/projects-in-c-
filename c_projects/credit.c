#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_n = get_long("type your card number here: ");
    int i = 0;
    long number = card_n;
    while (number > 0)
    {
        number = number / 10;
        i++;
    }
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    int sum1 =0;
    int sum2 = 0;
    long x = number;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;
    do
    {
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;
        mod2 = x % 10;
        x = x / 10;
        mod2 = mod2 * 2;
        d1 = mod1 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);
    total = sum1 + sum2;
    if (total % 10 != 0)
    {
        printf("INVALID");
        return 0;
    }
    long start = card_n;
    do
    {
        start = start / 10;
    }
    while (start > 100);
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
