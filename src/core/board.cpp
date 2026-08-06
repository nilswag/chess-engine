#include <string>
#include "board.h"

Board::Board(const std::string& startingFen)
{
	loadFen(startingFen);
}

void Board::loadFen(const std::string& fen)
{
	parseBoard(fen);
}

void Board::parseBoard(const std::string& fen)
{
	int index = 0;
	auto it = fen.cbegin();
	while (it++ != fen.cend() && *it != ' ')
	{
		if (*it == '/')
			continue;

		if		(*it == 'p') pieceBB[BLACK | PAWN] = static_cast<uint64_t>(1) << index;
		else if (*it == 'P') pieceBB[BLACK | PAWN] = static_cast<uint64_t>(1) << index;
		else if (*it == 'n') pieceBB[BLACK | PAWN] = static_cast<uint64_t>(1) << index;
		else if (*it == 'N') pieceBB[BLACK | PAWN] = static_cast<uint64_t>(1) << index;
		else if (*it == 'b') pieceBB[BLACK | PAWN] = static_cast<uint64_t>(1) << index;
		else if (*it == 'B') pieceBB[BLACK | PAWN] = static_cast<uint64_t>(1) << index;
		else if (*it == 'r') pieceBB[BLACK | PAWN] = static_cast<uint64_t>(1) << index;
		else if (*it == 'R') pieceBB[BLACK | PAWN] = static_cast<uint64_t>(1) << index;
		else if (*it == 'q') pieceBB[BLACK | PAWN] = static_cast<uint64_t>(1) << index;
		else if (*it == 'Q') pieceBB[BLACK | PAWN] = static_cast<uint64_t>(1) << index;
		else if (*it == 'k') pieceBB[BLACK | PAWN] = static_cast<uint64_t>(1) << index;
		else if (*it == 'K') pieceBB[BLACK | PAWN] = static_cast<uint64_t>(1) << index;

		index++;
	}

	for (int i = 0; i < N_PIECES * 2; i++)
		pieceBB[i] ^= 7;
}