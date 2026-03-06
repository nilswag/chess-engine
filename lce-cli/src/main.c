#include <stdio.h>

#include "util/util.h"

int main(void)
{
    LCEBoard board;
    lce_board_init(&board);

    lce_load_fen(&board, LCE_STARTING_FEN);
    lce_print_board(&board);

    lce_board_deinit(&board);
    return 0;
}