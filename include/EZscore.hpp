#ifndef EZSCORE_HPP
#define EZSCORE_HPP

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QString>
#include <QPen>

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

        /* string note format : NOTE(1|2)[#|B] ex: SOL1# LA2 LA1B ... */
        void setNotes(std::vector<std::string>);
        EzNote* getNote(int);

	private:
        std::vector<EzNote*> _notes;
};

#endif
