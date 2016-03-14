#ifndef EZTEXTNOTE_HPP
#define EZTEXTNOTE_HPP

#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QString>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <iostream>
#include <string>

#include "EZnote.hpp"

class EzTextNote : public QGraphicsTextItem{
	public:	
		EzTextNote(EzNote*, QGraphicsScene*);
		~EzTextNote();
		void setNote(EzNote*);
		void setNeutral();
		void setWrong();
		void setRight();
		void updateNote(std::string key);

	private:
		EzNote* realNote;
		QGraphicsTextItem *alter;
		
};

#endif
