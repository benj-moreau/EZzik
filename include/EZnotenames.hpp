#ifndef EZNOTENAMES_HPP
#define EZNOTENAMES_HPP

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QString>
#include <QPen>
#include <QList>
#include <QGraphicsItem>
#include <iostream>
#include <string>
#include <vector>

#include "EZtextnote.hpp"
#include "EZnote.hpp"

class EzNoteNames : public QGraphicsScene{
	Q_OBJECT
    public :
        EzNoteNames();
        ~EzNoteNames();

        EzTextNote* getNote(int);
	
	public slots:
		void recieveTextNotes(std::vector<EzNote*>);
		void recievePianoKey(std::string);

	private:
        std::vector<EzTextNote*> notes;
		int currentNoteIndex;
};

#endif
