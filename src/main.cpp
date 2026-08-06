#include <spdlog/spdlog.h>
#include "core/board.h"

int main()
{
#ifdef _DEBUG
	spdlog::set_level(spdlog::level::trace);
#endif

	Board board(DEFAULT_POSITION);

	return 0;
}