#include <QApplication>
#include <QObject>
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
#include <QString>

#include <vector>

#include "../include/EZpiano.hpp"
#include "../include/EZpianoview.hpp"
#include "../include/EZscore.hpp"
#include "../include/EZscoreview.hpp"
#include "../include/EZselection.hpp"
#include "../include/EZfiledialog.hpp"
#include "../include/EZtextnote.hpp"
#include "../include/EZnotenames.hpp"
#include "../include/EZnotenamesview.hpp"
#include "../include/EZreset.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    EzPiano *Pianoscene = new EzPiano();
    EzPianoView *pianoView = new EzPianoView(Pianoscene);
    pianoView->setStyleSheet("background: transparent; border-style: none;");

    EzScore *scoreScene = new EzScore();
    EzScoreView *scoreView = new EzScoreView(scoreScene);
	EzNoteNames *enm = new EzNoteNames();
    EzNoteNamesView *enmv = new EzNoteNamesView(enm);
    enmv->setStyleSheet("background: transparent; border-style: none;");

	EzSelection *ezselect = new EzSelection();
	EzFileDialog *ezfd = new EzFileDialog();

	EzReset *er = new EzReset();

	QObject::connect(ezfd,SIGNAL(sendDir(QString)),ezselect,SLOT(recieveDir(QString)));
	QObject::connect(ezselect,SIGNAL(sendScore(std::vector<std::string>)),scoreScene,SLOT(recieveNotes(std::vector<std::string>)));

	QObject::connect(scoreScene, SIGNAL(sendTextNotes(std::vector<EzNote*>)), enm, SLOT(recieveTextNotes(std::vector<EzNote*>)));
	QObject::connect(Pianoscene, SIGNAL(sendKey(std::string)), enm, SLOT(recievePianoKey(std::string)));

	QObject::connect(ezselect, SIGNAL(sendNewDir()), er, SLOT(newDir()));
	QObject::connect(ezselect, SIGNAL(sendNewValidInd(int)), er, SLOT(newValidIndex(int)));
	QObject::connect(er, SIGNAL(sendReset(int)), ezselect, SLOT(selectedScore(int)));

	QObject::connect(enm, SIGNAL(sendNewInd(int)), scoreScene, SLOT(drawBar(int)));

	QVBoxLayout *mainLayout = new QVBoxLayout();
	QHBoxLayout *scoreChooseLayout = new QHBoxLayout();
	
	scoreChooseLayout->addWidget(er);
	scoreChooseLayout->addWidget(ezselect);
	scoreChooseLayout->addWidget(ezfd);
	
	mainLayout->addLayout(scoreChooseLayout);
    mainLayout->addWidget(scoreView,1);
    mainLayout->addWidget(enmv);
    mainLayout->addWidget(pianoView,1);
    QWidget *w = new QWidget();
    
    w->setLayout(mainLayout);

    w->setWindowTitle("EZzik");
    w->setWindowIcon(QIcon("res/icone.png"));

    w->setMinimumWidth(430);
    w->setMinimumHeight(350);
    
    w->show();
    
    return app.exec();
}

