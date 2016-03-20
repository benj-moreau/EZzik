#include "../include/EZhelpbutton.hpp"

EzHelpButton::EzHelpButton():QPushButton(){
	setMaximumSize(QSize(50,50));
	setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
	QPixmap pixmap("icons/help.png");
	QIcon btnIcon(pixmap.scaled(60, 60, Qt::IgnoreAspectRatio, Qt::FastTransformation));
	setIcon(btnIcon);
	QObject::connect(this,SIGNAL(clicked()),this,SLOT(displayHelp()));
}
EzHelpButton::~EzHelpButton(){}

void EzHelpButton::displayHelp(){
	EzHelp *help = new EzHelp();
	help->show();
}
