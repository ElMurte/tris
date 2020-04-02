#include "tris.h"
#include "ui_tris.h"

Tris::Tris(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tris)
{
    ui->setupUi(this);
}

Tris::~Tris()
{
    delete ui;
}
