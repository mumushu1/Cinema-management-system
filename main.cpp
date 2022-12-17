#include "signin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    signin w;
    w.show();
    return a.exec();
}
