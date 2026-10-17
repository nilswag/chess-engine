#pragma once
#include <stdlib.h>

typedef enum
{
    LOG_LEVEL_TRACE = 0,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_FATAL,
    LOG_LEVEL_N
} LogLevel;

void log_out(LogLevel level, const char* file, int line, const char* fmt, ...);

#define TRACE(...) log_out(LOG_LEVEL_TRACE, __FILE_NAME__, __LINE__, __VA_ARGS__)
#define DEBUG(...) log_out(LOG_LEVEL_DEBUG, __FILE_NAME__, __LINE__, __VA_ARGS__)
#define INFO(...) log_out(LOG_LEVEL_INFO, __FILE_NAME__, __LINE__, __VA_ARGS__)
#define WARN(...) log_out(LOG_LEVEL_WARNING, __FILE_NAME__, __LINE__, __VA_ARGS__)
#define ERROR(...) log_out(LOG_LEVEL_ERROR, __FILE_NAME__, __LINE__, __VA_ARGS__)
#define FATAL(...) do { log_out(LOG_LEVEL_FATAL, __FILE_NAME__, __LINE__, __VA_ARGS__); exit(-1); } while (0)