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

	Board(const std::string& starting_fen);

private:
	void parseFen(const std::string& fen_str);

	uint64_t m_pieces[N_COLORS][N_PIECES] = {};
	char m_current_turn;
	std::string m_castling;
};