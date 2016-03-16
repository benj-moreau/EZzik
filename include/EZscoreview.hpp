#ifndef EZSCOREVIEW_HPP
#define EZSCOREVIEW_HPP

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QString>

#include <iostream>
	
class EzScoreView : public QGraphicsView{
    public :
        EzScoreView(QGraphicsScene*);
        ~EzScoreView();
		void resizeEvent(QResizeEvent *);
	private:
};

#endif

