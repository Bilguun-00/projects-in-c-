#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
     if (argc != 2)
     {
        printf("usage: ./caeser key\n");
        return 1;
     }

     for(int i = 0, ln = strlen(argv[1]); i < ln; i++)
     {
        if (!isdigit(argv[1][i]))
        {
            printf("usage: ./caeser key\n");
            return 1;
        }
     }
     int key = atoi(argv[1]);
     string p_text = get_string("type here: ");
     printf("ciphertext: ");
     for (int text = 0, len = strlen(p_text); text < len; text++)
     {
        if (isupper(p_text[text]))
        {
            printf("%c", (p_text[text] - 65 + key) % 26 + 65);
        }
        else if (islower(p_text[text]))
        {
            printf("%c", (p_text[text] - 97 + key) % 26 + 97);
        }
        else
        {
            printf("%c", p_text[text]);
        }
     }
     printf("\n");
}

