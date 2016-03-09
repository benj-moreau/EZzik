#ifndef EZSCORE_HPP
#define EZSCORE_HPP

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QString>

#include <iostream>
#include <string>
#include <vector>

#define SCORE_LENGTH 300
#define SCORE_INNERLINE 10


#include "EZnote.hpp"
	
class EzScore : public QGraphicsScene{
    public :
        EzScore();
        ~EzScore();

	private:
        std::vector<EzNote*> _notes;
        void setNotes(std::vector<std::string>);
};

#endif
