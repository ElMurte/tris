#ifndef TRIS_H
#define TRIS_H

#include <QWidget>

namespace Ui {
class Tris;
}

class Tris : public QWidget
{
    Q_OBJECT

public:
    explicit Tris(QWidget *parent = 0);
    ~Tris();

private:
    Ui::Tris *ui;
};

#endif // TRIS_H
