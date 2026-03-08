#include <stdio.h>

#include "util/util.h"

int main(void)
{
    LCEBoard board;
    lce_board_init(&board);

    lce_load_fen(&board, "a");
    lce_print_board(&board);

    lce_board_deinit(&board);
    return 0;
}