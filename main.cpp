#include "tris.h"
#include <QApplication>
#include "model.h"
#include "controller.h"
#include <iostream>
using std::cout;using std::endl;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    Controller c(&m);
    Tris tris(&c);
    c.set_View(&tris);
    tris.show();
    return a.exec();
}
