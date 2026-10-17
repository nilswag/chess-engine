#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include "log.h"

static void timestamp(char* buf, size_t buf_size)
{
    if (buf_size < sizeof(char) * 9) return;
    time_t t = time(NULL);
    struct tm* c = localtime(&t);
    sprintf(buf, "%02d:%02d:%02d", c->tm_hour, c->tm_min, c->tm_sec);
}

void log_out(LogLevel level, const char* file, int line, const char* fmt, ...)
{
    if (level < 0 || level >= LOG_LEVEL_N) return;

    static const char* prefixes[] = { "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL" };
    FILE* out = level < LOG_LEVEL_ERROR ? stdout : stderr;

    char buf[9];
    timestamp(buf, sizeof(buf));
    fprintf(out, "%s %s:%-3d %-5s ", buf, file, line, prefixes[level]);

    va_list args;
    va_start(args, fmt);
    vfprintf(out, fmt, args);
    va_end(args);

    fputc('\n', out);
}