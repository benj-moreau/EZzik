#include "../include/EZnote.hpp"

EzNote::EzNote(std::string note,NoteAlteration alteration, int x, int y, QGraphicsScene* parent):QGraphicsEllipseItem(QRectF(x, y, TONE_WIDTH, TONE_HEIGHT), 0, parent){
     setPen( QPen( QColor(0,0,0,225), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin ) );
	_note = note;
    _state = neutral;
    
    if(alteration == bemol){
		alter = new QGraphicsTextItem();
		alter->setTransform(QTransform::fromTranslate(x-14,y-8));
        alter->setPlainText("b");
		parent->addItem(alter);
    }else if(alteration == diese){
		alter = new QGraphicsTextItem();
		alter->setTransform(QTransform::fromTranslate(x-14,y-8));
        alter->setPlainText("#");
		parent->addItem(alter);
    }else{
		alter = NULL;
	}

    //under and upper onscore notes
    if((note.substr(0,3)=="DO1") ||  (note.substr(0,3)=="LA2")){
		line = new QGraphicsLineItem(x-(TONE_WIDTH/2),y+(TONE_HEIGHT/2),x+(TONE_WIDTH)+(TONE_WIDTH/2),y+(TONE_HEIGHT/2));
		parent->addItem(line);
    }else{
		line = NULL;
	}
}
EzNote::~EzNote(){
	delete alter;
	delete line;
}

std::string EzNote::getNote(){ return _note; }
QGraphicsTextItem* EzNote::getAlter(){ return alter; }
QPen EzNote::getPen(){ return QPen(); }
QPoint EzNote::getPos(){ 
	return QPoint(rect().x(),0); 
}

void EzNote::setState(NoteState state){
    _state = state;
    if(state == wrong){
        this->setBrush(QBrush(QColor(212, 27, 27)));
    }else{
        this->setBrush(QBrush(QColor(119, 212, 27)));
    }
}

NoteState EzNote::getState(){ return _state; }

bool EzNote::isBemol(){
	int noteSize = _note.length();
	return (noteSize > 0)?(_note[_note.length() -1] == 'B'):false;
}
