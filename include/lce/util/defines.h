#pragma once
#include <string.h>

#define LCE_FILE (strncmp(__FILE__, ROOT_DIR, sizeof(ROOT_DIR) - 1) == 0 ? __FILE__ + sizeof(ROOT_DIR) - 1 : __FILE__)
#define STMT(s) do { s } while (0)