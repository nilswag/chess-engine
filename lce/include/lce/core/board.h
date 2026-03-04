#pragma once
#include <stdint.h>

<<<<<<< HEAD
typedef enum LCEPieceType
{
=======
#define LCE_STARTING_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

typedef enum LCEPieceType {
>>>>>>> ced23800e8de12efb2510b46c3bd059244ea60c4
    LCE_PIECE_TYPE_PAWN = 0,
    LCE_PIECE_TYPE_KNIGHT,
    LCE_PIECE_TYPE_BISHOP,
    LCE_PIECE_TYPE_ROOK,
    LCE_PIECE_TYPE_QUEEN,
    LCE_PIECE_TYPE_KING,
<<<<<<< HEAD
    LCE_PIECE_TYPE_NR
} LCEPieceType;

typedef enum LCEPieceColor 
{
    LCE_PIECE_COLOR_WHITE = 0,
    LCE_PIECE_COLOR_BLACK,
    LCE_PIECE_COLOR_NR
=======
    LCE_PIECE_TYPE_N
} LCEPieceType;

typedef enum LCEPieceColor {
    LCE_PIECE_COLOR_WHITE = 0,
    LCE_PIECE_COLOR_BLACK,
    LCE_PIECE_COLOR_N
>>>>>>> ced23800e8de12efb2510b46c3bd059244ea60c4
} LCEPieceColor;

typedef struct LCEBoard
{
<<<<<<< HEAD
    uint64_t board[LCE_PIECE_COLOR_NR][LCE_PIECE_TYPE_NR];
} LCEBoard;

void lce_board_init(LCEBoard* board);
void lce_board_destroy(LCEBoard* board);

void lce_board_load_fen(LCEBoard* board, const char* fen_str);
=======
    uint64_t pieces[LCE_PIECE_COLOR_N][LCE_PIECE_TYPE_N];
} LCEBoard;

void lce_board_init(LCEBoard* board);

void lce_load_fen(LCEBoard* board, const char* fen_str);
>>>>>>> ced23800e8de12efb2510b46c3bd059244ea60c4
