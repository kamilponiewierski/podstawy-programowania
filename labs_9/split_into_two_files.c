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

    FILE *file_part_1 = fopen("./text_p1", "w");
    FILE *file_part_2 = fopen("./text_p2", "w");

    while (1)
    {
        char result = (char) fgetc(ptr);
        if (result == EOF)
        {
            break;
        }
        fputc(result, file_part_1);

        char result_2 = (char) fgetc(ptr);
        if (result_2 == EOF)
        {
            break;
        }
        fputc(result_2, file_part_2);
    }

    fclose(ptr);
    fclose(file_part_1);
}