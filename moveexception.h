#ifndef MOVEEXCEPTION_H
#define MOVEEXCEPTION_H
#include<stdexcept>

class MoveException : public std::runtime_error
{
public:
    MoveException(unsigned short x,unsigned short y);
private:
    unsigned short x,y;
};

#endif // MOVEEXCEPTION_H
