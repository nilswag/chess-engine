#include <string.h>

#include "lce/core/board.h"

void lce_board_init(LCEBoard* board)
{
    memset(board->pieces, 0, sizeof(board->pieces));
}

void lce_load_fen(LCEBoard* board, const char* fen_str)
{

}