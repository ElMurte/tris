#include "tris.h"
#include"controller.h"
Tris::Tris(Controller* c,QWidget *parent):QWidget(parent),controller(c){
    mainlayout=new QVBoxLayout(this);gridlayout=new QGridLayout(this);
//aggiungere menu
addMenu();
//celle gioco ovvero bottoni
addButtons();
mainlayout->addLayout(gridlayout);//aggiungere il layout
setLayout(mainlayout);
setTrisStyle();
}

Tris::~Tris(){

}

void Tris::Update(){
    // Per adesso l'argomento player viene utilizzato per il testing
        for (unsigned short i = 0U; i < 9; ++i){
                int player=controller->get_Player(i/3,i%3);
            if (player != 0){
                QLayoutItem* item = gridlayout->itemAtPosition(i/3,i%3);
                QPushButton* button = static_cast<QPushButton*>(item->widget());
                if (player == 1){
                    button->setIcon(QIcon(":/risorse/player1.png"));
                } else {
                    button->setIcon(QIcon(":/risorse/player2.png"));
                }
                //button->setEnabled(false);
            }
        }
}

void Tris::ResetGrid(){//Qlayoutbutton
    for (unsigned short int i = 0U; i < 9; i++) {
            // "Estraggo" il bottone
            QPushButton *button = static_cast<QPushButton*>(gridlayout->itemAtPosition(i / 3, i % 3)->widget());
      // Tolgo l'icona
            button->setIcon(QIcon());

            // Riabilito il bottone
            button->setEnabled(true);
    }
}

void Tris::ShowWinner(){
    //creo finestra con Qdialog
    //creo il messaggio
    //inserisco il messaggio
    //metto nella finestra
    int winner=controller->get_Winner();
    QDialog* vincitore=new QDialog(this);
    QVBoxLayout* layoutmessaggio=new QVBoxLayout(vincitore);
    std::stringstream nomev;
    if(winner){
    nomev<<"The winner is Player "<<winner;
    }
    else nomev<<"DRAW";
    layoutmessaggio->addWidget(new QLabel(QString::fromStdString(nomev.str()),vincitore));
    vincitore->show();
}

void Tris::cellHandler(unsigned short x, unsigned short y) const{/*for debugging cellsUI OR other cases*/
    /*QDialog* vincitore=new QDialog();
    QVBoxLayout* layoutmessaggio=new QVBoxLayout(vincitore);
    std::stringstream nomev;
    nomev<<"cliccato("<<x<<","<<y<<")";
    layoutmessaggio->addWidget(new QLabel(QString::fromStdString(nomev.str()),vincitore));
    vincitore->show();*/
}

void Tris::ShowErrorMessage(const QString &message){
    QDialog* messaggio=new QDialog(this);
    QVBoxLayout* layoutmessaggio=new QVBoxLayout(messaggio);
    layoutmessaggio->addWidget(new QLabel(message,messaggio));
    messaggio->show();
}

void Tris::addButtons(){
//creare i bottoni ->Qpushbutton
    //aggiungere al layout
   for(unsigned short int i=0;i<9;i++){
        TrisButton* button=new TrisButton(i/3,i%3,this);//crea
        button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);//policy size
        gridlayout->addWidget(button,i/3,i%3);//aggiungi
        connect(button,SIGNAL(clickedCell(unsigned short, unsigned short)),controller,SLOT(Move(unsigned short,unsigned short)) );
        //comment connect(button,SIGNAL(clickedCell(unsigned short, unsigned short)),this,SLOT(cellHandler(unsigned short,unsigned short)) );
    }
}

void Tris::setTrisStyle(){
setMinimumSize(QSize(400,400));//dim
setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);//
QFile file(":/risorse/style.css");
file.open(QFile::ReadOnly);
QString filesheet=QLatin1String(file.readAll());
setStyleSheet(filesheet);
}

void Tris::addMenu()
{
//creare barra poi menu poi azioni
    QMenuBar*menubar=new QMenuBar(this);
    QMenu*menu= new QMenu("Menu",menubar);
    QAction* exit=new QAction("Exit",menu);
    QAction* reset=new QAction("Reset",menu);
    //aggiungo le azioni al menu
    connect(reset,SIGNAL(triggered()),controller,SLOT(resetGame()));
    connect(exit,SIGNAL(triggered()),this,SLOT(close()));
    menu->addAction(reset);
    menu->addAction(exit);
    //aggiungo la barra layout
    menubar->addMenu(menu);
    mainlayout->addWidget(menubar);
}



