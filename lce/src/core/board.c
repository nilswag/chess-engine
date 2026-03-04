#include <string.h>
#include <stdint.h>

#include "lce/util/logger.h"
#include "lce/core/board.h"

void lce_board_load_fen(LCEBoard* board, const char* fen)
{
    LCE_TRACE("FEN string: %s", fen);

    memset(board->pieces, 0, sizeof(board->pieces));
    int index = 56; // start at a8
    const char* ptr = fen;

    LCE_TRACE("Started parsing FEN string");
    while (*ptr && *ptr != ' ')
    {
        if (*ptr == '/') index -= 16; // because of LERF mapping and the row below we need to subtract 16
        else if (*ptr >= '1' && *ptr <= '8') index += *ptr - '0'; // skip empty squares
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

                case 'q': 
                    piece = LCE_PIECE_TYPE_QUEEN;
                    color = LCE_PIECE_COLOR_BLACK;
                    break;

                case 'r':
                    piece = LCE_PIECE_TYPE_ROOK;
                    color = LCE_PIECE_COLOR_BLACK;
                    break;

                case 'b':
                    piece = LCE_PIECE_TYPE_BISHOP;
                    color = LCE_PIECE_COLOR_BLACK;
                    break;

                case 'n':
                    piece = LCE_PIECE_TYPE_KNIGHT;
                    color = LCE_PIECE_COLOR_BLACK;
                    break;

                case 'p':
                    piece = LCE_PIECE_TYPE_PAWN;
                    color = LCE_PIECE_COLOR_BLACK;
                    break;
                
                case 'K': 
                    piece = LCE_PIECE_TYPE_KING;
                    color = LCE_PIECE_COLOR_WHITE;
                    break;

                case 'Q': 
                    piece = LCE_PIECE_TYPE_QUEEN;
                    color = LCE_PIECE_COLOR_WHITE;
                    break;

                case 'R':
                    piece = LCE_PIECE_TYPE_ROOK;
                    color = LCE_PIECE_COLOR_WHITE;
                    break;

                case 'B':
                    piece = LCE_PIECE_TYPE_BISHOP;
                    color = LCE_PIECE_COLOR_WHITE;
                    break;

                case 'N':
                    piece = LCE_PIECE_TYPE_KNIGHT;
                    color = LCE_PIECE_COLOR_WHITE;
                    break;

                case 'P':
                    piece = LCE_PIECE_TYPE_PAWN;
                    color = LCE_PIECE_COLOR_WHITE;
                    break;

                default: // skip invalid character
                    LCE_WARN("Invalid FEN character detected: %c", *ptr);
                    ptr++;
                    continue;
            }
            
            if (index < 0 || index >= 64)
            {
                LCE_WARN("Invalid index detected for bitboard");
                return;
            }
            board->pieces[color][piece] |= 1ULL << index;
            index++;
        }

        ptr++;
    }
    LCE_TRACE("Finished parsing FEN string");

    // TODO: add current move parsing
    // TODO: add castling parsing
    // TODO: add en passant parsing
    // TODO: add 50-move rule parsing
    // TODO: add total moves counter parsing
}