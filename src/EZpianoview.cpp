#include "../include/EZpianoview.hpp"

EzPianoView::EzPianoView(QGraphicsScene* sc):QGraphicsView(sc){}
EzPianoView::~EzPianoView(){}

void EzPianoView::mousePressEvent(QMouseEvent * mouseEvent){
	//QMessageBox::information(new QWidget(),QString::number(mouseEvent->pos().x()),QString::number(mouseEvent->pos().y()));
	QGraphicsView::mousePressEvent(mouseEvent);
}
