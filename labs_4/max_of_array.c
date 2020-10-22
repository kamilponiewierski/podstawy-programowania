#include <stdio.h>

int main()
{
    int tab[] = {213, 2123, 342, 21, 2132, 0};

    int max;
    max = tab[0];

    for (int i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
    {
        if (max < tab[i]) max = tab[i];
    }

    printf("%d\n", max);
    return 0;
}