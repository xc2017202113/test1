#include "mw1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    MW1 mw;
    mw.show();

    return a.exec();
}
