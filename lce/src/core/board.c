#include <string.h>
#include <stdint.h>

#include "lce/core/board.h"

void lce_board_load_fen(LCEBoard* board, const char* fen)
{
    memset(board->pieces, 0, sizeof(board->pieces));
    int index = 56; // start at a8
    const char* ptr = fen;

    while (*ptr && *ptr != ' ')
    {
        if (*ptr == '/') index -= 16; // because of LERF mapping and the row below we need to subtract 16
        else if (*ptr >= '1' && *ptr <= 8) index += *ptr - '0'; // skip empty squares
        else
        {
            LCEPieceType piece;
            LCEPieceColor color;
            switch (*ptr)
            {
                case 'k': 
                    piece = LCE_PIECE_TYPE_KING;
                    color = LCE_PIECE_COLOR_BLACK;
                    break;
                case 'q': break;
                case 'r': break;
                case 'b': break;
                case 'n': break;
                case 'p': break;
                
                case 'K': break;
                case 'Q': break;
                case 'R': break;
                case 'B': break;
                case 'N': break;
                case 'P': break;

                case '/': break;

                default: // skip invalid character
                    ptr++;
                    continue;
            }

            board->pieces[color][piece] = (uint64_t)1 << index;
            index++;
        }

        ptr++;
    }

    // TODO: add current move parsing
    // TODO: add castling parsing
    // TODO: add en passant parsing
    // TODO: add 50-move rule parsing
    // TODO: add total moves counter parsing
}