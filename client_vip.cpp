#include "client_vip.h"
#include "ui_client_vip.h"
#include <client_main.h>

client_vip::client_vip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client_vip)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #fad0c4, stop:1 #ffd1ff);");
    this->ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    this->MyDatabase.getConnection();
    this->ui->lineEdit->setFocus();
}

client_vip::~client_vip()
{
    delete ui;
}

//退出办理会员界面
void client_vip::on_pushButton_clicked()
{
    this->~client_vip();
    client_main * w = new client_main();
    w->show();
}


//办理会员
void client_vip::on_pushButton_2_clicked()
{
    QString vname = this->ui->lineEdit->text();
    QString vphone = this->ui->lineEdit1->text();
    QSqlQuery query;
    query.exec("select 会员名 from 会员表 where 会员名 = '"+vname+"'");
    QString str1;
    while(query.next()){
        str1 = query.value("会员名").toString();
    }
    if(vname.isEmpty()||vphone.isEmpty())
    {
        QMessageBox::information(NULL, "提示", "会员名或手机号不得为空！", QMessageBox::Ok);
    }
    else
    {
        query.prepare("insert into 会员表(会员名,会员电话)values(?,?)");
        query.addBindValue(vname);
        query.addBindValue(vphone);
        bool test = query.exec();
        int vid = query.lastInsertId().toInt();
        if(test)
        {
             QMessageBox::information(NULL, "提示","办理成功，恭喜您成为尊贵的VIP用户！", QMessageBox::Ok);
        }
        else
        {
             QMessageBox::information(NULL, "提示","办理失败，是哪里出错了呢？", QMessageBox::Ok);
        }
        query.prepare("update 顾客表 set 会员编号=? where 顾客名=?");
        query.addBindValue(vid);
        query.addBindValue(vname);
        query.exec();
    }

}

