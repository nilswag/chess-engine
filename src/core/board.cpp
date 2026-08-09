#include <string>
#include <spdlog/spdlog.h>
#include "defines.h"
#include "board.h"

Board::Board(const std::string& fen_str)
{
	// piece placement
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

		uint64_t val = 1ULL << index;
		switch (c)
		{
		case 'p': pieces[tul(Color::Black)][tul(Piece::Pawn)] |= val; break;
		case 'n': pieces[tul(Color::Black)][tul(Piece::Knight)] |= val; break;
		case 'b': pieces[tul(Color::Black)][tul(Piece::Bishop)] |= val; break;
		case 'r': pieces[tul(Color::Black)][tul(Piece::Rook)] |= val; break;
		case 'q': pieces[tul(Color::Black)][tul(Piece::Queen)] |= val; break;
		case 'k': pieces[tul(Color::Black)][tul(Piece::King)] |= val; break;

		case 'P': pieces[tul(Color::Black)][tul(Piece::Pawn)] |= val; break;
		case 'N': pieces[tul(Color::Black)][tul(Piece::Knight)] |= val; break;
		case 'B': pieces[tul(Color::Black)][tul(Piece::Bishop)] |= val; break;
		case 'R': pieces[tul(Color::Black)][tul(Piece::Rook)] |= val; break;
		case 'Q': pieces[tul(Color::Black)][tul(Piece::Queen)] |= val; break;
		case 'K': pieces[tul(Color::Black)][tul(Piece::King)] |= val; break;

		default:
			break;
		}

		if (isdigit(c))
			index += c - '0';
		else
			index++;
	}
	it++;

	for (auto& color : pieces)
	{
		for (auto& pieces : color)
			occupied |= pieces;
	}
	empty = ~occupied;

	// side to move
	current_turn = *it++ == 'w';
	it++;

	// castling ability
	castling_ability = 0;
	while (it != fen_str.cend() && (c = *it++) != ' ')
	{
		if (c == '-')
			break;
		else if (c == 'K')
			castling_ability |= 1ULL << 3;
		else if (c == 'Q')
			castling_ability |= 1ULL << 2;
		else if (c == 'k')
			castling_ability |= 1ULL << 1;
		else if (c == 'q')
			castling_ability |= 1ULL << 0;
	}
	it++;

	// TODO: en passsant target square

	// TODO: halfmove clock
	
	// TODO: fullmove clock
}

uint64_t pawn_single_push_targets(Board& board, const Color& color)
{
	uint64_t pawns = board.pieces[tul(color)][tul(Piece::Pawn)];
	if (color == Color::White)
		return pawns;
	else
		;
}

uint64_t pawn_double_push_targets(Board& board, const Color& color)
{
	uint64_t pawns = board.pieces[tul(color)][tul(Piece::Pawn)];
	if (color == Color::White)
		return pawns;
	else
		;
}

uint64_t pawn_able_to_single_push(Board& board, const Color& color)
{
	uint64_t pawns = board.pieces[tul(color)][tul(Piece::Pawn)];
	if (color == Color::White)
		return pawns;
	else
		;
}

uint64_t pawn_able_to_double_push(Board& board, const Color& color)
{
	uint64_t pawns = board.pieces[tul(color)][tul(Piece::Pawn)];
	if (color == Color::White)
		return pawns;
	else
		;
}