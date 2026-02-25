#pragma once
#include <string>

namespace logger
{

    enum LogLevel 
    {
        FATAL,
        ERROR,
        WARNING,
        INFO,
        DEBUG,
        TRACE
    };

    template<typename... Args>
    inline void output(LogLevel level, std::string& message, Args... args)
    {
        
    }

}

#define LCE_FATAL
#define LCE_ERROR
#define LCE_WARN
#define LCE_INFO
#define LCE_DEBUG
#define LCE_TRACE