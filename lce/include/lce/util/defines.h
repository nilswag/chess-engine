#pragma once
#include <string.h>

#define STMT(s) do { s } while (0)

typedef enum LCEError
{
    LCE_OK = 0,
    LCE_ERROR_NULL_POINTER,
    LCE_ERROR_INVALID_ARGUMENT,
    LCE_ERROR_OUT_OF_BOUNDS,
    LCE_ERROR_FEN_PARSE
} LCEError;