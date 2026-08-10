#pragma once
#include <cstdint>
#include <utility>

namespace lce
{
	/**
 * @brief Shorthand for std::to_underlying
 */
	template <typename E>
	inline constexpr auto tul(E e)
	{
		return std::to_underlying(e);
	}

	namespace bb
	{
		enum class Color : uint8_t
		{
			Black,
			White,
			Count
		};

		enum class Piece : uint8_t
		{
			Pawn,
			Knight,
			Bishop,
			Rook,
			Queen,
			King,
			Count
		};

		// LERF (little-endian rank-file) mapping
		enum class Squares : uint8_t
		{
			a1, b1, c1, d1, e1, f1, g1, h1,
			a2, b2, c2, d2, e2, f2, g2, h2,
			a3, b3, c3, d3, e3, f3, g3, h3,
			a4, b4, c4, d4, e4, f4, g4, h4,
			a5, b5, c5, d5, e5, f5, g5, h5,
			a6, b6, c6, d6, e6, f6, g6, h6,
			a7, b7, c7, d7, e7, f7, g7, h7,
			a8, b8, c8, d8, e8, f8, g8, h8
		};

		namespace constants
		{
			constexpr uint64_t A_FILE = 0x0101010101010101ULL;
			constexpr uint64_t H_FILE = 0x8080808080808080ULL;
			constexpr uint64_t NOT_A_FILE = ~A_FILE;
			constexpr uint64_t NOT_H_FILE = ~H_FILE;

			constexpr uint64_t RANK_1 = 0x00000000000000FFULL;
			constexpr uint64_t RANK_2 = 0x000000000000FF00ULL;
			constexpr uint64_t RANK_3 = 0x0000000000FF0000ULL;
			constexpr uint64_t RANK_4 = 0x00000000FF000000ULL;
			constexpr uint64_t RANK_5 = 0x000000FF00000000ULL;
			constexpr uint64_t RANK_6 = 0x0000FF0000000000ULL;
			constexpr uint64_t RANK_7 = 0x00FF000000000000ULL;
			constexpr uint64_t RANK_8 = 0xFF00000000000000ULL;
		}

		/**
		 * @brief Function for moving set north by one
		 */
		inline constexpr uint64_t move_north(uint64_t bb) { return bb << 8; }

		/**
		 * @brief Function for moving set north east by one
		 */
		inline constexpr uint64_t move_north_east(uint64_t bb) { return (bb & constants::NOT_H_FILE) << 9; }

		/**
		 * @brief Function for moving set east by one
		 */
		inline constexpr uint64_t move_east(uint64_t bb) { return (bb & constants::NOT_H_FILE) << 1; }

		/**
		 * @brief Function for moving set south east by one
		 */
		inline constexpr uint64_t move_south_east(uint64_t bb) { return (bb & constants::NOT_H_FILE) >> 7; }

		/**
		 * @brief Function for moving set south by one
		 */
		inline constexpr uint64_t move_south(uint64_t bb) { return bb >> 8; }

		/**
		 * @brief Function for moving set south west by one
		 */
		inline constexpr uint64_t move_south_west(uint64_t bb) { return (bb & constants::NOT_A_FILE) >> 9; }

		/**
		 * @brief Function for moving set west by one
		 */
		inline constexpr uint64_t move_west(uint64_t bb) { return (bb & constants::NOT_A_FILE) >> 1; }

		/**
		 * @brief Function for moving set north west by one
		 */
		inline constexpr uint64_t move_north_west(uint64_t bb) { return (bb & constants::NOT_A_FILE) << 7; }

	}
}