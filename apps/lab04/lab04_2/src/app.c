#include <stdio.h>

#define ROWS 5
#define COLS 5

int main()
{
    srand(time(NULL));

    int m[ROWS][COLS];
    int i, j;

    printf("Original Matrix (%dx%d):\n", ROWS, COLS);
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            m[i][j] = rand() % 50; 
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int max_sum = -1; 
    int best_r = 0;   
    int best_c = 0;   

    for (i = 0; i <= ROWS - 3; ++i) {
        for (j = 0; j <= COLS - 3; ++j) {

            int current_sum = m[i][j] + m[i + 1][j + 1] + m[i + 2][j + 2];

            if (current_sum > max_sum) {
                max_sum = current_sum;
                best_r = i;
                best_c = j;
            }
        }
    }

    printf("Best 3x3 square found at index [%d][%d]\n", best_r, best_c);
    printf("Max Diagonal Sum: %d\n", max_sum);
    printf("The Square:\n");

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {

            printf("%3d ", m[best_r + i][best_c + j]);
        }
        printf("\n");
    }

    return 0;
}