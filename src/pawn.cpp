
#include <iostream>
#include <string>

#include "pawn.h"
#include "chess_board.h"

using namespace std;

pawn::pawn()
{

}


bool pawn::pawn_check_white(std::string s[9][9], int col, int row, int diff_col, int diff_row)
{
    //cout << "\n pawn_check_white  \n"<< piece;
   if (col>0 && col<9 && row<8 && row>0)
    {
        if (diff_row< 2 && diff_col==0 && diff_row > 0 )
            return true;
        else if ( ( diff_row == 1 || diff_row == -1) && ( diff_col == 1 || diff_col == -1)  &&  s[row][col].substr(0,1)== "b" )
            return true;
        else
            return false;

    }

}


bool pawn::pawn_check_black(std::string s[9][9], int col, int row, int diff_col, int diff_row)
{
    if (col>0 && col<9 && row<8 && row>0)
    {
        if (diff_row > -2 && diff_col==0 && diff_row < 0 )
            return true;
        else if ( ( diff_row == 1 || diff_row == -1) && ( diff_col == 1 || diff_col == -1)  &&  s[row][col].substr(0,1)== "w" )
            return true;
        else
            return false;
    }

     //cout << "\n pawn_check_black  \n"<< piece;



}

