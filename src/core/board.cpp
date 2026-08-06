#include <string>
#include <spdlog/spdlog.h>
#include "board.h"

Board::Board(const std::string& startingFen)
{
	parseFen(startingFen);
}

void Board::parseFen(const std::string& fenStr)
{
	// board
	int index = 56;
	char c;

	auto it = fenStr.cbegin();
	while (it != fenStr.cend() && (c = *it++) != ' ')
	{
		if (c == '/')
		{
			index -= 16;
			continue;
		}

		if (c == 'p')	   pieceBB[BLACK][PAWN] |= 1ULL << index;
		else if (c == 'n') pieceBB[BLACK][KNIGHT] |= 1ULL << index;
		else if (c == 'b') pieceBB[BLACK][BISHOP] |= 1ULL << index;
		else if (c == 'r') pieceBB[BLACK][ROOK] |= 1ULL << index;
		else if (c == 'q') pieceBB[BLACK][QUEEN] |= 1ULL << index;
		else if (c == 'k') pieceBB[BLACK][KING] |= 1ULL << index;
		else if (c == 'P') pieceBB[WHITE][PAWN] |= 1ULL << index;
		else if (c == 'N') pieceBB[WHITE][KNIGHT] |= 1ULL << index;
		else if (c == 'B') pieceBB[WHITE][BISHOP] |= 1ULL << index;
		else if (c == 'R') pieceBB[WHITE][ROOK] |= 1ULL << index;
		else if (c == 'Q') pieceBB[WHITE][QUEEN] |= 1ULL << index;
		else if (c == 'K') pieceBB[WHITE][KING] |= 1ULL << index;

		if (isdigit(c))
			index += c - '0';
		else
			index++;
	}

	// current/next move
	// castling
	// en passant

	spdlog::debug("Parsed FEN string: {}", fenStr);
}