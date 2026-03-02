#pragma once
#include <stdint.h>

typedef enum LCEPieceType {
    LCE_PIECE_TYPE_PAWN = 0,
    LCE_PIECE_TYPE_KNIGHT,
    LCE_PIECE_TYPE_BISHOP,
    LCE_PIECE_TYPE_ROOK,
    LCE_PIECE_TYPE_QUEEN,
    LCE_PIECE_TYPE_KING,
    LCE_PIECE_TYPE_N
} LCEPieceType;

typedef enum LCEPieceColor {
    LCE_PIECE_COLOR_WHITE = 0,
    LCE_PIECE_COLOR_BLACK,
    LCE_PIECE_COLOR_N
} LCEPieceColor;

typedef struct LCEBoard
{
    uint64_t board[LCE_PIECE_COLOR_N][LCE_PIECE_TYPE_N];
} LCEBoard;

void lce_board_init(LCEBoard* board);

void lce_load_fen(LCEBoard* board, const char* fen_str);