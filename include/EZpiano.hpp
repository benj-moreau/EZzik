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
	Q_OBJECT
	public : EzPiano();
	 		~EzPiano();
			void mousePressEvent(QGraphicsSceneMouseEvent*);

	signals:
		void sendKey(std::string);

	private:
		std::vector<EzKey*> board;
};

#endif
