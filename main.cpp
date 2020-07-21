// Adnan Shah
// 1602004

#include <iostream>
#include <string>

#include "knight.h"
#include "chess_board.h"

using namespace std;

int main()
{
    cout << "\n\t \t Welcome to the Chess Game";

    int row, control=1;
    char col;
    string piece;
    bool flag_white, flag_black, next, check;

    chess_board board;
    board.display();
    cout << endl << endl;

    while (true)
    {
        if ( control%2 == 0 ) // I selected even number  for black
        {
            // cout << "\n watching control   " << control;
            cout << "\n\n\t\t\t ###### B L A C K  T U R N  ###### \n";
            flag_white = false;
            flag_black = true;
        }
        else
        {
            cout << "\n\t\t\t |||||||||  WHITE TURN |||||||||| \n";
            flag_white = true;
            flag_black = false;
        }

        cout << "\n\n Choose Chess_Piece\t" ;
        cin >> piece;

        // this if condition is checking the valid turn of the black or white
        if ( ( flag_white==true && flag_black==false && piece.substr(0,1)=="w" ) ||
             ( flag_white==false && flag_black==true && piece.substr(0,1)=="b" ) )
        {
            cout << " Destination Col [a-h]    ";
            cin >> col;
            cout << " Destination ROW [1-8]    ";
            cin >> row;

            //cout << "\n   First letter   " << piece.substr(0,1);
            next = board.moves( flag_white, flag_black, piece, row, col);
            check = board.verify_check(piece, flag_white, flag_black);
            //cout << " \n watching next   " << next ;
        }
        else
            next = false;
        //cout << " \n watching next   " << next ;
        if ( next == true )
            control++;


    }


    return 0;
}
