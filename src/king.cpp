#include<iostream>

#include "king.h"

king::king()
{
    //ctor
}


bool king::king_move(std::string piece, int col, int row, int diff_col, int diff_row)
    {
        if (col>0 && col<9 && row<8 && row>0) // keeping the piece in the board
        {
                if ( diff_row==0 && (diff_col==-1 || diff_col== 1)  ) // agr col men 1/-1 ka difference ho and row men 0 ka to LEGAL MOVe
                    return true;
                else if ( (diff_row==-1 || diff_row==1) && diff_col == 0 ) // agr row men 1/-1 ka difference ho and col men 0 ka to LEGAL MOVe
                    return true;
                else if ( (diff_col==1 ) && (diff_row==1 ||  diff_row==-1)  )
                    return true;
                else if ( diff_row==1 && (diff_col==1 || diff_col==-1) )
                    return true;
                else if ( diff_row==-1 &&  diff_col==-1 )
                    return true;
                else if ( diff_row==1 && diff_col==-1 )
                    return true;
                else
                    return false;
        }

    }
