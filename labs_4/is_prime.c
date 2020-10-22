#include <stdio.h>

int main() {
    int possible_prime = 42;

    for (int i = 2; i * i <= possible_prime; i++) {
        if (possible_prime % i == 0) {
            printf("Nie jest\n");
            return 0;
        }
    }

    printf("Jest pierwsza\n");
    return 0;
}