#pragma once
#include "base/types.h"

typedef enum
{
    WHITE,
    BLACK,
    N_COLORS
} Color;

typedef enum
{
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    N_PIECES
} Piece;

typedef struct
{
    u64 board[N_COLORS][N_PIECES]; // little endian
    u8 castling;
    Color turn;
} Position;

void load_fen(Position* pos, const char* fen_str);