#include "app.h"      
#include "matrix.h"   

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