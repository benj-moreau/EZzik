#include "ezzik.h"
#include <QApplication>
#include <QIcon>
#include <QComboBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EZzik w;


    w.setWindowTitle("EZzik v1.0");
    w.setWindowIcon(QIcon("icone.png"));
    //TODO set minimum/maximum sizes

    //partition list creation
    //TODO parcourir dossier partitions
    QComboBox *partitionsListe = new QComboBox(&w);
    partitionsListe->addItem("p1");
    partitionsListe->move(100, 20);

    w.show();



    return a.exec();
}
