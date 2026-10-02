#include <stdlib.h>
#include <nwbase/util.h>

#include "board.h"


void load_fen(Board* board, const char* fen_str)
{
	size_t count;
	char** str = split(fen_str, " ", &count);

	// piece placement


	// current turn

	// castling ability

	// en passent target square

	// halfmove clock

	// fullmove counter

	free(str);
}