#include <stdio.h>

int count_words(char *text)
{
    char *ptr_copy = text;
    int counter =  1;
    while (*ptr_copy != '\0')
    {
        if (*ptr_copy == ' ')
        {
            counter++;
        }
        ptr_copy++;
    }

    return counter;
}

int main()
{
    char *text = "askdfjl ak sdfjkl ds asdf";
    printf("%d", count_words(text));
    return 0;
}