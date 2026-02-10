#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "log.h"
#include "types.h"

void _log(LogLevel level, const char* fmt, ...)
{
    static const char* prefix[] = { "INFO", "WARN", "ERRO" };

    char buf[1024];
    i32 n = sprintf(buf, "%s %s: %s", __TIME__, prefix[level], fmt);
    if (n < 0) return; // don't do anything on formatting error

    va_list args;
    va_start(args, fmt);
    vfprintf(level == ERROR ? stderr : stdout, buf, args);
    va_end(args);
}