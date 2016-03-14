#include "../include/EZtextnote.hpp"

EzTextNote::EzTextNote(EzNote* en, QGraphicsScene* parent):QGraphicsTextItem(QString(""),0,parent){
	setFont(QFont("Helvetica [Cronyx]", 12));
	realNote = en;
	myNote = "";
	setPos(realNote->getPos());
	alter = NULL;
	noteState = neutral;
}

EzTextNote::~EzTextNote(){
	delete alter;
}

void EzTextNote::updateNote(std::string key){
	myNote = key;
	std::string alteration;
	if(key.length() >= 4){
		if(realNote->getNote().length() >= 4){
			if (realNote->getNote().substr(3,4) == "b"){
				transformB(myNote);
			}
		}
		if(realNote->getNote().length() >= 5){
			if (realNote->getNote().substr(4,5) == "b"){
				transformB(myNote);
			}
		}
	}
	setPlainText(QString::fromStdString(key.substr(0,2)));
	if(myNote.length() >= 5){
		alteration = myNote.substr(4,5);
	}else if(myNote.length() >= 5){
		alteration = myNote.substr(3,4);
	}else{
		alteration = "";
	}
	
	if(alteration.length() > 0){
		alter = new QGraphicsTextItem();
		alter->setTransform(QTransform::fromTranslate(pos().x()-14,pos().y()-8));
        alter->setPlainText(QString::fromStdString(alteration));
		dynamic_cast<EzNoteNames*>(parent())->addItem(alter);
    }else{
		alter = NULL;
	}
}

void EzTextNote::transformB(std::string & dNote){
	std::string realNote = dNote.substr(0,2);
	if(realNote == "DO"){dNote = "RE" + dNote.substr(2,3) + "b";}
	else if(realNote == "RE"){dNote = "MI" + dNote.substr(2,3) + "b";}
	else if(realNote == "MI"){dNote = "FA" + dNote.substr(2,3) + "b";}
	else if(realNote == "FA"){dNote = "SOL" + dNote.substr(2,3) + "b";}
	else if(realNote == "SO"){dNote = "LA" + dNote.substr(3,4) + "b";}
	else if(realNote == "LA"){dNote = "SI" + dNote.substr(2,3) + "b";}
}


NoteState EzTextNote::getState(){
	return noteState;
}

bool EzTextNote::checkState(){
	if(myNote == realNote->getNote()){
		setRight();
		realNote->setState(correct);
		return true;
	}
	setWrong();
	realNote->setState(wrong);
	return false;
}

void EzTextNote::setNeutral(){
	noteState = neutral;
	setDefaultTextColor(QColor(0, 0, 0));
}
void EzTextNote::setWrong(){
	noteState = wrong;
	setDefaultTextColor(QColor(212, 27, 27));
	if(alter != NULL){
		alter->setDefaultTextColor(QColor(212, 27, 27));
	}
}
void EzTextNote::setRight(){
	noteState = correct;
	setDefaultTextColor(QColor(119, 212, 27));
	if(alter != NULL){
		alter->setDefaultTextColor(QColor(119, 212, 27));
	}
}
