#include "../include/EZnotenamesview.hpp"

EzNoteNamesView::EzNoteNamesView(QGraphicsScene* sc):QGraphicsView(sc){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setAlignment(Qt::AlignTop|Qt::AlignCenter);
}
EzNoteNamesView::~EzNoteNamesView(){}

void EzNoteNamesView::resizeEvent(QResizeEvent *event)
{
	fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
    QGraphicsView::resizeEvent(event);
}
