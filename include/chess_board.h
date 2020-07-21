#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "knight.h"
#include "pawn.h"
#include "Queen.h"
#include "Bishop.h"
#include "king.h"
#include "Rook.h"
#include "check_king.h"

class chess_board
{
public:
chess_board();

void display();
void piece_selector(std::string, int row, char col);
bool verify_move( std::string , int , int );
bool moves( bool, bool , std::string, int , char);
void check_blocking_helper(std::string);
bool checkmate();
bool verify_check( std::string, bool , bool);

private:
    void init_game();
    int initial_col;
    int initial_row;


};

#endif // CHESS_BOARD_H
