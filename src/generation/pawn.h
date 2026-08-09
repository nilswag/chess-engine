#pragma once
#include <cstdint>
#include "../core/defines.h"
#include "../core/board.h"

namespace lce::generation::pawn
{
	/**
	* @brief Generates set for all available single pawn push target squares
	*/
	uint64_t pawn_single_push_targets(Board& board, const bb::Color& color);

	/**
	 * @brief Generates set for all available double pawn push target squares
	 */
	uint64_t pawn_double_push_targets(Board& board, const bb::Color& color);

	/**
	 * @brief Generates set of the source squares of pawns able to do single push
	 */
	uint64_t pawn_able_to_single_push(Board& board, const bb::Color& color);

	/**
	 * @brief Generates set of the source squares of pawns able to do double push
	 */
	uint64_t pawn_able_to_double_push(Board& board, const bb::Color& color);
}