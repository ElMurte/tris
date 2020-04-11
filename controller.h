#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "model.h"
#include "tris.h"
class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(Model* mod,QObject *parent = nullptr);
    void set_View(Tris* v);
    int get_Player(unsigned short x,unsigned short y)const;
    int get_Winner()const;

public slots:
void Move(unsigned short,unsigned short);
void resetGame();
private:

Tris* view;
Model * model;
};

#endif // CONTROLLER_H
