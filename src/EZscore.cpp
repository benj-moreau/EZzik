#include "../include/EZscore.hpp"

EzScore::EzScore(){
    for(int i=1;i<=5;++i){
        this->addItem(new QGraphicsLineItem(0,SCORE_INNERLINE*i,SCORE_LENGTH,SCORE_INNERLINE*i));
    }
   //scaled set the proportion of the key in comparaison of score innerline
   QGraphicsPixmapItem *solKey = this->addPixmap((QPixmap("res/cleSol.png").scaled(SCORE_INNERLINE*4,SCORE_INNERLINE*8)));
   //sol key is up of 1 innerline
   solKey->setOffset(0,-SCORE_INNERLINE);
}
EzScore::~EzScore(){}

void EzScore::setNotes(std::vector<std::string> notes){
    std::vector<EzNote*> newNotes;
    //begin right after the sol key
    float x = SCORE_INNERLINE*5;
    float space = (SCORE_LENGTH-x)/notes.size();
    float y = 0;
    //y position on score
    for(int i=notes.size()-1;i>=0;--i){
        if (notes[i]=="DO1"){y=5.5*SCORE_INNERLINE;}
        else if (notes[i]=="RE1"){y=5*SCORE_INNERLINE;}
        else if (notes[i]=="MI1"){y=4.5*SCORE_INNERLINE;}
        else if (notes[i]=="FA1"){y=4*SCORE_INNERLINE;}
        else if (notes[i]=="SOL1"){y=3.5*SCORE_INNERLINE;}
        else if (notes[i]=="LA1"){y=3*SCORE_INNERLINE;}
        else if (notes[i]=="SI1"){y=2.5*SCORE_INNERLINE;}
        else if (notes[i]=="DO2"){y=2*SCORE_INNERLINE;}
        else if (notes[i]=="RE2"){y=1.5*SCORE_INNERLINE;}
        else if (notes[i]=="MI2"){y=1*SCORE_INNERLINE;}
        else if (notes[i]=="FA2"){y=0.5*SCORE_INNERLINE;}
        else if (notes[i]=="SOL2"){y=0*SCORE_INNERLINE;}
        else if (notes[i]=="LA2"){y=-0.5*SCORE_INNERLINE;}
        else if (notes[i]=="SI2"){y=-1.0*SCORE_INNERLINE;}
        else{y=5.5*SCORE_INNERLINE;}
        newNotes.push_back(new EzNote(notes[i],x,y,this));
        x += space;
    }
    _notes = newNotes;
}

EzNote* EzScore::getNote(int i){
    return _notes[i];
}
