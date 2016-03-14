#include "../include/EZnotenames.hpp"
EzNoteNames::EzNoteNames(){
	currentNoteIndex = 0;
}
EzNoteNames::~EzNoteNames(){}

EzTextNote* EzNoteNames::getNote(int ind){
	return notes[ind];
}

void EzNoteNames::recieveTextNotes(std::vector<EzNote*> realNotes){
	int notesSize = notes.size();
	for(int i = 0; i < notesSize; ++i){
		delete notes[i];
	}
	notesSize = realNotes.size();
	for(int i = 0; i < notesSize; ++i){
		notes.push_back(new EzTextNote(realNotes[i],this));
	}
}

void EzNoteNames::recievePianoKey(std::string key){
	notes[currentNoteIndex]->updateNote(key);
}
