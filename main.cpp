#include "AlphaFramework.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Alpha::AlphaFramework w;
    w.showMaximized();
    return a.exec();
}
