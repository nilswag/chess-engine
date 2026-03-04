#include <stdio.h>

#include "lce/core/board.h"

void print_board(LCEBoard* board)
{
    for (int i = 63; i > 0; i--)
    {
        for (int type = 0; type < LCE_PIECE_TYPE_NR; type++)
        {
            for (int color = 0; type < LCE_PIECE_COLOR_NR; color++)
            {
                char c;
                if (lce_board_type_to_char(type, color, &c)) printf("%c", c);
            }
        }
        if (!(i % 8)) putchar('\n');
    }
}

int main(void)
{
    LCEBoard board;
    lce_load_fen(&board, LCE_STARTING_FEN);
    print_board(&board);

    return 0;
}