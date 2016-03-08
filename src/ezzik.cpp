#include "ezzik.h"
#include "ui_ezzik.h"

EZzik::EZzik(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EZzik)
{
    ui->setupUi(this);
}

EZzik::~EZzik()
{
    delete ui;
}
