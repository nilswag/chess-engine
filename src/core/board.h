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

	Board(const std::string& startingFen = DEFAULT_POSITION);

private:
	void loadFen(const std::string& fen);
	std::string::const_iterator parseBoard(const std::string::const_iterator& it);

	uint64_t pieceBB[N_PIECES * 2];
};