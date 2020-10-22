#include <stdio.h>
#include <float.h>

int main()
{
    double tab[] = {12.123213, 2.123, 1.123, 5.321, 5.4321, 0.4231, 212.123, 42.0, 123.12};

    double soughtNumber = 42.0;

    for (int i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
    {
        if (tab[i] - DBL_EPSILON <= soughtNumber && tab[i] + DBL_EPSILON >= soughtNumber)
            printf("Znaleziono na indeksie %d\n", i);
    }

    return 0;
}