#pragma once
#include <string.h>

#define STMT(s) do { s } while (0)

typedef enum LCEError
{
    LCE_OK = 0,
    LCE_ERR_FEN_PARSE
} LCEError;