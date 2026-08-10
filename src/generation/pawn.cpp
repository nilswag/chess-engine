#include <cstdint>
#include "../core/defines.h"
#include "../core/board.h"
#include "pawn.h"

namespace lce::generation::pawn
{
	uint64_t w_pawn_attacks(uint64_t pawns)
	{
		return bb::move_north_east(pawns) | bb::move_north_west(pawns);
	}

	uint64_t w_pawn_single_push_targets(uint64_t pawns, uint64_t empty)
	{
		return bb::move_north(pawns) & empty;
	}

	uint64_t w_pawn_double_push_targets(uint64_t pawns, uint64_t empty)
	{
		uint64_t step = bb::move_north(pawns & bb::constants::RANK_2);
		return bb::move_north(step & empty) & empty;
	}

	uint64_t w_pawn_targets(uint64_t pawns, uint64_t empty)
	{
		uint64_t single_push = w_pawn_single_push_targets(pawns, empty);
		uint64_t double_push = w_pawn_double_push_targets(pawns, empty);
		return single_push | double_push;
	}

	uint64_t b_pawn_attacks(uint64_t pawns)
	{
		return bb::move_south_east(pawns) | bb::move_south_west(pawns);
	}

	uint64_t b_pawn_single_push_targets(uint64_t pawns, uint64_t empty)
	{
		return bb::move_south(pawns) & empty;
	}

	uint64_t b_pawn_double_push_targets(uint64_t pawns, uint64_t empty)
	{
		uint64_t step = bb::move_south(pawns & bb::constants::RANK_2);
		return bb::move_south(step & empty) & empty;
	}

	uint64_t b_pawn_targets(uint64_t pawns, uint64_t empty)
	{
		uint64_t single_push = b_pawn_single_push_targets(pawns, empty);
		uint64_t double_push = b_pawn_double_push_targets(pawns, empty);
		return single_push | double_push;
	}
}