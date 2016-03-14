#include "../include/EZtextnote.hpp"

EzTextNote::EzTextNote(EzNote* en, QGraphicsScene* parent):QGraphicsTextItem(QString(""),0,parent){
	setFont(QFont("Helvetica [Cronyx]", 12));
	realNote = en;
	alter = NULL;
}

EzTextNote::~EzTextNote(){
	delete alter;
}

void EzTextNote::updateNote(std::string key){
	setPlainText(QString::fromStdString(key));
	setPos(realNote->getPos());
	//alter = realNote->getAlter();
}

void EzTextNote::setNeutral(){
	//this->setBrush(QBrush(QColor(0, 0, 0)));
}
void EzTextNote::setWrong(){
	//this->setBrush(QBrush(QColor(212, 27, 27)));
}
void EzTextNote::setRight(){
	//this->setBrush(QBrush(QColor(119, 212, 27)));
}
