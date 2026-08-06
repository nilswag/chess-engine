#pragma once
#include <cstdint>
#include <string>

#define DEFAULT_POSITION "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

class Board
{
public:
	enum PieceType
	{
		PAWN = 0,
		KNIGHT,
		BISHOP,
		ROOK,
		QUEEN,
		KING,
		N_PIECES
	};

	enum PieceColor
	{
		BLACK = 0,
		WHITE,
		N_COLORS
	};

	Board(const std::string& startingFen);

private:
	void parseFen(const std::string& fenStr);

	uint64_t pieceBB[N_COLORS][N_PIECES] = {};
};