#ifndef PIECE_H
#define PIECE_H

typedef struct {
    int shape[4][4];
    int x;
    int y;
} Piece;

void piece_init_t(Piece *p);

#endif