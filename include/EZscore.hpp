#ifndef EZSCORE_HPP
#define EZSCORE_HPP

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QString>
#include <QPen>
#include <QList>
#include <QGraphicsItem>
#include <iostream>
#include <string>
#include <vector>

#define SCORE_LENGTH 400
#define SCORE_INNERLINE TONE_HEIGHT


#include "EZnote.hpp"
	
class EzScore : public QGraphicsScene{
	Q_OBJECT
    public :
        EzScore();
        ~EzScore();

        /* string note format : NOTE(1|2)[#|B] ex: SOL1# LA2 LA1B ... */
        void setNotes(std::vector<std::string>);
        EzNote* getNote(int);
	
	public slots:
		void recieveNotes(std::vector<std::string>);
	
	signals:
		void sendTextNotes(std::vector<EzNote*>);

	private:
        std::vector<EzNote*> _notes;
		int currentNoteIndex;
};

#endif
