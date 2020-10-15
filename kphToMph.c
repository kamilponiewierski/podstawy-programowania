#include <stdio.h>

int main() {
    char separator[16] = "---------------\0";
    char firstLine[16];
    char secondLine[16];
    int kmh;

    scanf("%s", firstLine);
    scanf("%s", secondLine);
    scanf("%d", &kmh);

    double kmhToMph = 0.621371192;

    double rawMph = kmh * kmhToMph;

    int mph = rawMph + 2;
    mph -= mph % 5;

    printf("%s\n", separator);
    printf("|%*.13s|\n", 13, firstLine);
    printf("|%*.13s|\n", 13, secondLine);
    printf("%s\n", separator);
    printf("|  km/h|   m/h|\n");
    printf("%s\n", separator);
    printf("|%6d|%6d|\n", kmh, mph);
    printf("%s\n", separator);

    return 0;
}