#include "tris.h"
#include <QApplication>
#include "model.h"
#include <iostream>
using std::cout;using std::endl;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tris tris;
    tris.show();
    return a.exec();
}
