#pragma once
#include <string>
#include "defines.h"

namespace lce
{
	struct Board
	{
		Board() = default;
		~Board() = default;
		Board(const std::string& fen_str);

		uint64_t pieces[tul(bb::Color::Count)][tul(bb::Piece::Count)] = {};
		uint64_t occupancy[tul(bb::Color::Count)] = {};
		uint64_t occupied = 0;
		uint64_t empty = ULLONG_MAX;

		bool current_turn = true;
		uint8_t castling_ability = 0;
		uint8_t en_passant_sq = 0;
		uint8_t halfmove_clock = 0;
		uint8_t fullmove_clock = 0;
	};

	/**
	* @brief Prints a formatted bitboard
	*/
	void print_bitboard(uint64_t board);

	/**
	* @brief Prints a formatted board
	*/
	void print_board(Board& board);

}