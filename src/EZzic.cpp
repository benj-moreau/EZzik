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
#include "../include/EZkey.hpp"
#include "../include/EZpianoview.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

	EzPiano *scene = new EzPiano();
	EzPianoView *view = new EzPianoView(scene);


	//QHBoxLayout *hLayout = new QHBoxLayout();
	//hLayout->addWidget(view);

	QVBoxLayout *mainLayout = new QVBoxLayout();
	//mainLayout->addLayout(hLayout);
	mainLayout->addWidget(view);

    // Create a widget
    QWidget *w = new QWidget();
    
    // Set the outer layout as a main layout 
    // of the widget
    w->setLayout(mainLayout);

    // Window title
    w->setWindowTitle("EZzic");
    
    // Display
    w->show();
    
    // Event loop
    return app.exec();
}

