#include <string.h>

#include "board.h"

void load_fen(Position* pos, const char* fen_str)
{

    for (u64 i = 0; i < strlen(fen_str); i++)
    {
        char c = fen_str[i];
        switch (c)
        {
            case 'P': break;
            case 'N': break;
            case 'B': break;
            case 'R': break;
            case 'Q': break;
            case 'K': break;

            case 'p': break;
            case 'n': break;
            case 'b': break;
            case 'r': break;
            case 'q': break;
            case 'k': break;
        }
    }   
}