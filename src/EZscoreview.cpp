#include "../include/EZscoreview.hpp"

EzScoreView::EzScoreView(QGraphicsScene* sc):QGraphicsView(sc){
}
EzScoreView::~EzScoreView(){}

void EzScoreView::resizeEvent(QResizeEvent *event)
{
    fitInView(0, 0, 80, 80,Qt::KeepAspectRatio);
    QGraphicsView::resizeEvent(event);
}
