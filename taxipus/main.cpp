#include "taptaxi.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TapTaxi w;
    w.show();
    return a.exec();
}
