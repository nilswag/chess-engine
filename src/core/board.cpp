#include <string>
#include <cstdint>
#include <spdlog/spdlog.h>
#include "defines.h"
#include "board.h"

namespace lce
{
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

			case 'P': pieces[tul(bb::Color::White)][tul(bb::Piece::Pawn)] |= val; break;
			case 'N': pieces[tul(bb::Color::White)][tul(bb::Piece::Knight)] |= val; break;
			case 'B': pieces[tul(bb::Color::White)][tul(bb::Piece::Bishop)] |= val; break;
			case 'R': pieces[tul(bb::Color::White)][tul(bb::Piece::Rook)] |= val; break;
			case 'Q': pieces[tul(bb::Color::White)][tul(bb::Piece::Queen)] |= val; break;
			case 'K': pieces[tul(bb::Color::White)][tul(bb::Piece::King)] |= val; break;

			default:
				break;
			}

			if (isdigit(c))
				index += c - '0';
			else
				index++;
		}
		it++;

		for (int i = 0; i < tul(bb::Color::Count); i++)
		{
			for (int j = 0; j < tul(bb::Piece::Count); j++)
			{
				occupancy[i] |= pieces[i][j];
			}
		}
		occupied = occupancy[0] | occupancy[1];
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

		spdlog::debug("Parsed FEN str: {}", fen_str);
	}

	std::string Board::to_string() const
	{
		std::string s;

		for (int i = 63; i >= 0; i--)
		{
			if (i % 8 == 7)
				s += std::to_string(i / 8 + 1) + "| ";

			char c = '.';

			for (int color = 0; color < tul(bb::Color::Count); color++)
			{
				
				for (int piece = 0; piece < tul(bb::Piece::Count); piece++)
				{
					if (pieces[color][piece] & (1ULL << i))
						c = "PNBRQK"[piece] + (color ? 0 : 32);
				}
			}

			s += c;
			s += ' ';

			if (i % 8 == 0)
				s += '\n';
		}

		s += "   a b c d e f g h";
		return s;
	}

	uint64_t Board::get_bb(bb::Color color, bb::Piece piece) const
	{
		return pieces[tul(color)][tul(piece)];
	}

	std::string bb_to_string(uint64_t board)
	{
		std::string s;
		
		for (int i = 63; i >= 0; i--)
		{
			if (i % 8 == 7)
				s += std::to_string(i / 8 + 1) + "| ";

			char c = '.';
			if (board & (1ULL << i))
				c = '#';

			s += c;
			s += ' ';

			if (i % 8 == 0)
				s += '\n';
		}

		s += "  a b c d e f g h";
		return s;
	}

}