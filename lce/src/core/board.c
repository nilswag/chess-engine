#include <string.h>
#include <stdint.h>

#include "lce/util/logger.h"
#include "lce/core/board.h"

LCEError lce_board_init(LCEBoard* board)
{
    if (!board)
    {
        LCE_FATAL("Null pointer passed as argument");
        return LCE_ERROR_NULL_POINTER;
    }

    memset(board, 0, sizeof(LCEBoard));
    return LCE_OK;
}

LCEError lce_board_deinit(LCEBoard* board)
{
    if (!board)
    {
        LCE_FATAL("Null pointer passed as argument");
        return LCE_ERROR_NULL_POINTER;
    }

    return LCE_OK;
}

LCEError lce_load_fen(LCEBoard* board, const char* fen)
{
    if (!board || !fen)
    {
        LCE_ERROR("Null pointer passed as argument");
        return LCE_ERROR_NULL_POINTER;
    }

    LCE_DEBUG("FEN string: %s", fen);

    memset(board->pieces, 0, sizeof(board->pieces));
    int index = 56; // start at a8
    const char* ptr = fen;

    LCE_TRACE("Started parsing FEN string");
    // parsing pieces
    LCE_TRACE("Parsing pieces...");
    while (*ptr && *ptr != ' ')
    {
        if (*ptr == '/') index -= 16; // because of LERF mapping and the row below we need to subtract 16
        else if (*ptr >= '1' && *ptr <= '8') index += *ptr - '0'; // skip empty squares
        else
        {
            LCEPieceType type;
            LCEPieceColor color;
            if (lce_board_fen_to_piece(*ptr, &color, &type) != LCE_OK) return LCE_ERROR_FEN_PARSE;
            
            if (index < 0 || index >= 64)
            {
                LCE_ERROR("Invalid index for bitboard");
                return LCE_ERROR_OUT_OF_BOUNDS;
            }

            board->pieces[color][type] |= 1ULL << index;
            index++;
        }

        ptr++;
    }
    
    // parsing current turn
    LCE_TRACE("Parsing current turn...");
    ptr++;
    if (*ptr == 'w') board->current_turn = LCE_PIECE_COLOR_WHITE;
    else if (*ptr == 'b') board->current_turn = LCE_PIECE_COLOR_BLACK;
    else 
    {
        LCE_ERROR("Invalid fen string");
        return LCE_ERROR_FEN_PARSE;
    }
    
    // TODO: add castling parsing
    // TODO: add en passant parsing
    // TODO: add 50-move rule parsing
    // TODO: add total moves counter parsing

    LCE_TRACE("Finished parsing FEN string");
    LCE_DEBUG("Loaded position: side=%c, pieces=%d", board->current_turn == LCE_PIECE_COLOR_WHITE ? 'w' : 'b', 10);
    return LCE_OK;
}

LCEError lce_board_fen_to_piece(char c, LCEPieceColor* color, LCEPieceType* type)
{
    if (!color || !type)
    {
        LCE_ERROR("Null pointer passed as argument");
        return LCE_ERROR_NULL_POINTER;
    }

    switch (c)
    {
        case 'p': *color = LCE_PIECE_COLOR_BLACK; *type = LCE_PIECE_TYPE_PAWN;   break;
        case 'n': *color = LCE_PIECE_COLOR_BLACK; *type = LCE_PIECE_TYPE_KNIGHT; break;
        case 'b': *color = LCE_PIECE_COLOR_BLACK; *type = LCE_PIECE_TYPE_BISHOP; break;
        case 'r': *color = LCE_PIECE_COLOR_BLACK; *type = LCE_PIECE_TYPE_ROOK;   break;
        case 'q': *color = LCE_PIECE_COLOR_BLACK; *type = LCE_PIECE_TYPE_QUEEN;  break;
        case 'k': *color = LCE_PIECE_COLOR_BLACK; *type = LCE_PIECE_TYPE_KING;   break;
        case 'P': *color = LCE_PIECE_COLOR_WHITE; *type = LCE_PIECE_TYPE_PAWN;   break;
        case 'N': *color = LCE_PIECE_COLOR_WHITE; *type = LCE_PIECE_TYPE_KNIGHT; break;
        case 'B': *color = LCE_PIECE_COLOR_WHITE; *type = LCE_PIECE_TYPE_BISHOP; break;
        case 'R': *color = LCE_PIECE_COLOR_WHITE; *type = LCE_PIECE_TYPE_ROOK;   break;
        case 'Q': *color = LCE_PIECE_COLOR_WHITE; *type = LCE_PIECE_TYPE_QUEEN;  break;
        case 'K': *color = LCE_PIECE_COLOR_WHITE; *type = LCE_PIECE_TYPE_KING;   break;
        default:
            LCE_ERROR("Invalid FEN character: %c", c);
            return LCE_ERROR_INVALID_ARGUMENT;
    }

    return LCE_OK;
}

LCEError lce_board_piece_to_fen(LCEPieceColor color, LCEPieceType type, char* c)
{
    if (!c)
    {
        LCE_ERROR("Null pointer passed as argument");
        return LCE_ERROR_NULL_POINTER;
    }

    if (color < 0 || color >= LCE_PIECE_COLOR_NR || type < 0 || type >= LCE_PIECE_TYPE_NR)
    {
        LCE_ERROR("Invalid piece color or type passed");
        return LCE_ERROR_INVALID_ARGUMENT;
    }

    static const char fen_chars[12] = { 'P', 'N', 'B', 'R', 'Q', 'K', 'p', 'n', 'b', 'r', 'q', 'k' };
    *c = fen_chars[type + (color * LCE_PIECE_TYPE_NR)];

    return LCE_OK;
}