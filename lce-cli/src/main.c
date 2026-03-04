#include "lce/util/logger.h"
#include "lce/core/board.h"

void print_board(LCEBoard* board)
{

}

int main(void)
{
    LCEBoard board;
    lce_board_init(&board);

    lce_board_load_fen(&board, LCE_STARTING_FEN);
    print_board(&board);

    return 0;
}