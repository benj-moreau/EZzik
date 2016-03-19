#include "../include/EZfiledialog.hpp"

EzFileDialog::EzFileDialog():QPushButton(){
	setMaximumSize(QSize(50,50));
	setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
	QPixmap pixmap("icons/Folder_Up.png");
	QIcon btnIcon(pixmap.scaled(60, 60, Qt::IgnoreAspectRatio, Qt::FastTransformation));
	setIcon(btnIcon);
	QObject::connect(this,SIGNAL(clicked()),this,SLOT(clickEvent()));
}
EzFileDialog::~EzFileDialog(){}

void EzFileDialog::clickEvent(){
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open directory"), ".", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if(dir != NULL)	
		emit sendDir(dir);
}
