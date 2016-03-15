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

void EzTextNote::updateNote(std::string key, EzNoteNames* parent){
	myNote = key;

	if(alter != NULL){
		parent->removeItem(alter);
		delete alter;
		alter = NULL;
	}

	if((realNote->isBemol()) && (key[key.length()-1] == '#')){
		transformB(myNote);
	}

	if(myNote.substr(0,2) == "SO"){
		setPlainText(QString("SOL"));
	}else{
		setPlainText(QString::fromStdString(myNote.substr(0,2)));
	}
	if((myNote[myNote.length()-1] == 'B') || (myNote[myNote.length()-1] == '#') ){
		alter = new QGraphicsTextItem();
		alter->setTransform(QTransform::fromTranslate(pos().x()-10,pos().y()+5));
        alter->setPlainText(QString((myNote[myNote.length()-1] == 'B')?"b":"#"));
		if(noteState == wrong)
				alter->setDefaultTextColor(QColor(212, 27, 27));
		if(noteState == correct)
				alter->setDefaultTextColor(QColor(119, 212, 27));
		parent->addItem(alter);
	}
}

void EzTextNote::transformB(std::string & dNote){
	std::string noteStart = dNote.substr(0,2);
	if(noteStart == "DO"){dNote = "RE" + dNote.substr(2,1) + "B";}
	else if(noteStart == "RE"){dNote = "MI" + dNote.substr(2,1) + "B";}
	else if(noteStart == "MI"){dNote = "FA" + dNote.substr(2,1) + "B";}
	else if(noteStart == "FA"){dNote = "SOL" + dNote.substr(2,1) + "B";}
	else if(noteStart == "SO"){dNote = "LA" + dNote.substr(3,1) + "B";}
	else if(noteStart == "LA"){dNote = "SI" + dNote.substr(2,1) + "B";}
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

std::string EzTextNote::getMyNote(){
	return myNote;
}

std::string EzTextNote::getRealNote(){
	return realNote->getNote();
}
