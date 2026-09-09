#ifndef BOARD_H
#define BOARD_H

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

typedef struct {
    int width;
    int height;
    int cells[BOARD_HEIGHT][BOARD_WIDTH];
} Board;

void board_init(Board *b);
void board_print(Board *b);

#endif