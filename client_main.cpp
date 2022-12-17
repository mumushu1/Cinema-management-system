#include "client_main.h"
#include "ui_client_main.h"
#include "signin.h"
#include "client_vip.h"
#include "client_movie.h"

client_main::client_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client_main)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #fad0c4, stop:1 #ffd1ff);");
    this->ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_5->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    this->myDatabase.getConnection();
    model = new QSqlTableModel;
    model->setTable("顾客表");
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽随窗口大小改变而改变，每列平均分配，充满整个表，但是此时列宽不能拖动进行改变
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

client_main::~client_main()
{
    delete ui;
}

//退出登录
void client_main::on_pushButton_3_clicked()
{
    this->~client_main();
    signin *w = new signin();
    w->show();
}

//办理会员卡
void client_main::on_pushButton_2_clicked()
{
    this->~client_main();
    client_vip *w = new client_vip();
    w->show();
}

//查看购买电影
void client_main::on_pushButton_clicked()
{
    this->~client_main();
    client_movie*w = new client_movie();
    w->show();
}

//查看个人编号
void client_main::on_pushButton_4_clicked()
{
    QSqlQuery sql;
    QString name = this->ui->name->text();
    model->setFilter(QString("顾客名 = %1").arg(name));
    model->select();
}

//保存
void client_main::on_pushButton_5_clicked()
{
    model->submitAll();
    model->select();
}

