#include "../include/EZfiledialog.hpp"

EzFileDialog::EzFileDialog():QPushButton(){
	setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Ignored);
	QPixmap pixmap("icons/Folder_Up.png");
	QIcon btnIcon(pixmap);
	setIcon(btnIcon);
	setIconSize(pixmap.rect().size());
	connect(this,SIGNAL(clicked()),this,SLOT(clickEvent()));
}
EzFileDialog::~EzFileDialog(){}

void EzFileDialog::clickEvent(){
	QString dir = QFileDialog::getExistingDirectory(new QWidget, tr("Open directory"), ".", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if(dir != NULL)	
		emit sendDir(dir);
}
