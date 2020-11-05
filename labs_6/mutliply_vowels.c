#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isVowel(const char *ptr_cpy);

char *multiplyVowels(char *text)
{
    const int maximum_multiply = 3;

    char *ptr_cpy = text;

    char *out = malloc(strlen(text) * (maximum_multiply+1));
    char *out_ptr = out;

    while (*ptr_cpy != '\0')
    {
        *out_ptr = *ptr_cpy;
        out_ptr++;

        if (isVowel(ptr_cpy))
        {
            int multiplier = rand() % maximum_multiply;

            for (int i = 0; i < multiplier; i++)
            {
                *out_ptr = *ptr_cpy;
                out_ptr++;
            }
        }
        ptr_cpy++;
    }

    out_ptr++;
    *out_ptr = '\0';

    return out;
}

bool isVowel(const char *ptr_cpy)
{
    return *ptr_cpy == 'a' || *ptr_cpy == 'e' || *ptr_cpy == 'i' || *ptr_cpy == 'u' || *ptr_cpy == 'y' ||
           *ptr_cpy == 'o';
}

int main()
{
    char *output = multiplyVowels("Totalnie losowy tekst");

    printf("%s", output);
    free(output);
    return 0;
}
