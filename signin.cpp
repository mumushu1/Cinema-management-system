#include "signin.h"
#include "ui_signin.h"
#include <QApplication>
#include"zhuce.h"
#include "admin_main.h"
#include "client_main.h"
#include <QLabel>

signin::signin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
    //界面美化
    this->ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->radioButton->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->radioButton_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->InputNumber->setStyleSheet("font: 25 10pt '微软雅黑 Light';" //字体
                                         "color: rgb(31,31,31);"		//字体颜色
                                         "padding-left:20px;"       //内边距-字体缩进
                                         "background-color: rgb(255, 255, 255);" //背景颜色
                                         "border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置
    this->ui->InputPassWord->setStyleSheet("font: 25 10pt '微软雅黑 Light';" //字体
                                         "color: rgb(31,31,31);"		//字体颜色
                                         "padding-left:20px;"       //内边距-字体缩进
                                         "background-color: rgb(255, 255, 255);" //背景颜色
                                         "border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置
    this->ui->InputPassWord->setEchoMode(QLineEdit::Password);
    ui->pushButton_2->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 Light';color: rgb(255,255,255);background-color: rgb(20,196,188);"
                                                                  "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                                                  "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                                                  "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                                                    "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->pushButton_3->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 Light';color: rgb(255,255,255);background-color: rgb(20,196,188);"
                                                                      "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                                                      "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                                                      "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                                                        "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->pushButton_4->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 Light';color: rgb(255,255,255);background-color: rgb(20,196,188);"
                                                                      "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                                                      "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                                                      "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                                                        "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #fad0c4, stop:1 #ffd1ff);");

    this->myDatabase.getConnection();//连接数据库
    setWindowFlags(Qt::Widget);//使dialog项目有最大最小化按钮
    setWindowTitle("登录");
    this->ui->InputNumber->setFocus();//一开始就可以输入,不用单点
}

signin::~signin()
{
    delete ui;
}
//注册槽函数
void signin::on_pushButton_3_clicked()
{
    this->~signin();

    zhuce *w = new zhuce();
    w->show();
}

//退出槽函数
void signin::on_pushButton_2_clicked()
{
    exit(0);
}

//登录
void signin::on_pushButton_4_clicked()
{
    QString userInputtype;//判断你是顾客还是管理员
    if(ui->radioButton->isChecked()){// isChecked()来查询按钮是否被选中。
        userInputtype = "client";
    }
    else
    {
        userInputtype = "admin";
    }
    QString username = this->ui->InputNumber->text();
    QString password = this->ui->InputPassWord->text();
    QSqlQuery query;
    if(ui->radioButton->isChecked()){
        if(username.isEmpty()||password.isEmpty()){
            QMessageBox::information(NULL, "提示", "账号密码不得为空！", QMessageBox::Ok);
        }
        else
        {
            query.exec("select * from 顾客表 where 顾客名 = '"+username+"'");
            if(!query.isActive())
            {
                QMessageBox::critical(NULL,"错误","查询未执行！", QMessageBox::Ok);
            }
            QString str1,str2;
            while(query.next()){
                str1 = query.value("顾客名").toString();
                str2 = query.value("顾客密码").toString();
            }
            if(str1.isEmpty()){
                QMessageBox::information(NULL, "提示", "没有该账号！", QMessageBox::Ok);
                this->ui->InputNumber->clear();
                this->ui->InputPassWord->clear();
                this->ui->InputNumber->setFocus();//输入焦点转为输入账号
            }
            else if(str2!=password)
            {
                QMessageBox::information(NULL, "提示", "账号存在，密码错误！", QMessageBox::Ok);
                this->ui->InputNumber->clear();
                this->ui->InputNumber->setFocus();
            }
            else
            {
                QMessageBox::information(NULL, "提示", "登录成功！", QMessageBox::Ok);
                this->~signin();//调用析构函数，释放
                client_main* w = new client_main();
                w->show();
            }
        }
    }
    else
    {
        if(username.isEmpty()||password.isEmpty()){
            QMessageBox::information(NULL, "提示", "账号密码不得为空！", QMessageBox::Ok);
        }
        else
        {
            query.exec("select * from 管理员表 where 管理员名 = '"+username+"'");
            if(!query.isActive())
            {
                QMessageBox::critical(NULL,"错误","查询未执行！", QMessageBox::Ok);
            }
            QString str1,str2;
            while(query.next()){
                str1 = query.value("管理员名").toString();
                str2 = query.value("管理员密码").toString();
            }
            if(str1.isEmpty()){
                QMessageBox::information(NULL, "提示", "没有该账号！", QMessageBox::Ok);
                this->ui->InputNumber->clear();
                this->ui->InputPassWord->clear();
                this->ui->InputNumber->setFocus();//输入焦点转为输入账号
            }
            else if(str2!=password)
            {
                QMessageBox::information(NULL, "提示", "账号存在，密码错误！", QMessageBox::Ok);
                this->ui->InputNumber->clear();
                this->ui->InputNumber->setFocus();
            }
            else
            {
                QMessageBox::information(NULL, "提示", "登录成功！", QMessageBox::Ok);
                this->~signin();//调用析构函数，释放
                admin_main* w = new admin_main();
                w->show();
            }
        }
    }

}

