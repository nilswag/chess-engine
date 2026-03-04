#include <string.h>

#include "lce/core/board.h"

void lce_board_init(LCEBoard* board)
{
<<<<<<< HEAD

}

void lce_board_destroy(LCEBoard* board)
{
    
}

void lce_board_load_fen(LCEBoard* board, const char* fen_str)
{
    for (int i = 0; i < strlen(fen_str); i++)
    {

    }
=======
    memset(board->pieces, 0, sizeof(board->pieces));
}

void lce_load_fen(LCEBoard* board, const char* fen_str)
{

>>>>>>> ced23800e8de12efb2510b46c3bd059244ea60c4
}