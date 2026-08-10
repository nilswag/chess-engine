#include <spdlog/spdlog.h>
#include "core/board.h"
#include "generation/pawn.h"

int main()
{
#ifdef _DEBUG
	spdlog::set_level(spdlog::level::trace);
#endif
	lce::Board board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
	spdlog::info("\n{}\n", board.to_string());

	uint64_t set = board.get_bb(lce::bb::Color::White, lce::bb::Piece::Pawn);
	spdlog::info("\n{}\n", lce::bb_to_string(set));

	return 0;
}