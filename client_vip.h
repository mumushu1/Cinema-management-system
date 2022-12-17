#ifndef CLIENT_VIP_H
#define CLIENT_VIP_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include <database.h>
#include <QMessageBox>

namespace Ui {
class client_vip;
}

class client_vip : public QWidget
{
    Q_OBJECT

public:
    Database MyDatabase;
    explicit client_vip(QWidget *parent = nullptr);
    ~client_vip();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::client_vip *ui;
};

#endif // CLIENT_VIP_H
