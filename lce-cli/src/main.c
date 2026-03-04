#include "lce/core/board.h"

int main(void)
{
    LCEBoard board;
    lce_board_init(&board);

    lce_load_fen(&board, LCE_STARTING_FEN);

    return 0;
}