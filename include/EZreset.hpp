#ifndef EZRESET_HPP
#define EZRESET_HPP

#include <QPushButton>
#include <QString>
#include <QPen>
#include <QList>
#include <QGraphicsItem>
#include <iostream>
#include <string>
#include <vector>


class EzReset : public QPushButton{
	Q_OBJECT
    public :
        EzReset();
        ~EzReset();

	signals:
		void sendReset(int);
		
	public slots:
		void clickControl();
		void newDir();
		void newValidIndex(int);

	private :
		int indexToReset;
};

#endif
