#ifndef EZSELECTION_HPP
#define EZSELECTION_HPP

#include <QMessageBox>
#include <QComboBox>
#include <QString>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <dirent.h>
#include <vector>
#include <sys/types.h>
	
class EzSelection : public QComboBox{
	Q_OBJECT
    public :
        EzSelection();
        ~EzSelection();
		int setDirPath(std::string);
		
	public slots:
		void recieveDir(QString);
		void selectedScore(int);

	signals:
		void sendScore(std::vector<std::string>);

	private:
		std::string dirPath;
		int updateList();
};

#endif
