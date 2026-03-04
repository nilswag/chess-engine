#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "lce/util/logger.h"

void lce_logger_output(LCELogLevel level, const char* file, int line, const char* func, const char* message, ...)
{
    if (level < 0 || level >= 6) return;
    FILE* out = level < LCE_LOG_LEVEL_WARNING ? stderr : stdout;

    static const char* prefix[6] = 
    {
        "FATAL",
        "ERROR",
        "WARN ",
        "INFO ",
        "DEBUG",
        "TRACE"
    };

    const char* color = LCE_LOG_COLOR_RESET;
    switch (level)
    {
        case LCE_LOG_LEVEL_FATAL:
        case LCE_LOG_LEVEL_ERROR:
            color = LCE_LOG_COLOR_RED;
            break;
        case LCE_LOG_LEVEL_WARNING:
            color = LCE_LOG_COLOR_YELLOW;
            break;
        case LCE_LOG_LEVEL_INFO:
            color = LCE_LOG_COLOR_WHITE;
            break;
        case LCE_LOG_LEVEL_DEBUG:
            color = LCE_LOG_COLOR_BLUE;
            break;
        case LCE_LOG_LEVEL_TRACE:
            color = LCE_LOG_COLOR_CYAN;
            break;
    }

    // timestamp
    time_t now = time(NULL);
    struct tm t;
    localtime_s(&t, &now);
    char timebuf[9]; // buffer for time string (max. should be 8 bytes +1 for null terminator)
    strftime(timebuf, sizeof(timebuf), "%H:%M:%S", &t);

    // header
    fprintf(out, "%s[%s][%s][%s:%d][%s] ", color, prefix[level], timebuf, strrchr(file, '/') + 1, line, func);

    // message
    va_list args;
    va_start(args, message);
    vfprintf(out, message, args);
    va_end(args);

    // footer
    fprintf(out, "%s\n", LCE_LOG_COLOR_RESET);

    if (level == LCE_LOG_LEVEL_FATAL) exit(EXIT_FAILURE);
}