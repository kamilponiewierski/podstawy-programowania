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
    const char searched_for[64] = "slowo";

    char buff[255];
    while (1)
    {
        if (fscanf(ptr, "%s", buff) == EOF)
            break;

        if (strcmp(buff, searched_for) == 0)
        {
            printf("FOUND\n");
            remove(filename);
            exit(0);
        }

    }
    fclose(ptr);
}