#include "fill_rectangle.h"
#include <stdio.h>

void fill_rectangle_neg(int *upper_left, int *bottom_right, int n_row, int n_col, int fill) {
    int width = (bottom_right - upper_left) % n_col + 1;
    int height = (bottom_right - upper_left) / n_col + 1;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int *at = upper_left + (n_col * i) + j;
            *at = fill;
        }
    }
}

void fill_rectangle_pos(int *upper_right, int *bottom_left, int n_row, int n_col, int fill) {
    int width = (upper_right - bottom_left + (height * n_col)) % n_col + 1;
//    printf("width = %d, height = %d\n", width, height);
    
    fill_rectangle_neg(upper_right - width + 1, bottom_left + width - 1, n_row, n_col, fill);
}
