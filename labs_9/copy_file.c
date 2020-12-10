#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const char filename[64] = "./text";
    FILE *ptr = fopen(filename, "r");
    if (ptr == NULL)
    {
        printf("ERROR");
        exit(1);
    }

    FILE *file_copy = fopen("./text_copy", "w");

    while (1)
    {
        char result = (char) fgetc(ptr);
        if (result == EOF)
        {
            break;
        }

        fputc(result, file_copy);
    }

    fclose(ptr);
    fclose(file_copy);
}
