#include "../include/EZpiano.hpp"

EzPiano::EzPiano(){
	board.push_back(new EzKey("white","DO1",0,0,this));
	board.push_back(new EzKey("white","RE1",20,0,this));
	board.push_back(new EzKey("white","MI1",40,0,this));
	board.push_back(new EzKey("white","FA1",60,0,this));
	board.push_back(new EzKey("white","SOL1",80,0,this));
	board.push_back(new EzKey("white","LA1",100,0,this));
	board.push_back(new EzKey("white","SI1",120,0,this));

	board.push_back(new EzKey("black","DO1#",15,0,this));
	board.push_back(new EzKey("black","RE1#",35,0,this));
	board.push_back(new EzKey("black","FA1#",75,0,this));
	board.push_back(new EzKey("black","SOL1#",95,0,this));
	board.push_back(new EzKey("black","LA1#",115,0,this));

	board.push_back(new EzKey("white","DO2",140,0,this));
	board.push_back(new EzKey("white","RE2",160,0,this));
	board.push_back(new EzKey("white","MI2",180,0,this));
	board.push_back(new EzKey("white","FA2",200,0,this));
	board.push_back(new EzKey("white","SOL2",220,0,this));
	board.push_back(new EzKey("white","LA2",240,0,this));
	board.push_back(new EzKey("white","SI2",260,0,this));

	board.push_back(new EzKey("black","DO2#",155,0,this));
	board.push_back(new EzKey("black","RE2#",175,0,this));
	board.push_back(new EzKey("black","FA2#",215,0,this));
	board.push_back(new EzKey("black","SOL2#",235,0,this));
	board.push_back(new EzKey("black","LA2#",255,0,this));

	mediaObject = new Phonon::MediaObject();
	mediaSource = new Phonon::MediaSource();
    videoWidget = new Phonon::VideoWidget();
    Phonon::createPath(mediaObject, videoWidget);
    audioOutput = new Phonon::AudioOutput(Phonon::VideoCategory);
    Phonon::createPath(mediaObject, audioOutput);
	mediaSource = new Phonon::MediaSource();
	mediaObject->setCurrentSource(*mediaSource);
}
EzPiano::~EzPiano(){
	delete mediaObject;
	delete mediaSource;
	delete videoWidget;
	delete audioOutput;
	delete mediaSource;
}

void EzPiano::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent){
	int xSPos = mouseEvent->lastScenePos().x(), ySPos = mouseEvent->lastScenePos().y();
	QGraphicsItem *clickedItem = itemAt(xSPos,ySPos);
	EzKey *clickedKey;
	if(clickedItem != NULL){
		clickedItem = itemAt(xSPos,ySPos);
		clickedKey = dynamic_cast<EzKey*>(itemAt(xSPos,ySPos));
	
		delete mediaSource;
		mediaSource = new Phonon::MediaSource(QString("sounds/") + QString::fromStdString(clickedKey->getNote()) + QString(".wav"));
		mediaObject->setCurrentSource(*mediaSource);
		mediaObject->play();

		emit sendKey(clickedKey->getNote());
	}
}

