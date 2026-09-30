#pragma once
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef enum 
{
	LOG_LEVEL_TRACE = 0,
	LOG_LEVEL_DEBUG,
	LOG_LEVEL_INFO,
	LOG_LEVEL_WARN,
	LOG_LEVEL_ERROR,
	LOG_LEVEL_FATAL,
	LOG_LEVEL_N
} LogLevel;

void log(LogLevel level, 
		 const char* file, 
		 int line, 
		 const char* fmt, ...);

#ifdef _WIN32
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#define TRACE(...) log(LOG_LEVEL_TRACE, __FILENAME__, __LINE__, __VA_ARGS__)
#define DEBUG(...) log(LOG_LEVEL_DEBUG, __FILENAME__, __LINE__, __VA_ARGS__)
#define INFO(...)  log(LOG_LEVEL_INFO, __FILENAME__, __LINE__, __VA_ARGS__)
#define WARN(...)  log(LOG_LEVEL_WARN, __FILENAME__, __LINE__, __VA_ARGS__)
#define ERROR(...) log(LOG_LEVEL_ERROR, __FILENAME__, __LINE__, __VA_ARGS__)
#define FATAL(...) do { log(LOG_LEVEL_FATAL, __FILENAME__, __LINE__, __VA_ARGS__); abort(); } while (false)