#include "model.h"

Model::Model(){
    for(u_s_int i=0;i<9;i++)
        grid[i]=none;//
}

bool Model::Move(unsigned short x, unsigned short y, Player player){
    //se esiste un vincitore nada  OR  se la casella è occupata
    if (winner() || (grid[x*3+y]!=none)) return false;

         grid[x*3+y]=player;
         return true;
}

Player Model::winner() const{
    for(u_s_int i=0;i<3;i++){
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
    for(u_s_int i=0;i<9;i++)
        grid[i]=none;//
}

unsigned short Model::countFrame(Player player) const
{
    u_s_int i=0;//contatore istanze player
    for(u_s_int n=0;i<9;n++){
        if(grid[n]==player)
            i++;
    }
    return i;
}

Player Model::operator()(unsigned short row, unsigned short col) const
{
    if( (row<0 || row >2) || (col <0 || col>2) )
        return none;
    return grid[row*3+col];//aritmetic pointers
}

bool Model::CheckWinner(unsigned short i, unsigned short j, unsigned short k) const{
    return grid[i]!=none &&  grid[i]==grid[j]==grid[k];//Qt suggerisce parentesi LOL
}
