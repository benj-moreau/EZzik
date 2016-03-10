#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPen>
#include <QBrush>
#include <QColor>

#include "../include/EZpiano.hpp"
#include "../include/EZpianoview.hpp"
#include "../include/EZscore.hpp"
#include "../include/EZscoreview.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    EzPiano *Pianoscene = new EzPiano();
    EzPianoView *pianoView = new EzPianoView(Pianoscene);
    pianoView->setStyleSheet("background: transparent; border-style: none;");
    EzScore *scoreScene = new EzScore();
    EzScoreView *scoreView = new EzScoreView(scoreScene);

    //score load exemple : JASONE
    std::vector<std::string> notes;
    notes.push_back("DO1");
    notes.push_back("RE1");
    notes.push_back("MI1");
    notes.push_back("FA1");
    notes.push_back("SOL1");
    notes.push_back("LA1");
    notes.push_back("SI1");
    notes.push_back("DO2");
    notes.push_back("RE2");
    notes.push_back("MI2");
    notes.push_back("FA2");
    notes.push_back("SOL2");
    notes.push_back("LA2");
    notes.push_back("SI2");
    scoreScene->setNotes(notes);
    scoreScene->getNote(0)->setState(wrong);
    scoreScene->getNote(1)->setState(correct);


	QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(scoreView);
    mainLayout->addWidget(pianoView);

    QWidget *w = new QWidget();
    
    w->setLayout(mainLayout);

    w->setWindowTitle("EZzik");
    w->setWindowIcon(QIcon("res/icone.png"));

    w->setMinimumWidth(400);
    w->setMinimumHeight(310);
    
    w->show();
    
    return app.exec();
}

