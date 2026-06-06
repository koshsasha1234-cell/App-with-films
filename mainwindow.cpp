#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include "dialogad.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MSI/Desktop/Lesson5full/movies.db");

    if(!db.open()){
        qDebug() << "Ошибка: " << db.lastError().text();
    }

    QSqlQuery createTable;
    createTable.exec(
        "CREATE TABLE IF NOT EXISTS films("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "title TEXT,"
        "genre TEXT,"
        "year INTEGER,"
        "UNIQUE(title))"
    );

    model = new QSqlTableModel(this);
    model->setTable("films");
    model->select();

    //ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_poisk_clicked()
{

}


void MainWindow::on_filters_clicked()
{
    Dialog *genreDialog = new Dialog(this);

    // Связываем сигнал из Dialog со слотом в MainWindow
    connect(genreDialog, &Dialog::genreSelected, this, &MainWindow::filterMoviesByGenre);

    genreDialog ->show();

}


void MainWindow::on_pushButton_clicked()
{
    Dialogad dlg(this);
    dlg.exec();
}

void MainWindow::filterMoviesByGenre(QString selectedGenre)
{
    // 1. Очищаем TableWidget перед новым выводом, чтобы старые фильмы стёрлись
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название" << "Жанр" << "Год");

    // 2. Создаем обычный SQL-запрос
    QSqlQuery query;

    // Пишем простой человеческий запрос: "Выбрать всё из таблицы films, где жанр равен нашему слову"
    // Например: SELECT * FROM films WHERE genre = 'Боевик'
    QString queryString = "SELECT title, genre, year FROM films WHERE genre = '" + selectedGenre + "'";

    // Запускаем запрос в базу данных
    if (!query.exec(queryString)) {
        qDebug() << "Ошибка выполнения запроса фильтрации:" << query.lastError().text();
        return;
    }

    // 3. Бежим циклом по всем найденным строчкам в базе данных (пока они не кончатся)
    while (query.next()) {
        // Достаем данные прямо по названиям колонок из нашего SELECT-запроса
        QString title = query.value("title").toString();
        QString movieGenre = query.value("genre").toString();
        int year = query.value("year").toInt();

        // Создаем новую строчку в конце TableWidget
        int currentRow = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(currentRow);

        // Построчно выводим данные в ячейки нашей таблицы на экране
        ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(title));
        ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(movieGenre));
        ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(QString::number(year)));
    }

    qDebug() << "Успешно вывели на экран все фильмы по жанру:" << selectedGenre;
}
