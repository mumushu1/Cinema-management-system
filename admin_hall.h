#ifndef ADMIN_HALL_H
#define ADMIN_HALL_H

#include <QWidget>
#include<QSqlTableModel>
#include<database.h>
#include <QSqlRecord>


namespace Ui {
class admin_hall;
}

class admin_hall : public QWidget
{
    Q_OBJECT

public:
    explicit admin_hall(QWidget *parent = nullptr);
    ~admin_hall();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Database MyDatabase;
    QSqlTableModel *model;
    Ui::admin_hall *ui;

};

#endif // ADMIN_HALL_H
