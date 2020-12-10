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

    char imie[255];
    char wiek[255];

    if (fscanf(ptr, "%s", imie) == EOF) exit(1);
    if (fscanf(ptr, "%s", wiek) == EOF) exit(1);

    printf("Jestem %s, mam %s lat", imie, wiek);

    fclose(ptr);
}
