#include "tris.h"
#include <QApplication>
#include "model.h"
#include <iostream>
using std::cout;using std::endl;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Tris w;
    w.show();

    return a.exec();

}
