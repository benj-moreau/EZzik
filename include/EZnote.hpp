#ifndef EZNOTE_HPP
#define EZNOTE_HPP

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QString>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <iostream>
#include <string>

#define TONE_WIDTH 10
#define TONE_HEIGHT 10

enum NoteState {neutral, correct, wrong};

class EzNote : public QGraphicsEllipseItem{
    public :
        EzNote(std::string, int, int, QGraphicsScene*);
        ~EzNote();
			
        std::string getNote();
        void setState(NoteState);

	private:
        std::string _note;
        NoteState _state;
	
};

#endif
