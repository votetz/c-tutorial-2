#include <stdio.h>
#define ROWS 5
#define COLS 5

void fill_matrix(int m[ROWS][COLS]);
void print_matrix(int m[ROWS][COLS]);
int calc_diag_sum(int m[ROWS][COLS], int r, int c);
void print_square_3x3(int m[ROWS][COLS], int r, int c);
void find_max_square(int m[ROWS][COLS]);

int main()
{
    srand(time(NULL));

    int m[ROWS][COLS];

    fill_matrix(m);

    printf("Original Matrix (%dx%d):\n", ROWS, COLS);
    print_matrix(m);
    printf("\n");

    find_max_square(m);

    return 0;
}

void fill_matrix(int m[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            m[i][j] = rand() % 50;
        }
    }
}

void print_matrix(int m[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}
int calc_diag_sum(int m[ROWS][COLS], int r, int c) {
    return m[r][c] + m[r + 1][c + 1] + m[r + 2][c + 2];
}

void print_square_3x3(int m[ROWS][COLS], int r, int c) {
    int i, j;
    printf("The Square:\n");
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%3d ", m[r + i][c + j]);
        }
        printf("\n");
    }
}

void find_max_square(int m[ROWS][COLS]) {
    int max_sum = -1;
    int best_r = 0;
    int best_c = 0;
    int i, j;

    for (i = 0; i <= ROWS - 3; ++i) {
        for (j = 0; j <= COLS - 3; ++j) {

            int current_sum = calc_diag_sum(m, i, j);

            if (current_sum > max_sum) {
                max_sum = current_sum;
                best_r = i;
                best_c = j;
            }
        }
    }

    printf("3x3 square found at index [%d][%d]\n", best_r, best_c);
    printf("Max Diagonal Sum: %d\n", max_sum);

	print_square_3x3(m, best_r, best_c); 
}