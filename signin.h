#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include <database.h>
#include <QMessageBox>

namespace Ui {
class signin;
}

class signin : public QWidget
{
    Q_OBJECT

public:
    Database myDatabase;//cpp文件中连接数据库用
    explicit signin(QWidget *parent = nullptr);
    ~signin();

private slots:
    //void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::signin *ui; 
};

#endif // SIGNIN_H
