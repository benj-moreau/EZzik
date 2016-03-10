#include "../include/EZnote.hpp"

EzNote::EzNote(std::string note, int x, int y, QGraphicsScene* parent):QGraphicsEllipseItem(QRectF(x, y, TONE_WIDTH, TONE_HEIGHT), 0, parent){
	_note = note;
    _state = neutral;
}
EzNote::~EzNote(){}

std::string EzNote::getNote(){ return _note; }
void EzNote::setState(NoteState state){ _state = state; }

