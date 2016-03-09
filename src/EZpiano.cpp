#include "../include/EZpiano.hpp"

EzPiano::EzPiano(){

	QGraphicsScene();
	board.push_back(new EzKey("white","DO",0,0,this));
	board.push_back(new EzKey("white","RE",20,0,this));
	board.push_back(new EzKey("white","MI",40,0,this));
	board.push_back(new EzKey("white","FA",60,0,this));
	board.push_back(new EzKey("white","SOL",80,0,this));
	board.push_back(new EzKey("white","LA",100,0,this));
	board.push_back(new EzKey("white","SI",120,0,this));

	board.push_back(new EzKey("black","DO#",15,0,this));
	board.push_back(new EzKey("black","RE#",35,0,this));
	board.push_back(new EzKey("black","FA#",75,0,this));
	board.push_back(new EzKey("black","SOL#",95,0,this));
	board.push_back(new EzKey("black","LA#",115,0,this));
}
EzPiano::~EzPiano(){}

void EzPiano::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent){
	int xSPos = mouseEvent->lastScenePos().x(), ySPos = mouseEvent->lastScenePos().y();
	if(itemAt(xSPos,ySPos) != NULL){
		dynamic_cast<EzKey*>(itemAt(xSPos,ySPos))->testPass();
	}
}
