#include "../include/EZscore.hpp"

EzScore::EzScore(){
	currentNoteIndex = 0;
    for(int i=1;i<=5;++i){
        this->addItem(new QGraphicsLineItem(0,SCORE_INNERLINE*i,SCORE_LENGTH,SCORE_INNERLINE*i));
    }
	//scaled set the proportion of the key in comparaison of score innerline
	QGraphicsPixmapItem *solKey = this->addPixmap((QPixmap("res/cleSol.png").scaled(SCORE_INNERLINE*4,SCORE_INNERLINE*8,Qt::KeepAspectRatio,Qt::SmoothTransformation)));
	//sol key is up of 1 innerline
    solKey->setOffset(0,-SCORE_INNERLINE);

    QPen pen;
    pen.setWidth(3);
    pen.setCapStyle(Qt::RoundCap);
    lineSup = new QGraphicsLineItem();
    lineSup->setPen(pen);
    lineInf = new QGraphicsLineItem();
    lineInf->setPen(pen);
    addItem(lineSup);
    addItem(lineInf);

}
EzScore::~EzScore(){}

void EzScore::setNotes(std::vector<std::string> notes){
	int notesSize = _notes.size();
	for(int i = 0; i < notesSize; ++i){
		delete _notes[i];
	}
	for(int i = 0; i < notesSize; ++i){
		_notes.pop_back();
	}
    std::vector<EzNote*> newNotes;
    //begin right after the sol key
    float x = SCORE_INNERLINE*5;
    float space = (SCORE_LENGTH-x)/notes.size();
    float y = 0;
    NoteAlteration alter;
    //y position on score
    for(int i=notes.size()-1;i>=0;--i){
        if (notes[i]=="DO1"){y=5.5*SCORE_INNERLINE;}
        else if (notes[i].substr(0,3)=="RE1"){y=5*SCORE_INNERLINE;}
        else if (notes[i].substr(0,3)=="MI1"){y=4.5*SCORE_INNERLINE;}
        else if (notes[i].substr(0,3)=="FA1"){y=4*SCORE_INNERLINE;}
        else if (notes[i].substr(0,4)=="SOL1"){y=3.5*SCORE_INNERLINE;}
        else if (notes[i].substr(0,3)=="LA1"){y=3*SCORE_INNERLINE;}
        else if (notes[i].substr(0,3)=="SI1"){y=2.5*SCORE_INNERLINE;}
        else if (notes[i].substr(0,3)=="DO2"){y=2*SCORE_INNERLINE;}
        else if (notes[i].substr(0,3)=="RE2"){y=1.5*SCORE_INNERLINE;}
        else if (notes[i].substr(0,3)=="MI2"){y=1*SCORE_INNERLINE;}
        else if (notes[i].substr(0,3)=="FA2"){y=0.5*SCORE_INNERLINE;}
        else if (notes[i].substr(0,4)=="SOL2"){y=0*SCORE_INNERLINE;}
        else if (notes[i].substr(0,3)=="LA2"){y=-0.5*SCORE_INNERLINE;}
        else if (notes[i].substr(0,3)=="SI2"){y=-1.0*SCORE_INNERLINE;}
        else{y=5.5*SCORE_INNERLINE;}
        if (notes[i][notes[i].length()-1]=='B'){alter = bemol;}
        else if(notes[i][notes[i].length()-1]=='#'){alter = diese;}
        else{alter=none;}
        newNotes.push_back(new EzNote(notes[i],alter,x,y,this));
        x += space;
    }
    _notes = newNotes;
	if(_notes.size() > 0)
		drawBar(0);
	emit sendTextNotes(_notes);
}

EzNote* EzScore::getNote(int i){
    return _notes[i];
}

void EzScore::drawBar(int ind){
	int sizeN = _notes.size();
	if(ind < sizeN){
		QPointF pos = _notes[ind]->getPos();
        lineSup->setLine(pos.x()+5,-SCORE_INNERLINE*2,pos.x()+5,-SCORE_INNERLINE);
        lineInf->setLine(pos.x()+5,SCORE_INNERLINE*7,pos.x()+5,SCORE_INNERLINE*8);
	}
}

void EzScore::recieveNotes(std::vector<std::string> notes){ setNotes(notes); }
