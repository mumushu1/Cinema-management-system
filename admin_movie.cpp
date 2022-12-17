#include "admin_movie.h"
#include "ui_admin_movie.h"
#include "admin_main.h"

admin_movie::admin_movie(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_movie)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #fad0c4, stop:1 #ffd1ff);");
    this->myDatabase.getConnection();
    this->ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    model = new QSqlTableModel;
    model->setTable("电影表_管理员视角");
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽随窗口大小改变而改变，每列平均分配，充满整个表，但是此时列宽不能拖动进行改变
    model->select();
    //设置model的编辑模式，手动提交修改
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->ui->listWidget->addItem(QString("欢迎你，伟大的管理员！\n"));

    //使该窗口close（）后自动销毁
    setAttribute(Qt::WA_DeleteOnClose, true);
    //一次选中一行
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);


}

admin_movie::~admin_movie()
{
    delete ui;
}

//查询槽函数
void admin_movie::on_query_clicked()
{
    int index = this->ui->comboBox->currentIndex();
    QString lineEdit = this->ui->lineEdit->text();
    switch(index)
    {
        case 0:
            QMessageBox::information(NULL,"提示","请选择查询方式!",QMessageBox::Ok);
            break;
        case 1:
            model->setFilter(QString("电影名称='%1'").arg(lineEdit));
            model->select();
            break;
        case 2:
            model->setFilter(QString("电影类型 = '%1'").arg(lineEdit));
            model->select();
            break;
    }
}


//增加空白行槽函数
void admin_movie::on_add_clicked()
{
    //添加空记录
    QSqlRecord record = model->record(); //获取空记录
    //获取行号
    int row = model->rowCount();
    model->insertRecord(row, record);
}

//删除槽函数
void admin_movie::on_delete_2_clicked()
{
    QItemSelectionModel *m = ui->tableView->selectionModel();
    QModelIndexList list = m->selectedRows();
    //删除所有选中的行
    for(int i=0;i<list.size();i++){
        model->removeRow(list.at(i).row());
    }
}

//保存槽函数
void admin_movie::on_pushButton_clicked()
{
    model->submitAll();
    model->select();
}

//返回列表槽函数
void admin_movie::on_pushButton_2_clicked()
{
    model->setTable("电影表_管理员视角");//指定使用哪个表
    model->select();//显示model里的数据

    this->ui->listWidget->clear();
    this->ui->listWidget->addItem(QString("欢迎你，伟大的管理员！\n"));
}


void admin_movie::on_tableView_clicked(const QModelIndex &index)
{
    this->ui->listWidget->clear();
    QSqlRecord record = model->record(index.row());
    QString mname = record.value("电影名称").toString();
    QString mtype = record.value("电影类型").toString();
    QString mshowtime = record.value("放映时间").toString();
    QString mtime = record.value("时长").toString();
    QString mhall = record.value("影厅号").toString();
    QString mfare = record.value("票价").toString();

    ui->listWidget->addItem(QString("电影名称:%1\n\n电影类型:%2\n\n时长:%3\n\n票价:%4\n\n影厅号:%5\n\n放映时间:%6\n").arg(mname).arg(mtype).arg(mtime).arg(mfare).arg(mhall).arg(mshowtime));


}

//返回管理员主界面
void admin_movie::on_pushButton_3_clicked()
{
    this->~admin_movie();
    admin_main *w = new admin_main();
    w->show();
}

