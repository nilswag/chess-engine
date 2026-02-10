#pragma once
#include "types.h"

typedef enum
{
    INFO,
    WARNING,
    ERROR,
    N_LEVELS
} LogLevel;

void _log(LogLevel level, const char* fmt, ...);

#define LOG_INFO(fmt, ...) STMT(_log(INFO, fmt, ##__VA_ARGS__);)
#define LOG_WARN(fmt, ...) STMT(_log(WARNING, fmt, ##__VA_ARGS__);)
#define LOG_ERROR(fmt, ...) STMT(_log(ERROR, fmt, ##__VA_ARGS__);)