#ifndef EZTEXTNOTE_HPP
#define EZTEXTNOTE_HPP

#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsScene>
#include <QString>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <iostream>
#include <string>

#include "EZnote.hpp"
#include "EZnotenames.hpp"

class EzNoteNames;

class EzTextNote : public QGraphicsSimpleTextItem{
	public:	
		EzTextNote(EzNote*, QGraphicsScene*);
		~EzTextNote();
		void setNote(EzNote*);
		void setNeutral();
		void setWrong();
		void setRight();
		void updateNote(std::string key, EzNoteNames*);
		bool checkState();
		NoteState getState();
		std::string getMyNote();
		std::string getRealNote();
	private:
		EzNote* realNote;
		std::string myNote;
		QGraphicsSimpleTextItem *alter;
		NoteState noteState;
		void transformB(std::string & dNote);
};

#endif
