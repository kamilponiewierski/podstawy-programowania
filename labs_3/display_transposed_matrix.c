#include <stdio.h>
#define matrix_size 2

int main() {
    float matrix[matrix_size][matrix_size];

    for (int i = 0; i < matrix_size; i++){
        for (int j = 0; j < matrix_size; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    for (int i = 0; i < matrix_size; i++){
        for (int j = 0; j < matrix_size; j++) {
            printf("%f ", matrix[j][i]);
        }
        printf("\n");
    }

    return 0;
}