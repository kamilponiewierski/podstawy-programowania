#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    double sum = 0;

    for(int i = 0; i < n; i++) {
        double a;
        scanf("%lf", &a);

        sum += a;
    }

    printf("average: %lf\n", sum / n);
    printf("sum: %lf\n", sum);

    return 0;
}