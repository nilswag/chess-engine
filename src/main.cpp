
#include "lce/util/logger.h"

int main()
{
    logger::output(logger::LogLevel::INFO, "Hello World!", 1, 2, 3);
    return 0;
}