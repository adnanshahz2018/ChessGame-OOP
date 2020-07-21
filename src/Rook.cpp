#include<iostream>
#include "Rook.h"

Rook::Rook()
{
    //ctor
}

bool Rook::rook_move(std::string piece, int col, int row, int diff_col, int diff_row)
{
    if (col>0 && col<9 && row<8 && row>0)
    {
        if ( ( col > 0 && col < 9 ) && diff_row==0 && diff_col < 9  ) // if col is in the range of 9 and in the same row
            return true;
        else if ( row < 8 && diff_col==0 && diff_row < 8) // if row is in the range of 8 and in the same col
            return true;
        else
            return false;
    }
}

bool Rook::rook_check_blocking( std::string s[9][9], int initial_row, int row, int initial_col, int col )
{
    bool green=true;
    // row = row , initial_row = initial-row,   col = col,   initial_col  = initial-col,
    int a = initial_row;
    int b = initial_col;

//std::cout << "\n   initial-col  " << initial_col;
//std::cout << "\n   col          " << col;
//std::cout << "\n   initial-row  " << initial_row;
//std::cout << "\n   row          " << row;

    if(col==initial_col && row!=initial_row)
    {

        if (initial_row<row)
        {
            initial_row++;

            for(; initial_row<row; initial_row++)
            {
                //std::cout << " \t 1st initial row:  " << initial_row;
                //std::cout << " \tinitial col:  " << initial_col;

                if (s[initial_row][col]!="[ ]")
                {
                    std::cout<<"\n\t THERE IS A PIECE IN YOUR PATH, CAN'T JUMP: \n";
                    return false;
                }
                else
                    green = true;
            }
        }
        initial_row=a;

        if(initial_row>row)
        {
            initial_row--;

            for(; initial_row>row; initial_row--)
            {
                //std::cout << " \t 2nd initial row:  " << initial_row;
                //std::cout << " \t initial col:  " << initial_col;

                if (s[initial_row][col]!="[ ]")
                {
                    std::cout<<"\n\t THERE IS A PIECE IN YOUR PATH, CAN'T JUMP: \n";
                    return false;
                }
                else
                    green = true;
            }

        }

    }

    initial_row=a;

    if(col!=initial_col && row==initial_row)
    {
        if (initial_col<col)
        {
            initial_col++;

            while( initial_col<=col)
            {
                //std::cout << " \t 2nd initial row:  " << initial_row;
                //std::cout << " \tinitial col:  " << initial_col;

                if (s[initial_row][initial_col]!="[ ]")
                {
                    std::cout<<"\n\t THERE IS A PIECE IN YOUR PATH, CAN'T JUMP: \n";
                    return false;
                }
                else
                    green = true;

                initial_col++;
            }
        }

        initial_col=b;

        if(initial_col>col)
        {
            initial_col--;
            for(; initial_col>=col; initial_col--)
            {
                //std::cout << " \t 4th initial row:  " << initial_row;
                //std::cout << " \tinitial col:  "      << initial_col;

                if (s[initial_row][initial_col]!="[ ]")
                {
                    std::cout<<"\n\t THERE IS A PIECE IN YOUR PATH, CAN'T JUMP: \n";
                    return false;
                }
                else
                    green = true;
            }
        }

    }

    return green;

}
