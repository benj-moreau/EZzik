#include "../include/EZreset.hpp"

EzReset::EzReset():QPushButton(){
	indexToReset = -1;
	setMaximumSize(QSize(50,50));
	setMinimumSize(QSize(50,50));
	setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
	QPixmap pixmap("icons/QuickRestart.png");
	QIcon btnIcon(pixmap.scaled(80, 80, Qt::IgnoreAspectRatio, Qt::FastTransformation));
	setIcon(btnIcon);

	QObject::connect(this,SIGNAL(clicked()),this,SLOT(clickControl()));
}
EzReset::~EzReset(){}

void EzReset::newDir(){
	indexToReset = -1; // in case user is opening a directory without valid scores
}

void EzReset::newValidIndex(int ind){
	indexToReset = ind;
}

void EzReset::clickControl(){
	if(indexToReset >= 0)
		emit(sendReset(indexToReset));
}
