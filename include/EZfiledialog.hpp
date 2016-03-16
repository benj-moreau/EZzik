#ifndef EZFILEDIALOG_HPP
#define EZFILEDIALOG_HPP

#include <QMessageBox>
#include <QPushButton>
#include <QSizePolicy>
#include <QFileDialog>
#include <QString>
#include <QSize>
#include <string>
#include <iostream>
	
#include "EZselection.hpp"

class EzFileDialog : public QPushButton{
	Q_OBJECT
    public :
        EzFileDialog();
        ~EzFileDialog();

	public slots:
		void clickEvent();

	signals:
		void sendDir(QString);
};

#endif
