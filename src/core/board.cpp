#include <string>
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
		case 'p': pieces[tul(bb::Color::Black)][tul(bb::Piece::Pawn)] |= val; break;
		case 'n': pieces[tul(bb::Color::Black)][tul(bb::Piece::Knight)] |= val; break;
		case 'b': pieces[tul(bb::Color::Black)][tul(bb::Piece::Bishop)] |= val; break;
		case 'r': pieces[tul(bb::Color::Black)][tul(bb::Piece::Rook)] |= val; break;
		case 'q': pieces[tul(bb::Color::Black)][tul(bb::Piece::Queen)] |= val; break;
		case 'k': pieces[tul(bb::Color::Black)][tul(bb::Piece::King)] |= val; break;

		case 'P': pieces[tul(bb::Color::Black)][tul(bb::Piece::Pawn)] |= val; break;
		case 'N': pieces[tul(bb::Color::Black)][tul(bb::Piece::Knight)] |= val; break;
		case 'B': pieces[tul(bb::Color::Black)][tul(bb::Piece::Bishop)] |= val; break;
		case 'R': pieces[tul(bb::Color::Black)][tul(bb::Piece::Rook)] |= val; break;
		case 'Q': pieces[tul(bb::Color::Black)][tul(bb::Piece::Queen)] |= val; break;
		case 'K': pieces[tul(bb::Color::Black)][tul(bb::Piece::King)] |= val; break;

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

uint64_t pawn_single_push_targets(Board& board, const bb::Color& color)
{
	uint64_t pawns = board.pieces[tul(color)][tul(bb::Piece::Pawn)];
	if (color == bb::Color::White)
		return bb::move_north(pawns) & board.empty;
	else
		return bb::move_south(pawns) & board.empty;
}

uint64_t pawn_double_push_targets(Board& board, const bb::Color& color)
{
	uint64_t single_push = pawn_single_push_targets(board, color);
	if (color == bb::Color::White)
	{
		uint64_t rank_4 = 0x00000000FF000000ULL;
		return bb::move_north(single_push);
	}
	else
	{
		uint64_t rank_5 = 0x000000FF00000000ULL;
		return bb::move_south(single_push);
	}
}

uint64_t pawn_able_to_single_push(Board& board, const bb::Color& color)
{
	uint64_t pawns = board.pieces[tul(color)][tul(bb::Piece::Pawn)];
	if (color == bb::Color::White)
		return bb::move_south(board.empty) & pawns;
	else
		return bb::move_north(board.empty) & pawns;
}

uint64_t pawn_able_to_double_push(Board& board, const bb::Color& color)
{
	uint64_t pawns = board.pieces[tul(color)][tul(bb::Piece::Pawn)];
	if (color == bb::Color::White)
	{
		uint64_t rank_4 = 0x00000000FF000000ULL;
		uint64_t empty_rank_3 = bb::move_south(board.empty & rank_4) & board.empty;
		return bb::move_south(empty_rank_3) & pawns;
	}
	else
	{
		uint64_t rank_5 = 0x000000FF00000000ULL;
		uint64_t empty_rank_6 = bb::move_north(board.empty & rank_5) & board.empty;
		return bb::move_north(empty_rank_6) & pawns;
	}
}