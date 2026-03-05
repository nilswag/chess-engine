#include <stdio.h>

#include "util/util.h"

int main(void)
{
    LCEBoard board;
    lce_board_init(&board);

    lce_load_fen(&board, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    lce_print_board(&board);

    lce_board_deinit(&board);
    return 0;
}