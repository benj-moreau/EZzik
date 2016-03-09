#ifndef EZPIANO_HPP
#define EZPIANO_HPP
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QString>
#include "EZkey.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
	
class EzPiano : public QGraphicsScene{
	public : EzPiano();
	 		~EzPiano();
			void mousePressEvent(QGraphicsSceneMouseEvent*);

	private:
		std::vector<EzKey*> board;
};

#endif
