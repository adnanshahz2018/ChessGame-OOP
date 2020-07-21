#ifndef QUEEN_H
#define QUEEN_H

#include "chess_board.h"
#include "Bishop.h"
#include "Rook.h"
class Queen
{
    public:
        Queen();

bool Queen_move(std::string, int , int, int ,int);
bool Queen_check_blocking_r(std::string s[9][9], int , int, int , int );
bool Queen_check_blocking_b(std::string s[9][9], int , int, int , int );
    private:
        int diff_rows;
        int diff_columns;

};

#endif // QUEEN_H
