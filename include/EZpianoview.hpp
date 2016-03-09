#ifndef EZPIANOVIEW_HPP
#define EZPIANOVIEW_HPP

#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QString>
#include "EZkey.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
	
class EzPianoView : public QGraphicsView{
	public : EzPianoView(QGraphicsScene*);
	 		~EzPianoView();
			void mousePressEvent(QMouseEvent * mouseEvent);
	private:
};

#endif

