#ifndef EZHELPBUTTON_HPP
#define EZHELPBUTTON_HPP

#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsTextItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "EZhelp.hpp"

class EzHelpButton : public QPushButton{
	Q_OBJECT
	public:
		 EzHelpButton();
		 ~EzHelpButton();
		
	public slots:
		void displayHelp();
};

#endif
