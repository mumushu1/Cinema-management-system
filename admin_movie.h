#ifndef ADMIN_MOVIE_H
#define ADMIN_MOVIE_H

#include <QWidget>
#include<QSqlTableModel>
#include<database.h>
#include <QSqlRecord>
#include <QMessageBox>

namespace Ui {
class admin_movie;
}

class admin_movie : public QWidget
{
    Q_OBJECT

public:
    explicit admin_movie(QWidget *parent = nullptr);
    ~admin_movie();

private slots:
    void on_query_clicked();

    void on_add_clicked();

    void on_delete_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

private:
    Database myDatabase;//cpp文件中连接数据库用
    Ui::admin_movie *ui;
    QSqlTableModel *model;
};

#endif // ADMIN_MOVIE_H
