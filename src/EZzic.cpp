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

	QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(scoreView);
    mainLayout->addWidget(pianoView);

    QWidget *w = new QWidget();
    
    w->setLayout(mainLayout);

    w->setWindowTitle("EZzik");
    w->setWindowIcon(QIcon("res/icone.png"));

    w->setMinimumWidth(325);
    w->setMinimumHeight(310);
    
    w->show();
    
    return app.exec();
}

