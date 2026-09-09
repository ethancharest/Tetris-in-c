#include "board.h"
#include "piece.h"
#include "input.h"
#include <stdio.h>
#include <unistd.h>

int main(void) {
    Board board;
    board_init(&board);

    Piece piece;
    piece_init(&piece, SHAPE_T);

    input_enable_raw_mode();

    while (1) {
        int key = input_read_key();

        int dx = 0, dy = 0;
        if (key == 'a') dx = -1;
        if (key == 'd') dx = 1;
        if (key == 's') dy = 1;
        if (key == 'q') break;

        if ((dx != 0 || dy != 0) && piece_can_move(&piece, &board, dx, dy)) {
            piece.x += dx;
            piece.y += dy;
        }

        // build a display copy each frame
        Board display = board;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (piece.shape[i][j] == 1) {
                    display.cells[piece.y + i][piece.x + j] = 1;
                }
            }
        }

        printf("\033[H\033[J");
        board_print(&display);

        usleep(50000); // 50ms, keeps the loop from spinning too fast
    }

    input_disable_raw_mode();
    return 0;
}
