#include "ezzik.h"
#include "ui_ezzik.h"
#include <QIcon>
#include <QComboBox>
#include <QGraphicsView>
#include <QGraphicsScene>


EZzik::EZzik(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EZzik)
{
    ui->setupUi(this);
    vLayout = new QVBoxLayout(this);
    vLayout->setAlignment(Qt::AlignHCenter);
}

EZzik::~EZzik()
{
    delete ui;
}

void EZzik::launch(){
    setWindowTitle("EZzik v1.0");
    setWindowIcon(QIcon("icone.png"));

    setMinimumWidth(600);
    setMinimumHeight(620);

    //partition list creation
    //TODO parcourir dossier partitions
    QComboBox *partitionsListe = new QComboBox(this);
    partitionsListe->addItem("partition1");
    partitionsListe->addItem("partition2");
    partitionsListe->addItem("partition3");
    vLayout->insertWidget(0,partitionsListe);
    InitPartition();
    show();
}

void EZzik::InitPartition()
{
        QGraphicsScene* scenePartition = new QGraphicsScene();
        scenePartition->addLine(0,10,500,10);
        scenePartition->addLine(0,20,500,20);
        scenePartition->addLine(0,30,500,30);
        scenePartition->addLine(0,40,500,40);
        QGraphicsView* viewPartition = new QGraphicsView(scenePartition);
        vLayout->insertWidget(1,viewPartition);
        viewPartition->show();
}

