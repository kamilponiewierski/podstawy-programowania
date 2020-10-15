#include <stdio.h>
#include <string.h>

int main() {
    int number;
    scanf("%d", &number);

    int lo = 0;
    int hi = 10;
    int guess = (lo + hi) / 2;
    while (1) {
        printf("Zgaduje, ze to %d\n", guess);
        char answer[10];
        scanf("%s", answer);

        if (strcmp(answer, "TAK") == 0) break;
        else if (strcmp(answer, "MNIEJSZA") == 0) {
            hi = guess;
            guess = (lo + hi) / 2;
        } else if (strcmp(answer, "WIEKSZA") == 0) {
            lo = guess;
            guess = (lo + hi + 1) / 2;
        } else {
            printf("Nie zrozumiano odpowiedzi");
        }
    }

    printf("Koniec");
}