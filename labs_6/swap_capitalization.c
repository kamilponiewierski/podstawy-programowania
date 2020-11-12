#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


bool isUpper(const char *ptr_cpy);

bool isLower(const char *ptr_cpy);

char *changeCapitalization(char *text)
{
    char *ptr_cpy = text;

    char *out = malloc(strlen(text));
    char *out_ptr = out;

    while (*ptr_cpy != '\0')
    {
        if (isUpper(ptr_cpy))
        {
            *out_ptr = (char) (*ptr_cpy - ('A' - 'a'));
        } else if (isLower(ptr_cpy))
        {
            *out_ptr = (char) (*ptr_cpy - ('a' - 'A'));
        } else
        {
            *out_ptr = *ptr_cpy;
        }

        ptr_cpy++;
        out_ptr++;
    }

    out_ptr++;
    *out_ptr = '\0';

    return out;
}

bool isLower(const char *ptr_cpy)
{ return 'a' <= *ptr_cpy && *ptr_cpy <= 'z'; }

bool isUpper(const char *ptr_cpy)
{ return 'A' <= *ptr_cpy && *ptr_cpy <= 'Z'; }


int main()
{
    char *output = changeCapitalization("ToTalnIe lOsowy tEkst");

    printf("%s", output);
    free(output);
    return 0;
}