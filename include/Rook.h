#ifndef ROOK_H
#define ROOK_H


class Rook
{
    public:
        Rook();

bool rook_move(std::string, int, int, int , int);
bool rook_check_blocking( std::string s[9][9], int , int, int , int );

};

#endif // ROOK_H
