#include "../include/EZnote.hpp"

EzNote::EzNote(std::string note,NoteAlteration alteration, int x, int y, QGraphicsScene* parent):QGraphicsEllipseItem(QRectF(x, y, TONE_WIDTH, TONE_HEIGHT), 0, parent){
     setPen( QPen( QColor(0,0,0,225), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin ) );
	_note = note;
    _state = neutral;
    QGraphicsTextItem *alter = new QGraphicsTextItem();
    alter->setTransform(QTransform::fromTranslate(x-14,y-8));
    if(alteration == bemol){
        alter->setPlainText("b");
    }else if(alteration == diese){
        alter->setPlainText("#");
    }
    parent->addItem(alter);
    //under and upper onscore notes
    if((note.substr(0,3)=="DO1") ||  (note.substr(0,3)=="LA2")){
        parent->addItem(new QGraphicsLineItem(x-(TONE_WIDTH/2),y+(TONE_HEIGHT/2),x+(TONE_WIDTH)+(TONE_WIDTH/2),y+(TONE_HEIGHT/2)));
    }
}
EzNote::~EzNote(){}

std::string EzNote::getNote(){ return _note; }
void EzNote::setState(NoteState state){
    _state = state;
    if(state == wrong){
        this->setBrush(QBrush(QColor(212, 27, 27)));
    }else{
        this->setBrush(QBrush(QColor(119, 212, 27)));
    }
}
