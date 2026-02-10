#pragma once

typedef enum
{
    INFO,
    WARNING,
    ERROR,
    N_LEVELS
} LogLevel;

void _log(LogLevel level, const char* fmt, ...);