#include "dialogadmin.h"
#include "ui_dialogadmin.h"

Dialogadmin::Dialogadmin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialogadmin)
{
    ui->setupUi(this);
}

Dialogadmin::~Dialogadmin()
{
    delete ui;
}
