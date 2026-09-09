#include "board.h"
#include <stdio.h>

void board_init(Board *b) {
    b->width = BOARD_WIDTH;
    b->height = BOARD_HEIGHT;
    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int col = 0; col < BOARD_WIDTH; col++) {
            b->cells[row][col] = 0;
        }
    }
}

void board_print(Board *b) {
    for (int row = 0; row < b->height; row++) {
        for (int col = 0; col < b->width; col++) {
           if (b->cells[row][col] == 0) {
                printf(".");
           } else {
                printf("#");
           }
        }
        printf("\n");
    }
}
