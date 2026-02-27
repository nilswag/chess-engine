#pragma once

#define LCE_LOG_COLOR_BLACK   "\e[0;30m"
#define LCE_LOG_COLOR_RED     "\e[0;31m"
#define LCE_LOG_COLOR_GREEN   "\e[0;32m"
#define LCE_LOG_COLOR_YELLOW  "\e[0;33m"
#define LCE_LOG_COLOR_BLUE    "\e[0;34m"
#define LCE_LOG_COLOR_MAGENTA "\e[0;35m"
#define LCE_LOG_COLOR_CYAN    "\e[0;36m"
#define LCE_LOG_COLOR_WHITE   "\e[0;37m"
#define LCE_LOG_COLOR_RESET   "\e[0m"

typedef enum LCELogLevel
{
    LCE_LOG_LEVEL_FATAL,
    LCE_LOG_LEVEL_ERROR,
    LCE_LOG_LEVEL_WARNING,
    LCE_LOG_LEVEL_INFO,
    LCE_LOG_LEVEL_DEBUG,
    LCE_LOG_LEVEL_TRACE
} LCELogLevel;

void lce_logger_output(LCELogLevel level, const char* file, int line, const char* message, ...);

#define LCE_FATAL(...) lce_logger_output(LCE_LOG_LEVEL_FATAL, __FILE__, __LINE__, __VA_ARGS__)
#define LCE_ERROR(...) lce_logger_output(LCE_LOG_LEVEL_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define LCE_WARN(...)  lce_logger_output(LCE_LOG_LEVEL_WARNING, __FILE__, __LINE__, __VA_ARGS__)
#define LCE_INFO(...)  lce_logger_output(LCE_LOG_LEVEL_INFO, __FILE__, __LINE__, __VA_ARGS__)
#define LCE_DEBUG(...) lce_logger_output(LCE_LOG_LEVEL_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define LCE_TRACE(...) lce_logger_output(LCE_LOG_LEVEL_TRACE, __FILE__, __LINE__, __VA_ARGS__)