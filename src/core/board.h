#pragma once
#include <string>
#include "defines.h"

struct Board
{
	Board() = default;
	~Board() = default;
	Board(const std::string& fen_str);
		
	uint64_t pieces[tul(bb::Color::Count)][tul(bb::Piece::Count)] = {};
	uint64_t empty = ULLONG_MAX;
	uint64_t occupied = 0;
	
	bool current_turn = true;
	uint8_t castling_ability = 0;
	uint8_t en_passant_sq = 0;
	uint8_t halfmove_clock = 0;
	uint8_t fullmove_clock = 0;
};

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