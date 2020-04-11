#ifndef TRISCLASS_H
#define TRISCLASS_H
#include <QPushButton>
#define u_s_int unsigned short
class TrisButton : public QPushButton
{
    Q_OBJECT
public:
    TrisButton(unsigned short r,unsigned short c,QWidget*parent=nullptr);

signals:
void clickedCell(unsigned short, unsigned short);

private:
    unsigned short x,y;
private slots:
void cellEmitter();
};

#endif // TRISCLASS_H
