#include "client_movie.h"
#include "ui_client_movie.h"
#include "client_main.h"

QString number="";

client_movie::client_movie(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client_movie)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #fad0c4, stop:1 #ffd1ff);");
    this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 200), stop:1 rgba(20,196,188, 210));");
    this->ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    this->ui->label_4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    this->myDatabase.getConnection();

    //表1
    model = new QSqlTableModel(this);
    model->setTable("电影表_管理员视角");
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽随窗口大小改变而改变，每列平均分配，充满整个表，但是此时列宽不能拖动进行改变
    model->select();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //表2
    model1 = new QSqlTableModel;
    model1->setTable("票务表");
    ui->tableView_2->setModel(model1);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽随窗口大小改变而改变，每列平均分配，充满整个表，但是此时列宽不能拖动进行改变
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
}

client_movie::~client_movie()
{
    delete ui;
}

//返回顾客主界面
void client_movie::on_pushButton_3_clicked()
{
    this->~client_movie();
    client_main *w = new client_main();
    w->show();
}

//查看已购
void client_movie::on_pushButton_2_clicked()
{
    model1->select();
}

//购买
bool judge_vip();
void client_movie::on_pushButton_clicked()
{
    QModelIndex index=ui->tableView->currentIndex();//得到点击的项的索引
    QSqlRecord record = model->record(index.row());
    QString mname = record.value("电影名称").toString();
    QString mshowtime = record.value("放映时间").toString();
    QString mhall = record.value("影厅号").toString();
    QString mfare = record.value("票价").toString();
    QSqlQuery sql;
    QString number = this->ui->number->text();

    QSqlQuery query;
    query.prepare("SELECT 会员编号 FROM 顾客表 WHERE 顾客编号 = ?");
    query.addBindValue(number); // 将顾客编号绑定到查询中
    query.exec();
    int vip = 0;
    if (query.next()) {
        // 获取会员编号
        int memberNumber = query.value(0).toInt();

        if (memberNumber != 0) {
            // 如果会员编号不为 0，则表示顾客是会员
            vip = 1;
        } else {
            // 否则，表示顾客不是会员
            vip = 0;
        }
    }

    bool buy = sql.exec("insert into 票务表 (电影名称,放映时间,影厅号,票价,顾客编号)values('"+mname+"','"+mshowtime+"','"+mhall+"','"+mfare+"','"+number+"')");
    if(buy&&vip)
    {
        QMessageBox::information(NULL,"提示",QString("%1\n购票成功,这边检测到您是尊贵的会员，已为您折扣费用，如果有需要，请来山财大领取免费小食").arg(mname),QMessageBox::Ok);
    }
    else if(buy&&vip==0)
    {
        QMessageBox::information(NULL,"提示",QString("%1\n购票成功,办理会员后更优惠！").arg(mname),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(NULL, "提示", "购票失败，请先输入您的编号！", QMessageBox::Ok);
    }
}

//输入编号
void client_movie::on_pushButton_5_clicked()
{
    QSqlQuery sql;
    QString number = this->ui->number->text();
    model1->setFilter(QString("顾客编号 = %1").arg(number));
    model1->select();
}

//按名称搜索电影
void client_movie::on_pushButton_6_clicked()
{
    QString cname = this->ui->cinema_name->text();
    model->setFilter(QString("电影名称 = '%1'").arg(cname));
}

//退票
void client_movie::on_pushButton_4_clicked()
{
    QItemSelectionModel *m = ui->tableView_2->selectionModel();
    QModelIndexList list = m->selectedRows();
    //删除所有选中的行
    for(int i=0;i<list.size();i++){
        model1->removeRow(list.at(i).row());
    }
}

//在上面没用函数已实现该功能
//判断是否为会员
//bool judge_vip(){
//    QSqlQuery query;
//    query.prepare("SELECT 会员编号 FROM 顾客表 WHERE 顾客编号 = ?");
//    query.addBindValue(number); // 将顾客编号绑定到查询中
//    query.exec();
//    if (query.next()) {
//        // 获取会员编号
//        int memberNumber = query.value(0).toInt();

//        if (memberNumber != 0) {
//            // 如果会员编号不为 0，则表示顾客是会员
//           return true;
//        } else {
//            // 否则，表示顾客不是会员
//            return false;
//        }

//    }
//}



