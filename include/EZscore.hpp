#ifndef EZSCORE_HPP
#define EZSCORE_HPP

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QString>

#include <iostream>
#include <string>
#include <vector>

#define SCORE_LENGTH 400
#define SCORE_INNERLINE TONE_HEIGHT


#include "EZnote.hpp"
	
class EzScore : public QGraphicsScene{
    public :
        EzScore();
        ~EzScore();
        void setNotes(std::vector<std::string>);
        EzNote* getNote(int);

	private:
        std::vector<EzNote*> _notes;
};

#endif
