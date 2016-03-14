#ifndef EZNOTENAMESVIEW_HPP
#define EZNOTENAMESVIEW_HPP

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QString>

#include <iostream>
	
class EzNoteNamesView : public QGraphicsView{
    public :
        EzNoteNamesView(QGraphicsScene*);
        ~EzNoteNamesView();
	private:
};

#endif
