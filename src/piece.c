#include "piece.h"

static int shapes[7][4][4] = {
    // I
    {{0,0,0,0},
     {1,1,1,1},
     {0,0,0,0},
     {0,0,0,0}},
    // O
    {{0,1,1,0},
     {0,1,1,0},
     {0,0,0,0},
     {0,0,0,0}},
    // T
    {{0,1,0,0},
     {1,1,1,0},
     {0,0,0,0},
     {0,0,0,0}},
    // S
    {{0,1,1,0},
     {1,1,0,0},
     {0,0,0,0},
     {0,0,0,0}},
    // Z
    {{1,1,0,0},
     {0,1,1,0},
     {0,0,0,0},
     {0,0,0,0}},
    // J
    {{1,0,0,0},
     {1,1,1,0},
     {0,0,0,0},
     {0,0,0,0}},
    // L
    {{0,0,1,0},
     {1,1,1,0},
     {0,0,0,0},
     {0,0,0,0}}
};

void piece_init(Piece *p, int shape_id) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            p->shape[i][j] = shapes[shape_id][i][j];
        }
    }

    p->x = 3;
    p->y = 0;
}

int piece_can_move(Piece *p, Board *b, int dx, int dy) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (p->shape[i][j] == 0) {
                continue; // empty cell, nothing to check
            }

            int new_row = p->y + i + dy;
            int new_col = p->x + j + dx;

            // Check boundaries
            if (new_col < 0 || new_col >= b->width || 
                new_row < 0 || new_row >= b->height) {
                return 0; // out of bounds
            }
            // Check if the cell is already filled
            if (b->cells[new_row][new_col] != 0) {
                return 0; // cell is filled
            }
        }
    }
    return 1; // every filled cell passed all checks
}