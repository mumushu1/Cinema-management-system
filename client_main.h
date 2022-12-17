#ifndef CLIENT_MAIN_H
#define CLIENT_MAIN_H

#include <QWidget>
#include<QSqlTableModel>
#include<database.h>
#include <QSqlRecord>

namespace Ui {
class client_main;
}

class client_main : public QWidget
{
    Q_OBJECT

public:
    explicit client_main(QWidget *parent = nullptr);
    ~client_main();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::client_main *ui;
    Database myDatabase;
    QSqlTableModel *model;
};

#endif // CLIENT_MAIN_H
