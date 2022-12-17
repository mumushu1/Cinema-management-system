#ifndef ADMIN_MAIN_H
#define ADMIN_MAIN_H

#include <QWidget>

namespace Ui {
class admin_main;
}

class admin_main : public QWidget
{
    Q_OBJECT

public:
    explicit admin_main(QWidget *parent = nullptr);
    ~admin_main();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::admin_main *ui;
};

#endif // ADMIN_MAIN_H
