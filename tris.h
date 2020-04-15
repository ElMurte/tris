#ifndef TRIS_H
#define TRIS_H
#define u_s_int unsigned short
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMenuBar>
#include <QPushButton>
#include <QIcon>
#include <QFile>
#include <QDialog>
#include <QLabel>
#include <sstream>
#include "trisbutton.h"

class Controller;
class Tris : public QWidget{
Q_OBJECT
public:
    Tris(Controller* c,QWidget *parent=0);
    ~Tris();
    void Update();
    void ResetGrid();
    void ShowWinner();
       void ShowErrorMessage(const QString& message);
public slots:
void cellHandler(unsigned short,unsigned short) const;
private:
    Controller* controller;
    QVBoxLayout *mainlayout;
    QGridLayout *gridlayout;

    void addMenu();
    void addButtons();
    void setTrisStyle();
};

#endif // TRIS_H
