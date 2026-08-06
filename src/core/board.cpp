#include <string>
#include "board.h"

Board::Board(const std::string& startingFen)
{
	loadFen(startingFen);
}

void Board::loadFen(const std::string& fen)
{
	std::string::const_iterator it = fen.begin();
	it = parseBoard(it);
}

std::string::const_iterator parseBoard(const std::string::const_iterator& it)
{
	
}