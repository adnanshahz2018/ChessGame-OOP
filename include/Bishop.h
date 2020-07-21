#ifndef BISHOP_H
#define BISHOP_H


class Bishop
{
    public:
        Bishop();

bool bishop_move(std::string, int , int , int , int);
bool bishop_check_blocking(std::string s[9][9], int , int, int , int );

};

#endif // BISHOP_H
