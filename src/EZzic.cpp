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

    EzPiano *pianoScene = new EzPiano();
    EzPianoView *pianoView = new EzPianoView(pianoScene);
    pianoView->setStyleSheet("background: transparent; border-style: none;");

    EzScore *scoreScene = new EzScore();
    EzScoreView *scoreView = new EzScoreView(scoreScene);

	EzNoteNames *noteNames = new EzNoteNames();
    EzNoteNamesView *noteNamesView = new EzNoteNamesView(noteNames);
    noteNamesView->setStyleSheet("background: transparent; border-style: none;");

	EzSelection *selection = new EzSelection();
	EzFileDialog *fileDialog = new EzFileDialog();

	EzReset *reset = new EzReset();

	QObject::connect(fileDialog,SIGNAL(sendDir(QString)),selection,SLOT(recieveDir(QString)));
	QObject::connect(selection,SIGNAL(sendScore(std::vector<std::string>)),scoreScene,SLOT(recieveNotes(std::vector<std::string>)));

	QObject::connect(scoreScene, SIGNAL(sendTextNotes(std::vector<EzNote*>)), noteNames, SLOT(recieveTextNotes(std::vector<EzNote*>)));
	QObject::connect(pianoScene, SIGNAL(sendKey(std::string)), noteNames, SLOT(recievePianoKey(std::string)));

	QObject::connect(selection, SIGNAL(sendNewDir()), reset, SLOT(newDir()));
	QObject::connect(selection, SIGNAL(sendNewValidInd(int)), reset, SLOT(newValidIndex(int)));
	QObject::connect(reset, SIGNAL(sendReset(int)), selection, SLOT(selectedScore(int)));

	QObject::connect(noteNames, SIGNAL(sendNewInd(int)), scoreScene, SLOT(drawBar(int)));

	QVBoxLayout *mainLayout = new QVBoxLayout();
	QHBoxLayout *scoreChooseLayout = new QHBoxLayout();
	
	scoreChooseLayout->addWidget(reset);
	scoreChooseLayout->addWidget(selection);
	scoreChooseLayout->addWidget(fileDialog);
	
	mainLayout->addLayout(scoreChooseLayout);
    mainLayout->addWidget(scoreView,1);
    mainLayout->addWidget(noteNamesView);
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

