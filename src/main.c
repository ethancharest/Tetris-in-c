#include "board.h"
#include "piece.h"
#include <stdio.h>

int main(void) {
    Board board;
    board_init(&board);

    Piece piece;
    piece_init(&piece, SHAPE_T);

    printf("Can move down? %d\n", piece_can_move(&piece, &board, 0, 1));
    printf("Can move left? %d\n", piece_can_move(&piece, &board, -1, 0));
    printf("Can move right? %d\n", piece_can_move(&piece, &board, 1, 0));

    // now push it hard against the left wall and try again
    piece.x = 0;
    printf("At x=0, can move left? %d\n", piece_can_move(&piece, &board, -1, 0));

    return 0;
}
