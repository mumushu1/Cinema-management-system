#include "zhuce.h"
#include "ui_zhuce.h"
#include"signin.h"
#include <QApplication>
#include<database.h>

zhuce::zhuce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zhuce)
{
    ui->setupUi(this);
    this->ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->radioButton->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->radioButton_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #fad0c4, stop:1 #ffd1ff);");
    this->MyDatabase.getConnection();//连接数据库
    this->ui->InputNumber->setFocus();
}

zhuce::~zhuce()
{
    delete ui;
}

void zhuce::on_pushButton_2_clicked()
{
    this->~zhuce();
    signin * w = new signin();
    w->show();
}

//注册
void zhuce::on_pushButton_3_clicked()
{
    QString userInputtype;
    if(ui->radioButton->isChecked()){
        userInputtype = "client";
    }
    else
    {
        userInputtype = "admin";
    }
    QString username = this->ui->InputNumber->text();
    QString password = this->ui->InputPassWord->text();
    QString surepassword = this->ui->InputPassWord_2->text();
    QSqlQuery query;
    //顾客注册
    if(ui->radioButton->isChecked()){
        query.exec("select 顾客名 from 顾客表 where 顾客名 = '"+username+"'");
        QString str1;
        while(query.next()){
            str1 = query.value("顾客名").toString();
        }
        if(username.isEmpty()||password.isEmpty()||surepassword.isEmpty()){
            QMessageBox::information(NULL, "提示", "账号密码确认密码不得为空！", QMessageBox::Ok);
        }
        else if(!str1.isEmpty())
        {
            QMessageBox::information(NULL,"提示","该用户名已被注册，请换一个用户名！",QMessageBox::Ok);
            this->ui->InputPassWord->clear();
            this->ui->InputPassWord_2->clear();
            this->ui->InputPassWord->setFocus();
        }
        else if(password!=surepassword)
        {
            QMessageBox::information(NULL, "提示", "密码和确认密码不同，请重新输入！", QMessageBox::Ok);
            this->ui->InputPassWord->clear();
            this->ui->InputPassWord_2->clear();
            this->ui->InputPassWord->setFocus();
        }
        else
        {
            query.prepare("insert into 顾客表(顾客名,顾客密码)values(?,?)");

            query.addBindValue(username);
            query.addBindValue(password);
            bool test = query.exec();
            if(test)
            {
                QMessageBox::information(NULL, "提示", "注册成功！", QMessageBox::Ok);
                //this->close();
            }
            else
            {
                QMessageBox::information(NULL, "提示", "注册不成功，请重新注册！", QMessageBox::Ok);
            }
        }
    }
    //管理员注册
    else
    {
            query.exec("select 管理员名 from 管理员表 where 管理员名 = '"+username+"'");
            QString str1;
            while(query.next()){
                str1 = query.value("管理员名").toString();
            }
            if(username.isEmpty()||password.isEmpty()||surepassword.isEmpty()){
                QMessageBox::information(NULL, "提示", "账号密码确认密码不得为空！", QMessageBox::Ok);
            }
            else if(!str1.isEmpty())
            {
                QMessageBox::information(NULL,"提示","该管理员名已被注册，请换一个管理员名！",QMessageBox::Ok);
                this->ui->InputPassWord->clear();
                this->ui->InputPassWord_2->clear();
                this->ui->InputPassWord->setFocus();
            }
            else if(password!=surepassword)
            {
                QMessageBox::information(NULL, "提示", "密码和确认密码不同，请重新输入！", QMessageBox::Ok);
                this->ui->InputPassWord->clear();
                this->ui->InputPassWord_2->clear();
                this->ui->InputPassWord->setFocus();
            }
            else
            {
                query.prepare("insert into 管理员表(管理员名,管理员密码)values(?,?)");

                query.addBindValue(username);
                query.addBindValue(password);
                bool test = query.exec();
                if(test)
                {
                    QMessageBox::information(NULL, "提示", "注册成功！", QMessageBox::Ok);
                    //this->close();
                }
                else
                {
                    QMessageBox::information(NULL, "提示", "注册不成功，请重新注册！", QMessageBox::Ok);
                }
    }
}
}

