#include<iostream>

#include "Bishop.h"

Bishop::Bishop()
{
    //ctor
}

bool Bishop::bishop_move(std::string piece, int col, int row, int diff_col, int diff_row)
{
    if   (col>0 && col<9 && row<8 && row>0)
    {  //std::cout << "\n\t\t\t Check-row     " << diff_row; // Using these cout to track the movements  checking variables
       //std::cout << "\n\t\t\t Check- col    " << diff_col;

    if (   (diff_row == diff_col ) ||  (diff_col== -diff_row)   ||     (diff_row == -diff_col)  )
            return true;
        else
            return false;
    }
}

bool Bishop::bishop_check_blocking( std::string s[9][9], int initial_row, int row, int initial_col, int col)
{
    //std::cout << "\n Bishop check blocking ;";
   // std::cout << " \tinitial row:  " << initial_row;  // Using these cout to track the movements  checking variables
    //std::cout << " \tinitial col:  " << initial_col;

    if (row>initial_row&&col>initial_col)
    {
        initial_row++;
        initial_col++;
        while(row>initial_row&&col>initial_col)
        {
            if (s[initial_row][initial_col]!= "[ ]" )
            {
                std::cout<<"\n\t *******invalid move###########\n ";
                return false;
            }
            initial_row++;
            initial_col++;
        }

    }

    if (row>initial_row&&col<initial_col)
    {
        initial_row++;
        initial_col--;
        while(row>initial_row&&col<initial_col)
        {
            if (s[initial_row][initial_col]!= "[ ]" )
            {
                 std::cout<<"\n\t THERE IS A PIECE IN YOUR PATH, CAN'T JUMP: \n";
                return false;
            }
            initial_row++;
            initial_col--;
        }

    }

    if (row<initial_row&&col>initial_col)
    {
        initial_row--;
        initial_col++;
        while(row<initial_row&&col>initial_col)
        {
            if (s[initial_row][initial_col]!= "[ ]" )
            {
                 std::cout<<"\n\t THERE IS A PIECE IN YOUR PATH, CAN'T JUMP: \n";
                return false;
            }
            initial_row--;
            initial_col++;
        }

    }
    //////
    if (row<initial_row&&col<initial_col)
    {
        initial_row--;
        initial_col--;
        while(row<initial_row&&col<initial_col)
        {
            if (s[initial_row][initial_col]!= "[ ]" )
            {
                 std::cout<<"\n\t THERE IS A PIECE IN YOUR PATH, CAN'T JUMP: \n";
                return false;
            }
            initial_row--;
            initial_col--;
        }

    }
    return true;


}
