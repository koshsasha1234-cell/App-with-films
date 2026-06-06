#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_5_clicked()
{
    reject();
}


void Dialog::on_comedy_clicked()
{

    // Отправляем сигнал "Комедия" наружу
    emit genreSelected("Комедия");

    // Закрываем текущее диалоговое окно
    this->close();

}


void Dialog::on_boyeviky_clicked()
{

    emit genreSelected("Боевик");

    // Закрываем текущее диалоговое окно
    this->close();
}


void Dialog::on_fantastic_clicked()
{

    emit genreSelected("Фантастика");

    // Закрываем текущее диалоговое окно
    this->close();
}


void Dialog::on_detective_clicked()
{

    emit genreSelected("Детектив");

    // Закрываем текущее диалоговое окно
    this->close();
}

