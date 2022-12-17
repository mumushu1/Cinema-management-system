#include "admin_main.h"
#include "ui_admin_main.h"
#include "admin_movie.h"
#include "admin_hall.h"
#include "signin.h"

admin_main::admin_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_main)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #fad0c4, stop:1 #ffd1ff);");
}

admin_main::~admin_main()
{
    delete ui;
}

//进入电影信息管理界面
void admin_main::on_pushButton_clicked()
{
    this->~admin_main();
    admin_movie * w = new admin_movie();
    w->show();
}

//进入影厅管理界面
void admin_main::on_pushButton_2_clicked()
{
    this->~admin_main();
    admin_hall *w = new admin_hall();
    w->show();
}

//退出登录
void admin_main::on_pushButton_3_clicked()
{
    this->~admin_main();
    signin *w = new signin();
    w->show();
}

