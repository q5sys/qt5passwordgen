#include <QtGui>
#include <QApplication>
#include "MainUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainUI W;
    W.show();
    return a.exec();
}
