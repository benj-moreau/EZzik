#include "../include/EZscoreview.hpp"

EzScoreView::EzScoreView(QGraphicsScene* sc):QGraphicsView(sc){
}
EzScoreView::~EzScoreView(){}

void EzScoreView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
}
