
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE_SQRT 3
#define BOARD_SIZE BOARD_SIZE_SQRT * BOARD_SIZE_SQRT

int check_column(const int *board);

int check_row(const int *board);

int check_diagonal(const int *board);

void initBoard(int *board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        *(board + i) = 0;
    }
}

int markBoard(int mark, int *board, int field)
{
    if (field < 0 || BOARD_SIZE < field || *(board + field) != 0) return 1;
    *(board + field) = mark;
    return 0;
}

void printBoard(int *board)
{
    for (int i = 0; i < BOARD_SIZE_SQRT; i++)
    {
        for (int j = 0; j < BOARD_SIZE_SQRT; j++)
        {
            int value = *(board + BOARD_SIZE_SQRT * i + j);
            printf("%c", value == 0 ? '.' : value == 1 ? 'O' : 'X');
        }
        printf("\n");
    }
}

int isGameWon(int *board)
{
    return check_column(board) || check_row(board) || check_diagonal(board);
}

int check_column(const int *board)
{
    for (int i = 0; i < BOARD_SIZE_SQRT; i++)
    {
        if (*(board + 0 + i) != 0 && *(board + 0 + i) == *(board + 3 + i) && *(board + 0 + i) == *(board + 6 + i))
            return *(board + 0 + i);
    }

    return 0;
}

int check_row(const int *board)
{
    for (int i = 0; i < BOARD_SIZE_SQRT; i++)
    {
        if (*(board + BOARD_SIZE_SQRT * i) != 0 &&
            *(board + BOARD_SIZE_SQRT * i) == *(board + BOARD_SIZE_SQRT * i + 1) &&
            *(board + BOARD_SIZE_SQRT * i) == *(board + BOARD_SIZE_SQRT * i + 2))
            return *(board + 0 + i);
    }

    return 0;
}

int check_diagonal(const int *board)
{
    if (*(board) != 0 && *(board) == *(board + 4) && *(board) == *(board + 8))
        return *(board);

    if (*(board + 2) != 0 && *(board + 2) == *(board + 4) && *(board + 2) == *(board + 6))
        return *(board + 2);

    return 0;
}


int main()
{
    int *tab = malloc(9 * sizeof(int));
    initBoard(tab);

    char name_one[20], name_two[20];

    scanf("%s", name_one);
    scanf("%s", name_two);

    int currentPlayer = 0;
    int game_status;
    while (!isGameWon(tab))
    {
        printf("Gracz: %s\n", currentPlayer % 2 == 0 ? name_one : name_two);
        int field;
        scanf("%d", &field);
        if (!markBoard(currentPlayer % 2 + 1, tab, field))
            currentPlayer++;
        else
        {
            printf("Pole zajęte lub poza zakresem\n");
        }
        printBoard(tab);
        printf("\n");
    }

    game_status = isGameWon(tab);
    printf("Wygrał(a): %s\n", game_status == 1 ? name_one : name_two);


    printBoard(tab);
}