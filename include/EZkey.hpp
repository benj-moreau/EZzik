#ifndef EZKEY_HPP
#define EZKEY_HPP

#include <QGraphicsItem>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QString>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <iostream>
#include <string>

#define WHITE_WIDTH 20
#define WHITE_HEIGHT 80
#define BLACK_WIDTH 10
#define BLACK_HEIGHT 50

class EzKey : public QGraphicsRectItem{
	public : EzKey(std::string, std::string, int, int, QGraphicsScene*);
	 		~EzKey();
			
			std::string getNote();
			void setNote(std::string);
			std::string getColor();

	private:
		std::string _note;
		std::string _color;
		
};

#endif
