#include "dialogad.h"
#include "ui_dialogad.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
Dialogad::Dialogad(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialogad)
{
    ui->setupUi(this);
}

Dialogad::~Dialogad()
{
    delete ui;
}

void Dialogad::on_pushButton_clicked()
{
    reject();
}


void Dialogad::on_pushButton_2_clicked()
{
    QString title = ui->TITLE->text();
    QString genre = ui->GENRE->text();
    int year = ui->YEAR->text().toInt();


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "dialog_connection");
    db.setDatabaseName("C:/Users/MSI/Desktop/Lesson5full/movies.db");

    if (!db.open()) {
        qDebug() << "Диалог не смог открыть базу данных:" << db.lastError().text();
        return; // Если не открылась, дальше не идем
    }

    // 2. Создаем запрос ИМЕННО для этого подключения (передаем db в конструктор)
    QSqlQuery query(db);

    // 3. Твой самый простой запрос на добавление
    bool success = query.exec(QString("INSERT INTO films (title, genre, year) VALUES ('%1', '%2', %3)")
                                  .arg(title).arg(genre).arg(year));

    // 4. Проверка добавлено или нет
    if (success) {
        qDebug() << "Успешно добавлено через диалог!";

        // После работы закрываем это конкретное соединение
        db.close();

        accept(); // Закрываем окошко
    } else {
        qDebug() << "Ошибка добавления в диалоге:" << query.lastError().text();
        db.close();
    }
}

