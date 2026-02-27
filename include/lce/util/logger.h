#pragma once

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