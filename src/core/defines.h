#pragma once

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

enum class Direction : uint8_t
{
	NorthWest = 7, North = 8, NorthEast = 9,
	West = -1, East = 1,
	SouthWest = -9, South = -8, SouthEast = -7
};

/**
 * @brief Shorthand for std::to_underlying
 */
template <typename E>
inline constexpr auto tul(E e)
{
	return std::to_underlying(e);
}