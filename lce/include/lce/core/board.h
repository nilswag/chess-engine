#pragma once
#include <stdint.h>

#include "lce/util/defines.h"

#define LCE_STARTING_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

typedef enum LCEPieceType {
    LCE_PIECE_TYPE_PAWN = 0,
    LCE_PIECE_TYPE_KNIGHT,
    LCE_PIECE_TYPE_BISHOP,
    LCE_PIECE_TYPE_ROOK,
    LCE_PIECE_TYPE_QUEEN,
    LCE_PIECE_TYPE_KING,
    LCE_PIECE_TYPE_NR
} LCEPieceType;

typedef enum LCEPieceColor 
{
    LCE_PIECE_COLOR_WHITE = 0,
    LCE_PIECE_COLOR_BLACK,
    LCE_PIECE_COLOR_NR
} LCEPieceColor;

typedef struct LCEBoard
{
    // each bitboard used LERF mapping (little endian rank-file mapping)
    uint64_t pieces[LCE_PIECE_COLOR_NR][LCE_PIECE_TYPE_NR];
} LCEBoard;

LCEError lce_load_fen(LCEBoard* board, const char* fen);

LCEError lce_board_char_to_type(char c, LCEPieceType* type, LCEPieceColor* color);
LCEError lce_board_type_to_char(LCEPieceType type, LCEPieceColor color, char* c);
