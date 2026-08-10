#pragma once
#include <cstdint>
#include "../core/defines.h"
#include "../core/board.h"

namespace lce::generation::pawn
{
	/**
	* @brief Returns set of all pseudo-legal pawn attacks for white
	*/
	uint64_t w_pawn_attacks(uint64_t pawns);

	/**
	* @brief Returns set of single push targets for white pawns
	*/
	uint64_t w_pawn_single_push_targets(uint64_t pawns, uint64_t empty);

	/**
	* @brief Returns set of double push targets for white pawns
	*/
	uint64_t w_pawn_double_push_targets(uint64_t pawns, uint64_t empty);

	/**
	* @brief Returns set of single and double push targets for white pawns
	*/
	uint64_t w_pawn_targets(uint64_t pawns, uint64_t empty);

	/**
	* @brief Returns set of all pseudo-legal pawn attacks for black
	*/
	uint64_t b_pawn_attacks(uint64_t pawns);

	/**
	* @brief Returns set of single push targets for black pawns
	*/
	uint64_t b_pawn_single_push_targets(uint64_t pawns, uint64_t empty);

	/**
	* @brief Returns set of double push targets for black pawns
	*/
	uint64_t b_pawn_double_push_targets(uint64_t pawns, uint64_t empty);

	/**
	* @brief Returns set of single and double push targets for black pawns
	*/
	uint64_t b_pawn_targets(uint64_t pawns, uint64_t empty);
}