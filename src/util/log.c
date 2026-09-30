#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include "log.h"
#include "colors.h"

static const char* _level_color(LogLevel level)
{
	switch (level)
	{
		case LOG_LEVEL_TRACE: return COLOR_BLUE;
		case LOG_LEVEL_DEBUG: return COLOR_CYAN;
		case LOG_LEVEL_INFO:  return COLOR_GREEN;
		case LOG_LEVEL_WARN:  return COLOR_YELLOW;
		case LOG_LEVEL_ERROR: return COLOR_RED;
		case LOG_LEVEL_FATAL: return COLOR_BOLD_RED;
		default:
			break;
	}

	return COLOR_RESET;
}

static const char* _level_str(LogLevel level)
{
	switch (level)
	{
		case LOG_LEVEL_TRACE: return "TRACE";
		case LOG_LEVEL_DEBUG: return "DEBUG";
		case LOG_LEVEL_INFO:  return "INFO";
		case LOG_LEVEL_WARN:  return "WARN";
		case LOG_LEVEL_ERROR: return "ERROR";
		case LOG_LEVEL_FATAL: return "FATAL";
	}

	return "MISC";
}

void log(LogLevel level,
	const char* file,
	int line,
	const char* fmt, ...)
{
	time_t now = time(NULL);
	struct tm* tm = localtime(&now);

	char time_buf[16];
	strftime(time_buf, sizeof(time_buf), "%H:%M:%S", tm);

	FILE* out = level >= LOG_LEVEL_ERROR ? stderr : stdout;

	fprintf(out, "%s%s %s%-5s %s%s:%d %s",
		COLOR_GRAY, time_buf,
		_level_color(level), _level_str(level),
		COLOR_GRAY, file, line,
		COLOR_RESET
	);

	va_list args;
	va_start(args, fmt);
	vfprintf(out, fmt, args);
	va_end(args);

	fputs(COLOR_RESET "\n", out);
}