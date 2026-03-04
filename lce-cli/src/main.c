#include <stdio.h>

#include "lce/core/board.h"

void print_board(LCEBoard* board)
{
    for (int i = 63; i >= 0; i--)
    {
        char c = '.';

        for (int type = 0; type < LCE_PIECE_TYPE_NR; type++)
        {
            for (int color = 0; color < LCE_PIECE_COLOR_NR; color++)
            {
                if (board->pieces[color][type] & (1ULL << i))
                {
                    lce_board_type_to_char(type, color, &c);
                    goto print;
                }
            }
        }

    print:
        printf("%c", c);

        if (i % 8 == 0)
            printf("\n");
    }
}

int main(void)
{
    LCEBoard board;
    lce_load_fen(&board, LCE_STARTING_FEN);
    print_board(&board);

    return 0;
}