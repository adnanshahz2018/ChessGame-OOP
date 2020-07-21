#ifndef PAWN_H
#define PAWN_H

#include "chess_board.h"
class pawn
{
public:
    pawn();

bool pawn_check_white(std::string s[9][9], int, int, int, int );
bool pawn_check_black(std::string s[9][9] ,int, int, int, int );

};

#endif // PAWN_H
