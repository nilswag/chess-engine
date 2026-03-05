#include <stdio.h>

#include "lce/util/logger.h"
#include "util.h"

LCEError lce_print_board(LCEBoard* board)
{
    if (!board)
    {
        LCE_WARN("Null pointer passed as argument");
        return LCE_ERROR_NULL_POINTER;
    }

    static const char rank_chars[8] = { 'a','b','c','d','e','f','g','h' };

    for (int rank = 7; rank >= 0; rank--)
    {
        printf("%d ", rank);

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
                        goto found_piece;
                    }
                }
            }

        found_piece:
            printf("%c", c);
        }

        putchar('\n');
    }

    printf("\n  ");
    for (int i = 0; i < 8; i++)
        printf("%c", rank_chars[i]);
    putchar('\n');

    return LCE_OK;
}