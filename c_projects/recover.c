#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file\n");
        return 2;
    }

    unsigned char buffer[512];
    int image_counter = 0;
    FILE *output = NULL;
    char *file = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(char), 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (output != NULL)
            {
                fclose(output);
            }

            sprintf(file, "%03i.jpg", image_counter);
            output = fopen(file, "w");
            if (output == NULL)
            {
                printf("Could not create output file\n");
                free(file);
                fclose(card);
                return 3;
            }

            image_counter++;
        }

        if (output != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output);
        }
    }

    free(file);

    if (output != NULL)
    {
        fclose(output);
    }

    fclose(card);
    return 0;
}
