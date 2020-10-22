#include <stdio.h>

int main()
{
    int tab[] = {10, 2, 42, 123, 12, 21231, 12, 123, -13, -4, 14};

    int size = sizeof(tab) / sizeof(tab[0]);

    for (int i = 0; i < size; i++)
    {
        int i_of_min = i;
        for (int j = i; j < size; j++)
        {
            if (tab[j] < tab[i_of_min])
            {
                i_of_min = j;
            }
        }

        int tmp = tab[i];
        tab[i] = tab[i_of_min];
        tab[i_of_min] = tmp;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
}