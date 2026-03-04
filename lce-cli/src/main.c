#include <stdio.h>

#include "lce/core/board.h"

void print_board(LCEBoard* board)
{
    for (int rank = 7; rank >= 0; rank--)
    {
        for (int file = 0; file < 8; file++)
        {
            char c = '.';
            int sq = rank * 8 + file;
            
            for (int color = 0; color < LCE_PIECE_COLOR_NR; color++)
            {
                for (int type = 0; type < LCE_PIECE_TYPE_NR; type++)
                {
                    if (board->pieces[color][type] & (1ULL << sq))
                    {
                        lce_board_piece_to_fen(color, type, &c);
                        goto print;
                    }
                }
            }
            
        print:
            printf("%c", c);
        }

        putchar('\n');
    }
}

int main(void)
{
    LCEBoard board;
    lce_load_fen(&board, LCE_STARTING_FEN);
    print_board(&board);

    lce_load_fen(&board, "8/8/8/4p1K1/2k1P3/8/8/8 b - - 0 1");
    print_board(&board);

    return 0;
}