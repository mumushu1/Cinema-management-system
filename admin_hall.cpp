#include "admin_hall.h"
#include "ui_admin_hall.h"
#include "admin_main.h"

admin_hall::admin_hall(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_hall)
{
    ui->setupUi(this);
    this->MyDatabase.getConnection();
    //以下两句为界面美化
    this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #fad0c4, stop:1 #ffd1ff);");
    this->ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    model = new QSqlTableModel;
    model->setTable("影厅表");
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽随窗口大小改变而改变，每列平均分配，充满整个表，但是此时列宽不能拖动进行改变
    //设置model的编辑模式，手动提交修改
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //一次选中一行
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

admin_hall::~admin_hall()
{
    delete ui;
}

//返回管理员主界面
void admin_hall::on_pushButton_4_clicked()
{
    this->~admin_hall();
    admin_main *w = new admin_main();
    w->show();
}

//查询
void admin_hall::on_pushButton_clicked()
{
    model->select();
}


//删除
void admin_hall::on_pushButton_3_clicked()
{
    QItemSelectionModel *m = ui->tableView->selectionModel();
    QModelIndexList list = m->selectedRows();
    //删除所有选中的行
    for(int i=0;i<list.size();i++){
        model->removeRow(list.at(i).row());
    }
}

//保存
void admin_hall::on_pushButton_2_clicked()
{
    model->submitAll();
    model->select();
}


void admin_hall::on_tableView_clicked(const QModelIndex &index)
{
    QSqlRecord record = model->record(index.row());
    QString hall_id = record.value("影厅号").toString();
    QString hall_condition = record.value("影厅状态").toString();
}

