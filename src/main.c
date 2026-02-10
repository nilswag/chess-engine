#include "base/log.h"

int main(void)
{
    LOG_INFO("%s\n", "Hello INFO");
    LOG_WARN("%s\n", "Hello WARNING");
    LOG_ERROR("%s\n", "Hello ERROR");

    return 0;
}