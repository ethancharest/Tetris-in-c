#ifndef PIECE_H
#define PIECE_H

#define SHAPE_I 0
#define SHAPE_O 1
#define SHAPE_T 2
#define SHAPE_S 3
#define SHAPE_Z 4
#define SHAPE_J 5
#define SHAPE_L 6

typedef struct {
    int shape[4][4];
    int x;
    int y;
} Piece;

void piece_init_t(Piece *p, int shape_id);

#endif