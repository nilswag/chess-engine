#include <string>
#include <spdlog/spdlog.h>
#include "board.h"

Board::Board(const std::string& starting_fen)
{
	parseFen(starting_fen);
}

void Board::parseFen(const std::string& fen_str)
{
	// board parsing
	int index = 56;
	char c;

	auto it = fen_str.cbegin();
	while (it != fen_str.cend() && (c = *it++) != ' ')
	{
		if (c == '/')
		{
			index -= 16;
			continue;
		}

		if (c == 'p')	   m_pieces[BLACK][PAWN] |= 1ULL << index;
		else if (c == 'n') m_pieces[BLACK][KNIGHT] |= 1ULL << index;
		else if (c == 'b') m_pieces[BLACK][BISHOP] |= 1ULL << index;
		else if (c == 'r') m_pieces[BLACK][ROOK] |= 1ULL << index;
		else if (c == 'q') m_pieces[BLACK][QUEEN] |= 1ULL << index;
		else if (c == 'k') m_pieces[BLACK][KING] |= 1ULL << index;
		else if (c == 'P') m_pieces[WHITE][PAWN] |= 1ULL << index;
		else if (c == 'N') m_pieces[WHITE][KNIGHT] |= 1ULL << index;
		else if (c == 'B') m_pieces[WHITE][BISHOP] |= 1ULL << index;
		else if (c == 'R') m_pieces[WHITE][ROOK] |= 1ULL << index;
		else if (c == 'Q') m_pieces[WHITE][QUEEN] |= 1ULL << index;
		else if (c == 'K') m_pieces[WHITE][KING] |= 1ULL << index;

		if (isdigit(c))
			index += c - '0';
		else
			index++;
	}
	it++;

	// current/next move
	m_current_turn = *it;

	// castling
	// en passant

	spdlog::debug("Parsed FEN string: {}", fen_str);
}