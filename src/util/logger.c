#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lce/util/logger.h"

static const char* prefixes[6] = 
{
    "FATAL: ",
    "ERORR: ",
    "WARN: ",
    "INFO: ",
    "DEBUG: ",
    "TRACE: "
};

void lce_logger_output(LCELogLevel level, const char* file, int line, const char* message, ...)
{
    if (level < 0 || level >= 6) return;
    FILE* out = level < LCE_LOG_LEVEL_WARNING ? stderr : stdout;

    fprintf(out, "%s:%d ", file, line);
    fputs(prefixes[level], out);

    va_list args;
    va_start(args, message);
    vfprintf(out, message, args);
    va_end(args);

    fputc('\n', out);

    if (level == LCE_LOG_LEVEL_FATAL) abort();
}