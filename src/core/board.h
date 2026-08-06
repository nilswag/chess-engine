#pragma once
#include <cstdint>
#include <string>

#define DEFAULT_POSITION "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

class Board
{
public:
	enum PieceType
	{
		PAWN = 2,
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

	Board(const std::string& position = DEFAULT_POSITION);

private:
	void LoadFen(const std::string& position);

	uint64_t m_pieceBB[N_PIECES * 2];
};