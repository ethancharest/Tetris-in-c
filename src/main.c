#include "board.h"
#include "piece.h"
#include <stdio.h>

int main(void) {
    Board board;
    board_init(&board);

    Piece piece;
    piece_init_t(&piece, SHAPE_T);

    // temporarily "stamp" the piece onto the board so board_print can show it
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (piece.shape[i][j] == 1) {
                board.cells[piece.y + i][piece.x + j] = 1;
            }
        }
    }

    board_print(&board);
    return 0;
}
