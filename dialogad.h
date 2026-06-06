#ifndef DIALOGAD_H
#define DIALOGAD_H

#include <QDialog>

namespace Ui {
class Dialogad;
}

class Dialogad : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogad(QWidget *parent = nullptr);
    ~Dialogad();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialogad *ui;
};

#endif // DIALOGAD_H
