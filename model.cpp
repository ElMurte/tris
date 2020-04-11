#include "model.h"

Model::Model(){
    reset();
}

bool Model::Move(unsigned short x, unsigned short y){
    //se esiste un vincitore nada  OR  outofbound or se la casella è occupata
    if (  x>2 || y>2 || winner() || (grid[x*3+y]!=none)) return false;
         grid[x*3+y]=(turn?player2:player1);
         turn=!turn;
         return true;
}

Player Model::winner() const{
    for(unsigned short i=0;i<3;i++){
        if(CheckWinner(i*3,i*3+1,i*3+2))
            return grid[i*3];
        if(CheckWinner(i,i+3,i+6))
            return grid[i];
    }
    //diagonali
    if(CheckWinner(0,4,8) || CheckWinner(2,4,6))
        return grid[4];
    return none;
}

void Model::reset(){
    turn=0;
    for(u_s_int i=0;i<9;i++)
        grid[i]=none;//
}

unsigned short Model::countFrame(Player player) const
{
    unsigned short i=0;//contatore istanze player
    for(unsigned short n=0;i<9;n++){
        if(grid[n]==player)
            i++;
    }
    return i;
}

Player Model::operator()(unsigned short row, unsigned short col) const
{
    if( (row >2 || col>2) )
        return none;
    return grid[row*3+col];//aritmetic pointers
}

bool Model::CheckWinner(unsigned short i, unsigned short j, unsigned short k) const{
    return ( grid[i] &&  (grid[i]==grid[j]) && (grid[j]==grid[k]) );
}
