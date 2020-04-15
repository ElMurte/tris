#include "moveexception.h"



MoveException::MoveException(unsigned short X,unsigned short Y)
    : std::runtime_error(std::runtime_error("Exception ("+ std::to_string(x) + "," + std::to_string(y)+") can not be done")),x(X),y(Y)
{

}

