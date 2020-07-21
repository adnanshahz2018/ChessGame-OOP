#ifndef CHECK_KING_H
#define CHECK_KING_H

#include <iostream>
#include <string>

#include "chess_board.h"

class check_king
{

public:

check_king();

bool verify_check_white( std::string s[9][9], int , int );
bool verify_check_black( std::string s[9][9], int , int );
bool verify_check_near_black (std::string s[9][9], int , int  );
bool verify_check_near_white (std::string s[9][9], int , int  );
bool verify_check_knight_black (std::string s[9][9], int , int  );
bool verify_check_knight_white (std::string s[9][9], int , int  );


};

#endif // CHECK_KING_H
