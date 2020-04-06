#include "trisbutton.h"

TrisButton::TrisButton(unsigned short r, unsigned short c, QWidget *parent) : QPushButton(parent),x(r),y(c){
    connect(this,SIGNAL(clicked()),this,SLOT(cellEmitter()));
}

void TrisButton::cellEmitter(){
emit clickedCell(x,y);
}
