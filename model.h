  #ifndef MODEL_H
#define MODEL_H
#define u_s_int unsigned short
enum Player{none=0,player1=1,player2=2};
class Model
{
public:
    Model();
    //svolgimento di una mossa
    bool Move( u_s_int x, u_s_int y);
    //restituzione di un vincitore
    Player winner()const;//ritorna il vincitore se esiste altrimenti ritorna 0
    //reset
    void reset();
u_s_int countFrame(Player player) const;
Player operator()(u_s_int row,u_s_int col)const;
private:
    Player grid[9];
    bool turn;
    bool CheckWinner(u_s_int r,u_s_int c,u_s_int k) const;
};

#endif // MODEL_H
