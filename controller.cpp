#include "controller.h"

Controller::Controller(Model *mod, QObject *parent) : view(nullptr),model(mod),QObject(parent){}

void Controller::set_View(Tris *v){
view=v;
}

int Controller::get_Player(unsigned short x, unsigned short y) const{
return (*model)(x,y);
}

int Controller::get_Winner() const{
    return model->winner();
}

void Controller::Move(unsigned short x, unsigned short y){
    //provo sd eseguire la mossa
    if(model->Move(x,y)){
        view->Update();
        if(model->winner() || ((model->countFrame(player1))+(model->countFrame(player2)))==8){
            view->ShowWinner();
            resetGame();
        }
    }
//se la mossa va a buon aggiorno la vista e controllo il vincitore
//oppure dovrei aggiornare la vista con qualche messaggio
}

void Controller::resetGame(){
    //reset modello
    model->reset();
    //remipostare la vista
    view->ResetGrid();
}
