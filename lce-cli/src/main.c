#include <stdio.h>

#include "lce/core/board.h"

void print_board(LCEBoard* board)
{
    for (int rank = 7; rank >= 0; rank--)
    {
        char c = '.';

        for (int file = 0; file < 8; file++)
        {
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
            if (!(sq % 8)) putchar('\n');
        }
    }
}

int main(void)
{
    LCEBoard board;
    lce_load_fen(&board, "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2 ");
    print_board(&board);

    return 0;
}