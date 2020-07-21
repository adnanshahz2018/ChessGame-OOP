#include "check_king.h"

#include <iostream>
#include <string>


check_king::check_king()
{
    //ctor
}

bool check_king::verify_check_knight_black (std::string s[9][9], int r, int c )
{
    std::string piece = "wn" ;

    if (   c>0 && r<7 &&  (s[r+2][c-1].substr(0,2)== piece || s[r+2][c-1].substr(0,2)== piece)   )
    {
        std::cout << "\n \t 1*WHITE KING HAS BEEN CHECKED BY BLACK KNIGHT\n";
        return true;
    }
    else if ( c>0 && r>1 && (s[r-2][c+1].substr(0,2)== piece || s[r-2][c-1].substr(0,2)== piece)   )
    {
        std::cout << "\n \t 2*WHITE KING HAS BEEN CHECKED BY BLACK KNIGHT\n";
        return true;
    }
    else if (   r>0 && c >1 && (s[r+1][c+2].substr(0,2)== piece ) || ( r>0 && s[r-1][c+2].substr(0,2)== piece)   )
    {
        std::cout << "\n \t 3*WHITE KING HAS BEEN CHECKED BY BLACK KNIGHT\n";
        return true;
    }
    else if (  c>1 && r>0 && (s[r+1][c-2].substr(0,2)== piece || s[r-1][c-2].substr(0,2)== piece)   )
    {
        std::cout << "\n \t 4*WHITE KING HAS BEEN CHECKED BY BLACK KNIGHT\n";
        return true;
    }
    else if (  r>1 && c > 0 && s[r+2][c+1].substr(0,2)== piece )
    {
        std::cout << "\n \t 5*WHITE KING HAS BEEN CHECKED BY BLACK KNIGHT\n";
        return true;
    }
    else
        return false;

    return true;
}

bool check_king::verify_check_near_black (std::string s[9][9], int r, int c )
{
    //std::cout << "\n  r  " << r  << "\t c  " << c << std::endl;

    if (  c>0 && ( s[r][c-1].substr(0,2) == "wq" || s[r][c-1].substr(0,2) == "wr"  || s[r][c-1].substr(0,2) == "wk") )
        std::cout << "\n 1****BLACK KING has been CHECKED by\t  "  << s[r][c-1].substr(0,3)  ;

    else if ( c<8 && ( s[r][c+1].substr(0,2) == "wq" ||s[r][c+1].substr(0,2) == "wr" || s[r][c+1].substr(0,2) == "wk" )  )
        std::cout << "\n 2****BLACK KING has been CHECKED by\t  "  << s[r][c+1].substr(0,3)  ;

    else if ( r<8 && c<8 && (s[r+1][c+1].substr(0,2) == "wq"  || s[r+1][c+1].substr(0,2) == "wb" || s[r+1][c+1].substr(0,2) == "wk" || s[r+1][c+1].substr(0,2) == "wp" )  )
        std::cout << "\n 3****BLACK KING has been CHECKED by\t  "  << s[r+1][c+1].substr(0,3)  ;

    else if ( c>0 && r>0 && ( s[r-1][c-1].substr(0,2) == "wq" || s[r-1][c-1].substr(0,2) == "wb" || s[r-1][c-1].substr(0,2) == "wk" || s[r-1][c-1].substr(0,2) == "wp")  )
        std::cout << "\n 4****BLACK KING has been CHECKED by\t  "  << s[r-1][c-1].substr(0,3) ;

    else if ( r>0 && (s[r-1][c].substr(0,2) == "wq" || s[r-1][c].substr(0,2) == "wr" || s[r-1][c].substr(0,2) == "wk" )  )
        std::cout << "\n ****BLACK KING has been CHECKED by\t  "  << s[r-1][c].substr(0,3) ;

    else if ( r<8 && c>0 && ( s[r+1][c-1].substr(0,2) == "wq" || s[r+1][c-1].substr(0,2) == "wb" || s[r+1][c-1].substr(0,2) == "wk" || s[r+1][c-1].substr(0,2) == "wp")  )
        std::cout << "\n 5****BLACK KING has been CHECKED by\t  "  << s[r+1][c-1].substr(0,3) ;

    else if ( c<8 && r>0 && (s[r-1][c+1].substr(0,2) == "wq" || s[r-1][c+1].substr(0,2) == "wb" || s[r-1][c+1].substr(0,2) == "wk" || s[r-1][c+1].substr(0,2) == "wp") )
        std::cout << "\n ****BLACK KING has been CHECKED by\t  "  << s[r-1][c+1].substr(0,3) ;

    else if (r<8 && ( s[r+1][c].substr(0,2) == "wq" || s[r+1][c].substr(0,2) == "wr" || s[r+1][c].substr(0,2) == "wk" )  )
        std::cout << "\n 6****BLACK KING has been CHECKED by\t  "  << s[r+1][c].substr(0,3);

    else
        std::cout ;

    return true;
}

bool check_king::verify_check_black (std::string s[9][9], int king_row, int king_col )
{
    int r = king_row;
    int c = king_col;
    bool green;

    for ( r = king_row+1 ; r < 8 ; r++)
    {
        c--;
        //std::std::cout << "\n piece " << s[r][c].substr(0,3) ;
        if ( s[r][c].substr(0,2) == "wb" || s[r][c].substr(0,2) == "wq" || s[r][c].substr(0,2) == "[ "  )
        {
            if (s[r][c].substr(0,2) == "wb" || s[r][c].substr(0,2) == "wq")
                std::cout << "\n ****BLACK KING have been CHECKED \t by  " << s[r][c]  ;
        }
        else if (c<=1)
            break;
        else
            break;

    }
    r = king_row;
    c = king_col;

    for ( r = king_row+1 ; r < 8 ; r++)
    {
        c++;
        //std::std::cout << "\n piece " << s[r][c].substr(0,3) ;
        if ( s[r][c].substr(0,2) == "wb" || s[r][c].substr(0,2) == "wq" || s[r][c].substr(0,2) == "[ "  )
        {
            if (s[r][c].substr(0,2) == "wb" || s[r][c].substr(0,2) == "wq")
                std::cout << "\n ****BLACK KING have the check \t by  " << s[r][c]  ;

        }
        else if (c>7)
            break;
        else
            break;

    }
    r = king_row;
    c = king_col;

    for ( r = king_row+1 ; r < 8 ; r++)
    {
        // std::std::cout << "\n piece " << s[r][c].substr(0,3) ;

        if ( s[r][c].substr(0,2) == "wr" || s[r][c].substr(0,2) == "wq" || s[r][c].substr(0,2) == "[ "  )
        {
            if (s[r][c].substr(0,2) == "wr" || s[r][c].substr(0,2) == "wq")
                std::cout << "\n****BLACK KING have the check\tby  " << s[r][c] ;
        }
        else
            break;

    }
    r = king_row;
    c = king_col;

    for ( c = king_col+1 ; c < 8 ; c++)
    {
        // std::std::cout << "\n piece " << s[r][c].substr(0,3) ;

        if ( s[r][c].substr(0,2) == "wr" || s[r][c].substr(0,2) == "wq" || s[r][c].substr(0,2) == "[ "  )
        {
            if (s[r][c].substr(0,2) == "wr" || s[r][c].substr(0,2) == "wq")
                std::cout << "\n ****BLACK KING have the check \t by  " << s[r][c]  ;
        }
        else
            break;

    }
    r = king_row;
    c = king_col;

    for ( c = king_col-1 ; c >0 ; c--)
    {
        // std::std::cout << "\n piece " << s[r][c].substr(0,3) ;

        if ( s[r][c].substr(0,2) == "wr" || s[r][c].substr(0,2) == "wq" || s[r][c].substr(0,2) == "[ "  )
        {
            if (s[r][c].substr(0,2) == "wr" || s[r][c].substr(0,2) == "wq")
                std::cout << "\n ****BLACK KING have the check \t by  " << s[r][c]  ;
        }
        else
            break;

    }

}


//////////////////////**************************************88/////////////////////////////////
//////////////////////**************************************88/////////////////////////////////


bool check_king::verify_check_white (std::string s[9][9], int king_row, int king_col )
{
    int r = king_row;
    int c = king_col;
    bool green;

    // std::cout << "\n  row "<< king_row;
    //std::cout << "   col "<< king_col;

    for ( r = king_row+1 ; r < 8 ; r++)
    {
        c--;
        //std::std::cout << "\n piece " << s[r][c].substr(0,3) ;
        if ( s[r][c].substr(0,2) == "bb" || s[r][c].substr(0,2) == "bq" || s[r][c].substr(0,2) == "[ "  )
        {
            if (s[r][c].substr(0,2) == "bb" || s[r][c].substr(0,2) == "bq")
                std::cout << "\n ****WHITE KING have been CHECKED \t by  " << s[r][c]  ;
        }
        else if (c<=1)
            break;
        else
            break;
    }
    c = king_col;

    for ( r = king_row+1 ; r < 8 ; r++)
    {
        c++;
        //std::std::cout << "\n piece " << s[r][c].substr(0,3) ;

        if ( s[r][c].substr(0,2) == "bb" || s[r][c].substr(0,2) == "bq" || s[r][c].substr(0,2) == "[ "  )
        {
            if (s[r][c].substr(0,2) == "bb" || s[r][c].substr(0,2) == "bq")
                std::cout << "\n ****WHITE KING have the check \t by  " << s[r][c]  ;

        }
        else if (c>7)
            break;
        else
            break;

    }
    c = king_col;

    for ( r = king_row+1 ; r < 8 ; r++)
    {
        // std::std::cout << "\n piece " << s[r][c].substr(0,3) ;

        if ( s[r][c].substr(0,2) == "br" || s[r][c].substr(0,2) == "bq" || s[r][c].substr(0,2) == "[ "  )
        {
            if (s[r][c].substr(0,2) == "br" || s[r][c].substr(0,2) == "bq")
                std::cout << "\n ****WHITE KING have the check \t by  " << s[r][c]  ;

        }
        else if (c>7)
            break;
        else
            break;

    }

}


bool check_king::verify_check_near_white (std::string s[9][9], int r, int c )
{
   // std::cout << "\n  r  " << r  << "\t c  " << c << std::endl;

    if (  c>0 && ( s[r][c-1].substr(0,2) == "bq" || s[r][c-1].substr(0,2) == "br"  || s[r][c-1].substr(0,2) == "bk") )
        std::cout << "\n 1****WHITE KING have been CHECKED by\t  "  << s[r][c-1].substr(0,3)  ;
    else if ( c<8 && ( s[r][c+1].substr(0,2) == "bq" ||s[r][c+1].substr(0,2) == "br" || s[r][c+1].substr(0,2) == "bk" )  )
        std::cout << "\n 2****WHITE KING have been CHECKED by\t  "  << s[r][c+1].substr(0,3)  ;
    else if ( r<8 && c<8 && (s[r+1][c+1].substr(0,2) == "bq"  || s[r+1][c+1].substr(0,2) == "bb" || s[r+1][c+1].substr(0,2) == "bk" || s[r+1][c+1].substr(0,2) == "bp" )  )
        std::cout << "\n 3****WHITE KING have been CHECKED by\t  "  << s[r+1][c+1].substr(0,3)  ;
    else if ( c>0 && r>0 && ( s[r-1][c-1].substr(0,2) == "bq" || s[r-1][c-1].substr(0,2) == "bb" || s[r-1][c-1].substr(0,2) == "bk" || s[r-1][c-1].substr(0,2) == "bp")  )
        std::cout << "\n 4****WHITE KING have been CHECKED by\t  "  << s[r-1][c-1].substr(0,3) ;
    else if ( r>0 && (s[r-1][c].substr(0,2) == "bq" || s[r-1][c].substr(0,2) == "br" || s[r-1][c].substr(0,2) == "bk" )  )
        std::cout << "\n ****WHITE KING have been CHECKED by\t  "  << s[r-1][c].substr(0,3) ;
    else if ( r<8 && c>0 && ( s[r+1][c-1].substr(0,2) == "bq" || s[r+1][c-1].substr(0,2) == "bb" || s[r+1][c-1].substr(0,2) == "bk" || s[r+1][c-1].substr(0,2) == "bp" )  )
        std::cout << "\n 5****WHITE KING have been CHECKED by\t  "  << s[r+1][c-1].substr(0,3) ;
    else if ( c<8 && r>0 && (s[r-1][c+1].substr(0,2) == "bq" || s[r-1][c+1].substr(0,2) == "bb" || s[r-1][c+1].substr(0,2) == "bk"  || s[r-1][c+1].substr(0,2) == "bp") )
        std::cout << "\n ****WHITE KING have been CHECKED by\t  "  << s[r-1][c+1].substr(0,3) ;
    else if (r<8 && ( s[r+1][c].substr(0,2) == "bq" || s[r+1][c].substr(0,2) == "br" || s[r+1][c].substr(0,2) == "bk" )  )
        std::cout << "\n 6****WHITE KING have been CHECKED by\t  "  << s[r+1][c].substr(0,3);
    else
        std::cout ;

    return true;
}

bool check_king::verify_check_knight_white (std::string s[9][9], int r, int c )
{
    std::string piece = "bn" ;
   // std::cout << "\n r  " << r << "\t   c  " << c ;

    if (   c>0 && r<7 &&  (s[r+2][c-1].substr(0,2)== piece || s[r+2][c-1].substr(0,2)== piece)   )
    {
        std::cout << "\n \t 1*WHITE KING HAS BEEN CHECKED BY BLACK KNIGHT\n";
        return true;
    }
    else if ( c>0 && r>1 && (s[r-2][c+1].substr(0,2)== piece || s[r-2][c-1].substr(0,2)== piece)   )
    {
        std::cout << "\n \t 2*WHITE KING HAS BEEN CHECKED BY BLACK KNIGHT\n";
        return true;
    }
    else if (   r>0 && c >1 && (s[r+1][c+2].substr(0,2)== piece ) || ( r>0 && s[r-1][c+2].substr(0,2)== piece)   )
    {
        std::cout << "\n \t 3*WHITE KING HAS BEEN CHECKED BY BLACK KNIGHT\n";
        return true;
    }
    else if (  c>1 && r>0 && (s[r+1][c-2].substr(0,2)== piece || s[r-1][c-2].substr(0,2)== piece)   )
    {
        std::cout << "\n \t 4*WHITE KING HAS BEEN CHECKED BY BLACK KNIGHT\n";
        return true;
    }
    else if (  r>1 && c > 0 && s[r+2][c+1].substr(0,2)== piece )
    {
        std::cout << "\n \t 5*WHITE KING HAS BEEN CHECKED BY BLACK KNIGHT\n";
        return true;
    }
    else
        return false;


    return true;
}




