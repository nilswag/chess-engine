#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include "log.h"
#include "ascii_colors.h"

static void timestamp(char* buf, size_t buf_size)
{
    if (buf_size < 9) return;
    time_t t = time(NULL);
    struct tm* c = localtime(&t);
    snprintf(buf, buf_size, "%02d:%02d:%02d", c->tm_hour, c->tm_min, c->tm_sec);
}

void log_out(LogLevel level, const char* file, int line, const char* fmt, ...)
{
    if (level < 0 || level >= LOG_LEVEL_N) return;

    static const char* prefixes[] = { "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL" };
    static const char* colors[] = { FG_CYAN, FG_BLUE, FG_WHITE, FG_YELLOW, FG_RED, BG_RED };
    FILE* out = level < LOG_LEVEL_ERROR ? stdout : stderr;

    char buf[9];
    timestamp(buf, sizeof(buf));
    fprintf(out, "%s%s %s:%-3d %s%-5s%s ",
        FG_GRAY, buf,
        file,
        line,
        colors[level], prefixes[level],
        COLOR_RESET
    );

    va_list args;
    va_start(args, fmt);
    vfprintf(out, fmt, args);
    va_end(args);

    fputc('\n', out);
}