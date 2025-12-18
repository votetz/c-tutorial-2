#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void fill_matrix(int m[ROWS][COLS]);
void print_matrix(int m[ROWS][COLS]);
int calc_diag_sum(int m[ROWS][COLS], int r, int c);
void print_square_3x3(int m[ROWS][COLS], int r, int c);
void find_max_square(int m[ROWS][COLS]);

#endif