#include <cstdint>
#include "../core/defines.h"
#include "../core/board.h"
#include "pawn.h"

namespace lce::generation::pawn
{
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
}