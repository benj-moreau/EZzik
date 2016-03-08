#include "ezzik.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EZzik w;

    w.launch();

    return a.exec();
}
