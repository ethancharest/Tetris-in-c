#include "piece.h"

void piece_init_t(Piece *p) {
    int t_shape[4][4] = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            p->shape[i][j] = t_shape[i][j];
        }
    }

    p->x = 3;
    p->y = 0;
}