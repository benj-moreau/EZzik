#ifndef EZPIANO_HPP
#define EZPIANO_HPP
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QString>
#include <QSound>
#include <QTransform>
/*#include <Phonon/MediaObject>
#include <Phonon/AudioOutput>
#include <Phonon/VideoWidget>
#include <Phonon/MediaSource>*/
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
			void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
	signals:
		void sendKey(std::string);

	private:
		std::vector<EzKey*> board;
		
		//Phonon::MediaObject *mediaObject;
		//Phonon::MediaSource *mediaSource;
		//Phonon::VideoWidget *videoWidget;
		//Phonon::AudioOutput *audioOutput;
};

#endif
