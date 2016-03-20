#ifndef EZHELP_HPP
#define EZHELP_HPP

#include <iostream>
#include <QFrame>
#include <QWidget>
#include <QGraphicsTextItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsSimpleTextItem>

class EzHelp : public QWidget{
	Q_OBJECT
	public:
		 EzHelp();
		 ~EzHelp();

	private:
		QLabel *imagePanel;
};

#endif
