#include "../include/EZpianoview.hpp"

EzPianoView::EzPianoView(QGraphicsScene* sc):QGraphicsView(sc){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setRenderHints(QPainter::Antialiasing);
}
EzPianoView::~EzPianoView(){}

void EzPianoView::mousePressEvent(QMouseEvent * mouseEvent){
	//QMessageBox::information(new QWidget(),QString::number(mouseEvent->pos().x()),QString::number(mouseEvent->pos().y()));
	QGraphicsView::mousePressEvent(mouseEvent);
}

void EzPianoView::resizeEvent(QResizeEvent *event)
{
    fitInView(scene()->sceneRect() ,Qt::KeepAspectRatio);
    QGraphicsView::resizeEvent(event);
}
