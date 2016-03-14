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
#include <QPoint>

#define TONE_WIDTH 11
#define TONE_HEIGHT 10

enum NoteState {neutral, correct, wrong};
enum NoteAlteration {none, diese, bemol};

class EzNote : public QGraphicsEllipseItem{
    public :
        EzNote(std::string, NoteAlteration, int, int, QGraphicsScene*);
        ~EzNote();
		QGraphicsTextItem* getAlter();
        std::string getNote();
		NoteState getState();
		QPen getPen();
		QPoint getPos();
        void setState(NoteState);

	private:
        std::string _note;
        NoteState _state;
		QGraphicsTextItem *alter;
		QGraphicsLineItem *line;
	
};

#endif
