#include <string.h>
#include <stdint.h>

#include "lce/util/logger.h"
#include "lce/core/board.h"

LCEError lce_load_fen(LCEBoard* board, const char* fen)
{
    if (!board || !fen)
    {
        LCE_ERROR("Null pointer passed as argument");
        return LCE_ERROR_NULL_POINTER;
    }

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
            if (lce_board_char_to_type(*ptr, &piece, &color) != LCE_OK) return LCE_ERROR_FEN_PARSE;
            
            if (index < 0 || index >= 64)
            {
                LCE_ERROR("Invalid index for bitboard");
                return LCE_ERROR_OUT_OF_BOUNDS;
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

    return LCE_OK;
}

LCEError lce_board_char_to_type(char c, LCEPieceType* type, LCEPieceColor* color)
{
    if (!type || !color)
    {
        LCE_ERROR("Null pointer passed as argument");
        return LCE_ERROR_NULL_POINTER;
    }

    switch (c)
    {
        case 'p': *type = LCE_PIECE_TYPE_PAWN;   *color = LCE_PIECE_COLOR_BLACK; break;
        case 'n': *type = LCE_PIECE_TYPE_KNIGHT; *color = LCE_PIECE_COLOR_BLACK; break;
        case 'b': *type = LCE_PIECE_TYPE_BISHOP; *color = LCE_PIECE_COLOR_BLACK; break;
        case 'r': *type = LCE_PIECE_TYPE_ROOK;   *color = LCE_PIECE_COLOR_BLACK; break;
        case 'q': *type = LCE_PIECE_TYPE_QUEEN;  *color = LCE_PIECE_COLOR_BLACK; break;
        case 'k': *type = LCE_PIECE_TYPE_KING;   *color = LCE_PIECE_COLOR_BLACK; break;
        case 'P': *type = LCE_PIECE_TYPE_PAWN;   *color = LCE_PIECE_COLOR_WHITE; break;
        case 'N': *type = LCE_PIECE_TYPE_KNIGHT; *color = LCE_PIECE_COLOR_WHITE; break;
        case 'B': *type = LCE_PIECE_TYPE_BISHOP; *color = LCE_PIECE_COLOR_WHITE; break;
        case 'R': *type = LCE_PIECE_TYPE_ROOK;   *color = LCE_PIECE_COLOR_WHITE; break;
        case 'Q': *type = LCE_PIECE_TYPE_QUEEN;  *color = LCE_PIECE_COLOR_WHITE; break;
        case 'K': *type = LCE_PIECE_TYPE_KING;   *color = LCE_PIECE_COLOR_WHITE; break;
        default:
            LCE_ERROR("Invalid FEN character: %c", c);
            return LCE_ERROR_INVALID_ARGUMENT;
    }

    return LCE_OK;
}

LCEError lce_board_type_to_char(LCEPieceType type, LCEPieceColor color, char* c)
{
    if (!c)
    {
        LCE_ERROR("Null pointer passed as argument");
        return LCE_ERROR_NULL_POINTER;
    }

    if (type < 0 || type >= LCE_PIECE_TYPE_NR || color < 0 || color >= LCE_PIECE_COLOR_NR)
    {
        LCE_ERROR("Invalid piece type or color passed");
        return LCE_ERROR_INVALID_ARGUMENT;
    }

    static const char fen_chars[12] = { 'P', 'N', 'B', 'R', 'Q', 'K', 'p', 'n', 'b', 'r', 'q', 'k' };
    *c = fen_chars[type + (color * LCE_PIECE_TYPE_NR)];

    return LCE_OK;
}