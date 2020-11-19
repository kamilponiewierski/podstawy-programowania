#include <stdio.h>
#include <math.h>

#define DAYS_IN_WEEK 7

int daysCount(int month)
{
    if (month == 2)
        return 28;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
}

void printMonth(int month)
{
    printf("Miesiac %d\n", month);
}

void printDays()
{
    printf("|Ni|Po|Wt|Sr|Cz|Pt|So|\n");
}

void printRow(int firstDay, int firstPosition, int lastDay)
{
    printf("|");
    for (int i = 0; i < DAYS_IN_WEEK; i++)
    {
        int day_to_display_now = firstDay + i - firstPosition;
        if (i < firstPosition || day_to_display_now > lastDay)
            printf("  |");
        else
            printf("%2d|", day_to_display_now);
    }
    printf("\n");
}

int main()
{
    int month = 5, starting_day = 5;

    printMonth(month);
    printDays();
    double min_days = starting_day + daysCount(month);
    int rows = ceil(min_days / DAYS_IN_WEEK);

    int days_to_print = daysCount(month);

    for (int i = 0; i < rows; i++)
    {
        printRow(i == 0 ? 1 : 1 + 7 * i - starting_day, i == 0 ? starting_day : 0, days_to_print);
    }
}
