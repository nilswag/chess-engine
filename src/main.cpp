#include <spdlog/spdlog.h>
#include "core/board.h"

int main()
{
#ifdef _DEBUG
	spdlog::set_level(spdlog::level::trace);
#endif
	Board board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
	return 0;
}