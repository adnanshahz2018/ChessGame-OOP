#include <iostream>
#include <string>

#include "knight.h"

using namespace std;

bool knight::knight_check( int col, int row, int diff_col, int diff_row)
{

    if (col>0 && col<9 && row<8 && row>0) // keeping in the board
    {

        if ( (diff_row == 2 && diff_col==1) || (diff_row ==2 && diff_col ==-1) )
            return true;
        else if ( (diff_row ==-2 && diff_col==1) || (diff_row ==-2 && diff_col==-1) )
            return true;
        else if ( (diff_row == 1 && diff_col==2) || (diff_row == -1 && diff_col==2) )
            return true;
        else if ( (diff_row ==1 && diff_col==-2) || (diff_row ==-1 && diff_col==-2) )
            return true;
        else
            return false;
    }
}

