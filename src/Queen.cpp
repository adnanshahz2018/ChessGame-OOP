#include <iostream>
#include <string>

#include "Queen.h"

Queen::Queen()
{

}


bool Queen::Queen_move(std::string piece, int col, int row, int diff_col, int diff_row)
{

if  ( (col>0 && col<9 && row<8 && row>0)  ) // keeping the piece in the board
  {                                          // copied from rook

    if ( col < 8 && diff_row==0 && diff_col < 8 ) // if col is in the range of 8 and in the same row
        return true;
    else if ( row < 8 && diff_col==0 && diff_row < 8) // if row is in the range of 8 and in the same col
        return true; // Copied from king and modified
    else if (   (col>0 && col<9 && row<8)  &&    (diff_row == diff_col )  ) // checking diagonally
        return true;
    else if (   (diff_col== -diff_row)   ||     (diff_row == -diff_col)   ) // checking diagonally
        return true;
    else if ( diff_row==1 && (diff_col==1 || diff_col==-1) ) // checking 1 step to any diagonal
        return true;
    else
        return false;
  }
}

bool Queen::Queen_check_blocking_r(std::string s[9][9], int initial_row , int row, int initial_col , int col )
{
    bool green;

           // std::cout << " \n\t\t in the QQQQ  IF CONDITION OF THE ROOOKKKK\n";
            Rook R;
            green = R.rook_check_blocking( s,  initial_row,  row,  initial_col,  col);

        return green;
}

bool Queen::Queen_check_blocking_b(std::string s[9][9], int initial_row , int row, int initial_col , int col )
{
        bool green;
         Bishop B;
            //std::cout << " \n\t\t in the QQQQ IF CONDITION OF THE BISHOPPPP\n";
            green =  B.bishop_check_blocking( s, initial_row,  row, initial_col,  col);

            return green;
}
