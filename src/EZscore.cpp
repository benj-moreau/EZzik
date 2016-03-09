#include "../include/EZscore.hpp"

EzScore::EzScore(){
    for(int i=1;i<=5;++i){
        this->addItem(new QGraphicsLineItem(2,SCORE_INNERLINE*i,SCORE_LENGTH,SCORE_INNERLINE*i));
    }
   //scaled set the proportion of the key in comparaison of score innerline
   QGraphicsPixmapItem *solKey = this->addPixmap((QPixmap("res/cleSol.png").scaled(SCORE_INNERLINE*4,SCORE_INNERLINE*8)));
   //sol key is up of 1 innerline
   solKey->setOffset(0,-SCORE_INNERLINE);
}
EzScore::~EzScore(){}

void EzScore::setNotes(std::vector<std::string> notes){

}
