#include <stdio.h>

#include "util/util.h"

int main(void)
{
    LCEBoard board;
    lce_board_init(&board);

    lce_load_fen(&board, "8/8/8/4p1K1/2k1P3/8/8/8 b - - 0 1");
    lce_print_board(&board);

    lce_board_deinit(&board);
    return 0;
}