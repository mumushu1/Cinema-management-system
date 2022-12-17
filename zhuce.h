#ifndef ZHUCE_H
#define ZHUCE_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include <database.h>
#include <QMessageBox>

namespace Ui {
class zhuce;
}

class zhuce : public QWidget
{
    Q_OBJECT

public:
    Database MyDatabase;
    explicit zhuce(QWidget *parent = nullptr);
    ~zhuce();

private slots:
    //void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::zhuce *ui;
};

#endif // ZHUCE_H
