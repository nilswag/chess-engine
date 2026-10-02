#pragma once

#include <nwbase/defines.h>

typedef enum
{
	PAWN = 0,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING,
	N_PIECES
} PieceType;

typedef enum
{
	WHITE = 0,
	BLACK,
	N_COLORS
} PieceColor;

typedef struct
{
	u64 pieces[N_COLORS][N_PIECES]; // LERF mapping
	u64 occupied;
} Board;

void load_fen(Board* board, const char* fen_str);

static inline u64 move_nort(u64 pieces);
static inline u64 move_noea(u64 pieces);
static inline u64 move_east(u64 pieces);
static inline u64 move_soea(u64 pieces);
static inline u64 move_sout(u64 pieces);
static inline u64 move_sowe(u64 pieces);
static inline u64 move_west(u64 pieces);
static inline u64 move_nowe(u64 pieces);