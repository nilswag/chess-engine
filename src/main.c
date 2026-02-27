#include "lce/util/logger.h"

int main(void)
{
    LCE_TRACE("trace message");
    LCE_DEBUG("debug message");
    LCE_INFO("info message");
    LCE_WARN("warning message");
    LCE_ERROR("error message");
    LCE_FATAL("boom");
    return 0;
}