
#include <iostream>
#include <string>
#include "chess_board.h"

using namespace std;

string s [9][9];

string black_pawn1 = "bp1", black_pawn2 = "bp2", black_pawn3 = "bp3", black_pawn4 = "bp4",
       black_pawn5 = "bp5", black_pawn6 = "bp6", black_pawn7 = "bp7", black_pawn8 = "bp8",
       black_king  = "bk", black_queen = "bq",
       black_rook1 = "br1", black_bishop1 = "bb1",black_knight1 = "bn1",
       black_rook2 = "br2", black_bishop2 = "bb2",black_knight2 = "bn2",
       white_pawn1 = "wp1",  white_pawn2 = "wp2", white_pawn3 = "wp3", white_pawn4 = "wp4",
       white_pawn5 = "wp5",  white_pawn6 = "wp6", white_pawn7 = "wp7", white_pawn8 = "wp8",
       white_king  = "wk", white_queen = "wq",
       white_rook1 = "wr1", white_bishop1 = "wb1",white_knight1 = "wn1",
       white_rook2 = "wr2", white_bishop2 = "wb2", white_knight2 = "wn2"  ;


chess_board::chess_board()
{
    for (int i =0; i<9; i++)
    {
        for (int j =0; j<9; j++)
        {
            s[i][j]= "[ ]" ;
        }
    }
    init_game();
}

bool chess_board::verify_check( std::string piece, bool flag_white, bool flag_black)
{
    int king_row, king_col ;
    int king_row_white, king_col_white ;
    check_king k;
    bool check=false;

    if (flag_white == true || flag_black == true)
    {
        for (int i =0; i<9; i++)
        {
            for (int j =0; j<9; j++)
            {
                if ( s[i][j] == "bk" )
                {
                    king_row = i;
                  //  cout << "\nking row " << king_row;
                    king_col = j;
                   // cout << "\nking col " << king_col;
                }

            }

        }

            k.verify_check_black(s, king_row, king_col);
            k.verify_check_near_black(s, king_row, king_col);
            k.verify_check_knight_black(s, king_row, king_col);



    }

    if (flag_white == true || flag_black == true )
    {
        for (int i =0; i<9; i++)
        {
            for (int j =0; j<9; j++)
            {
                if ( s[i][j] == "wk" )
                {
                    king_row_white = i;
                    king_col_white = j;
                }

            }

        }
            k.verify_check_white( s, king_row, king_col);
            k.verify_check_near_white(s, king_row_white, king_col_white);
            k.verify_check_knight_white(s, king_row_white, king_col_white);
    }

   return check;
}

void chess_board::display() // showing the 2D chess on the Console
{
    for (int i =0; i<9; i++)
    {
        cout << endl<<endl;
        for (int j =0; j<9; j++)
        {
            cout <<"\t"<< s[i][j] ;
        }

    } cout << endl;

}


void chess_board::check_blocking_helper (std::string piece)
{
    for (int i =0; i<9; i++)
    {
        for (int j =0; j<9; j++)
        {
            if (s[i][j]== piece )
            {
                initial_row = i; // check if really i is the row
                initial_col = j;
            }
        }
    }
}

bool chess_board::verify_move(std::string piece, int row, int col) // checks whether the Move can be made or NOT
{
    //cout << "verify move : piece = " << piece;

    int diff_row, diff_col;
    int verify_row, verify_col;

    for (int i =0; i<9; i++)
    {
        for (int j =0; j<9; j++)
        {

            if (piece ==  s[i][j])
            {
                diff_row = i - row;
                diff_col = col - j;
            }
        }
    }

    if ( piece == white_pawn1 || piece == white_pawn2 || piece == white_pawn3 || piece == white_pawn4 ||
            piece == white_pawn5 || piece == white_pawn6 || piece == white_pawn7 || piece == white_pawn8 ||
            piece == black_pawn1 || piece == black_pawn2 || piece == black_pawn3 || piece == black_pawn4 ||
            piece == black_pawn5 || piece == black_pawn5 || piece == black_pawn7 || piece == black_pawn8  )
    {

        pawn p; // object of the pawn class
        bool green;

        if (  piece == black_pawn1 || piece == black_pawn2 || piece == black_pawn3 || piece == black_pawn4  ||
                piece == black_pawn5 || piece == black_pawn6 || piece == black_pawn7 || piece == black_pawn8  )
        {
            green = p.pawn_check_black(s, col, row, diff_col, diff_row);
            //cout << "\n \t\t watching green-black: " << green << endl;

        }
        else if ( piece == white_pawn1 || piece == white_pawn2 || piece == white_pawn3 || piece == white_pawn4 ||
                  piece == white_pawn5 || piece == white_pawn6 || piece == white_pawn7 || piece == white_pawn8    )
        {
            green = p.pawn_check_white( s, col, row, diff_col, diff_row);
            //cout << "\n \t\t watching green-white: " << green << endl;
        }

        return green;
    }


    if ( piece == black_knight1 || piece == white_knight1 || piece == white_knight2 || piece == black_knight2)
    {
        knight k2;
        bool green;
        green = k2.knight_check( col, row, diff_col, diff_row );
        return green;
    }

    if ( piece == black_king || piece == white_king)
    {
        king k;
        bool green;
        //cout << "\n row " << row;    // these cout are to check the input values of the functions
        //cout << "\n col " << col;
        //cout << "\n check row " << diff_row;
        //cout << "\n check col " << diff_col;

        green = k.king_move( piece, col, row, diff_col, diff_row );
        //cout << "\n watching green  "<< green << endl;
        return green;
    }

    if ( piece == black_bishop1 || piece == white_bishop1 ||  piece == black_bishop2 || piece == white_bishop2)
    {
        Bishop B;
        bool green;
        green = B.bishop_move( piece, col, row, diff_col, diff_row );

        check_blocking_helper(piece);

        if ( green == true )
            green = B.bishop_check_blocking(s, initial_row, row, initial_col, col);
        return green;
    }

    if ( piece == black_rook1 || piece == white_rook1 || piece == black_rook2 || piece == white_rook2)
    {
        Rook R;
        bool green;
        green = R.rook_move( piece, col, row, diff_col, diff_row );

        check_blocking_helper(piece);

        if ( green == true)
            green = R.rook_check_blocking( s, initial_row, row, initial_col, col );
        return green;

    }

    if ( piece == black_queen || piece == white_queen)
    {
        Queen Q;
        bool green;
        green = Q.Queen_move( piece, col, row, diff_col, diff_row );

        check_blocking_helper(piece);
        //std::cout << "\n  check- col  " << diff_col;  // checking the value of variables
        //std::cout << "\n  check- row  " << diff_row;

        if( green == true && ( (diff_row==0 && diff_col < 9) ||  ( diff_col==0 && diff_row < 8 )  )    )
            green = Q.Queen_check_blocking_r( s, initial_row, row, initial_col, col );

        else if( green == true && ( diff_col == diff_row || diff_col == -diff_row )  )
            green = Q.Queen_check_blocking_b( s, initial_row, row, initial_col, col );

        return green;
    }

}

bool chess_board::moves ( bool flag_white, bool flag_black, string piece, int row, char column ) // responds on the input value of the user for the movements
{
    bool shuffle;
    //cout << "\n\t\t inside moves :   "<< pawn << endl;

    int col;

    switch(column)
    {
    case 'h':
        col=8;
        break;
    case 'g':
        col=7;
        break;
    case 'f':
        col=6;
        break;
    case 'e':
        col=5;
        break;
    case 'd':
        col=4;
        break;
    case 'c':
        col=3;
        break;
    case 'b':
        col=2;
        break;
    case 'a':
        col=1;
        break;
    default:
        col=8;
        break;
    }

    shuffle = verify_move(piece, row, col);

    if (  shuffle  ) // Calling the verification function for the Desired Move..
    {
        bool flag_pawn=true;

        string swapz;
        for (int i =0; i<9; i++)
        {
            for (int j =0; j<9; j++)
            {
                //cout << j << " " << i << "  s[i][j] " << s[i][j]<<  endl;
                if ( piece == s[i][j])
                {
                     //cout << "\n \t\t\t  initial piece " << s[i][j].substr(0,2);
                     //cout << "\n \t\t\t  destination piece " << s[row][col].substr(0,2);
                    if ( s[i][j].substr(0,2) == "wp" || s[i][j].substr(0,2) == "bp" )
                    {
                        cout << "\n inside trouble: \n" ;

                    if ( s[i][j].substr(0,2) == "wp"  && ( s[i-1][j-1].substr(0,1) == "b" || s[i-1][j+1].substr(0,1) == "b" )  )
                        flag_pawn = true;
                    else if ( s[i][j].substr(0,2) == "bp"  && (s[i+1][j+1].substr(0,1) == "w" || s[i+1][j-1].substr(0,1) == "w" )  )
                        flag_pawn = true;
                    else
                        flag_pawn = false;
                    }

                    if ( s[row][col]== "[ ]"  ) // checking if the Destination place is an empty location
                    {
                        //cout << "\t \t\t LEGAL MOVE    \n";
                        swapz = s[row][col];
                        s[row][col] =  s [i][j];
                        s[i][j] = swapz;
                        display();
                        return true;
                        break;

                    }


                    else if ( flag_white==true && flag_black == false && s[row][col].substr(0,1)== "b" )
                    {
                        if ( flag_pawn )
                        {

                            cout << endl<< s[i][j] << "\t has killed the\t " << s[row][col];
                            s[row][col] = s[i][j];
                            s[i][j] = "[ ]";
                            display();
                            return true;
                        }
                        else
                            {
                                cout << "\n \t\t ****PAWN can NOT kILL Straight \n ";
                                return false;
                            }

                    }

                    else if ( flag_white==false && flag_black == true && s[row][col].substr(0,1)== "w" )
                    {
                        if ( flag_pawn  )
                        {
                            cout << endl<< s[i][j] << "\t has killed the\t " << s[row][col];
                            s[row][col] = s[i][j];
                            s[i][j] = "[ ]";
                            display();

                            return true;
                        }
                        else
                            {
                                cout << "\n \t\t ****PAWN can NOT kILL Straight \n ";
                                return false;
                            }

                    }
                    else
                    {
                        display();
                        return false;
                    }

                }
            }

        }
        //cout << "\n S[row][col]   =    " << s[row][col] ;
        //cout << "\n Swapped by   =    " << s[i][j] << endl;
        display();

    }
     else
        cout << "\n\t SORRY THIS MOVE IS NOT VALID ";


return shuffle;

}



void chess_board::init_game() // placement of the pawns , knights, queen , rook, bishop, king
{

    s[0][1]="<a>";
    s[0][2]="<b>";
    s[0][3]="<c>";
    s[0][4]="<d>";
    s[0][5]="<e>";
    s[0][6]="<f>";
    s[0][7]="<g>";
    s[0][8]="<h>";
    s[1][0]="8";
    s[2][0]="7";
    s[3][0]="6";
    s[4][0]="5";
    s[5][0]="4";
    s[6][0]="3";
    s[7][0]="2";
    s[8][0]="1";
    s[0][0]="";

    s[1][1]=black_rook1;
    s[1][2]=black_knight1;
    s[1][3]=black_bishop1;
    s[1][4]=black_king;
    s[1][5]=black_queen;
    s[1][6]=black_bishop2;
    s[1][7]=black_knight2;
    s[1][8]=black_rook2;

    s[8][1]=white_rook1;
    s[8][2]=white_knight1;
    s[8][3]=white_bishop1;
    s[8][4]=white_king;
    s[8][5]=white_queen;
    s[8][6]=white_bishop2;
    s[8][7]=white_knight2;
    s[8][8]=white_rook2;
    s[1][0]="1";
    s[2][0]="2";
    s[3][0]="3";
    s[4][0]="4";
    s[5][0]="5";
    s[6][0]="6";
    s[7][0]="7";
    s[8][0]="8";
    s[0][0]="";
    s[7][1]= white_pawn1;
    s[7][2]= white_pawn2;
    s[7][3]= white_pawn3;
    s[7][4]= white_pawn4;
    s[7][5]= white_pawn5;
    s[7][6]= white_pawn6;
    s[7][7]= white_pawn7;
    s[7][8]= white_pawn8;
    ///////////////////////////////////////
    s[2][1]= black_pawn1;
    s[2][2]= black_pawn2;
    s[2][3]= black_pawn3;
    s[2][4]= black_pawn4;
    s[2][5]= black_pawn5;
    s[2][6]= black_pawn6;
    s[2][7]= black_pawn7;
    s[2][8]= black_pawn8;

}




