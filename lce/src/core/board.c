#include <string.h>

#include "lce/core/board.h"

void lce_board_init(LCEBoard* board)
{
    memset(board->pieces, 0, sizeof(board->pieces));
}

void lce_board_destroy(LCEBoard* board)
{
    
}

void lce_board_load_fen(LCEBoard* board, const char* fen_str)
{
    for (int i = 0; i < strlen(fen_str); i++)
    {
        char c = fen_str[i];
        switch (c)
        {

        }
    }
}