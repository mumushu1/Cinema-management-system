#ifndef CLIENT_MOVIE_H
#define CLIENT_MOVIE_H

#include <QWidget>
#include <database.h>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDialog>
#include <QListWidgetItem>
#include <QCompleter>
#include <QString>
#include <QAbstractItemView>

namespace Ui {
class client_movie;
}

class client_movie : public QWidget
{
    Q_OBJECT

public:
    explicit client_movie(QWidget *parent = nullptr);
    ~client_movie();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::client_movie *ui;
    Database myDatabase;
    QSqlTableModel *model;
    QSqlTableModel *model1;
};

#endif // CLIENT_MOVIE_H
