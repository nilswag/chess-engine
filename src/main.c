#include "base/log.h"

int main(void)
{
    LOG_INFO("Hello %s!\n", "Info");
    LOG_WARN("Hello Warning!\n");
    LOG_ERROR("Hello Error!\n");
    return 0;
}