#include "../include/EZnotenames.hpp"

EzNoteNames::EzNoteNames():QGraphicsScene(){
	init();
}
EzNoteNames::~EzNoteNames(){}

void EzNoteNames::init(){
	currentNoteIndex = 0;
	nbRight = 0;
	nbErrors = 0;
	over = false;
	firstNote = true;
	isCorrectedOnce = false;
}


EzTextNote* EzNoteNames::getNote(int ind){
	return notes[ind];
}

std::vector<EzTextNote*>  EzNoteNames::getNotes(){
	return notes;
}

void EzNoteNames::recieveTextNotes(std::vector<EzNote*> realNotes){
	int notesSize = notes.size();
	init();

	for(int i = 0; i < notesSize; ++i){
		removeItem(notes[i]);
		delete notes[i];
	}
	for(int i = 0; i < notesSize; ++i){
		notes.pop_back();
	}
	notesSize = realNotes.size();
	for(int i = 0; i < notesSize; ++i){
        EzTextNote *note = new EzTextNote(realNotes[i],this);
        notes.push_back(note);
	}
}

void EzNoteNames::recievePianoKey(std::string key){
	int notesSize = notes.size();
	double duration;

	if(firstNote){
		firstNote = false;
		start = std::clock();
	}
	if(!over){
		if(notesSize > 0){
			notes[currentNoteIndex]->updateNote(key,this);
			currentNoteIndex = isCorrectedOnce?getNextWrong():currentNoteIndex+1;
			if(currentNoteIndex >= notesSize){
				correct();
				isCorrectedOnce = true;
				if(nbRight >= notesSize){
					over = true;

					duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC * 100;
                    QString result = QString("Vous avez mis <strong>")  + QString::number(duration) + QString(" secondes</strong> à déchiffrer la partition<br/>");
                    result += QString("Vous avez fait <strong>")  + QString::number(nbErrors) + QString(" erreurs</strong><br/>Sur une partition de <strong>") +
                    QString::number(notes.size()) + QString(" notes</strong>");
					QMessageBox::information(new QWidget(), QString("Statistiques de la partition"), result);
				}else{
					currentNoteIndex = getNextWrong();
				}
			}
		}
		emit(sendNewInd(currentNoteIndex));
	}
}

void EzNoteNames::correct(){
	int notesSize = notes.size();
	int currentNoteIndex = 0;
	while(currentNoteIndex < notesSize){
		if(notes[currentNoteIndex]->getState() == wrong || notes[currentNoteIndex]->getState() == neutral)
			nbRight = notes[currentNoteIndex]->checkState()?nbRight+1:nbRight;
		++currentNoteIndex;
	}
}

int EzNoteNames::getNextWrong(){
	int notesSize = notes.size();
	int next = (currentNoteIndex >= notesSize)?0:currentNoteIndex+1;
	while(next < notesSize && (notes[next]->getState() != wrong)){
		++next;
	}
	if(next < notesSize){
		++ nbErrors;
	}
	return next;
}
