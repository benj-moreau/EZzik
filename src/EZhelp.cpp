#include "../include/EZhelp.hpp"

EzHelp::EzHelp():QWidget(){
	QHBoxLayout *mainHLayout = new QHBoxLayout();
	QVBoxLayout *mainVLayout = new QVBoxLayout();
	QHBoxLayout *horizLayout = new QHBoxLayout();
	
	// picture	
	QPixmap *pixmap = new QPixmap("icons/EZzikHelp.png");
	QLabel *imagePanel = new QLabel();
	imagePanel->setPixmap(pixmap->scaled(imagePanel->width(),imagePanel->height(),Qt::KeepAspectRatio));
	imagePanel->setFixedWidth(460);
	mainHLayout->addWidget(imagePanel);

	// rule 1
	QLabel *idLabel = new QLabel();
	idLabel->setFixedWidth(20);
	idLabel->setFixedHeight(20);
	idLabel->setText("1");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 16,60)));
	idLabel->setStyleSheet("QLabel { color : red; }");
	horizLayout->addWidget(idLabel);
	idLabel = new QLabel();
	idLabel->setText(" clickez ce bouton pour réinitialiser\n la partition courante");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 14,40)));
	idLabel->setStyleSheet("QLabel { color : black; }");
	horizLayout->addWidget(idLabel);
	mainVLayout->addLayout(horizLayout);

	// rule 2
	horizLayout = new QHBoxLayout(); 
	idLabel = new QLabel();
	idLabel->setFixedWidth(20);
	idLabel->setFixedHeight(20);
	idLabel->setText("2");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 16,60)));
	idLabel->setStyleSheet("QLabel { color : red; }");
	horizLayout->addWidget(idLabel);
	idLabel = new QLabel();
	idLabel->setText(" clickez ici pour choisir la partition courante");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 14,40)));
	idLabel->setStyleSheet("QLabel { color : black; }");
	horizLayout->addWidget(idLabel);
	mainVLayout->addLayout(horizLayout);
	
	// rule 3
	horizLayout = new QHBoxLayout(); 
	idLabel = new QLabel();
	idLabel->setFixedWidth(20);
	idLabel->setFixedHeight(20);
	idLabel->setText("3");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 16,60)));
	idLabel->setStyleSheet("QLabel { color : red; }");
	horizLayout->addWidget(idLabel);
	idLabel = new QLabel();
	idLabel->setText(" clickez ce bouton pour choisir le dossier\n contenant les partitions");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 14,40)));
	idLabel->setStyleSheet("QLabel { color : black; }");
	horizLayout->addWidget(idLabel);
	mainVLayout->addLayout(horizLayout);

	// rule 4
	horizLayout = new QHBoxLayout(); 
	idLabel = new QLabel();
	idLabel->setFixedWidth(20);
	idLabel->setFixedHeight(20);
	idLabel->setText("4");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 16,60)));
	idLabel->setStyleSheet("QLabel { color : red; }");
	horizLayout->addWidget(idLabel);
	idLabel = new QLabel();
	idLabel->setText(" clickez ce bouton pour afficher l'aide");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 14,40)));
	idLabel->setStyleSheet("QLabel { color : black; }");
	horizLayout->addWidget(idLabel);
	mainVLayout->addLayout(horizLayout);

	// rule 5
	horizLayout = new QHBoxLayout(); 
	idLabel = new QLabel();
	idLabel->setFixedWidth(20);
	idLabel->setFixedHeight(20);
	idLabel->setText("5");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 16,60)));
	idLabel->setStyleSheet("QLabel { color : red; }");
	horizLayout->addWidget(idLabel);
	idLabel = new QLabel();
	idLabel->setText(" cette barre indique la note courrante\n à deviner");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 14,40)));
	idLabel->setStyleSheet("QLabel { color : black; }");
	horizLayout->addWidget(idLabel);
	mainVLayout->addLayout(horizLayout);

	// rule 6
	horizLayout = new QHBoxLayout(); 
	idLabel = new QLabel();
	idLabel->setFixedWidth(20);
	idLabel->setFixedHeight(20);
	idLabel->setText("6");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 16,60)));
	idLabel->setStyleSheet("QLabel { color : red; }");
	horizLayout->addWidget(idLabel);
	idLabel = new QLabel();
	idLabel->setText(" zone de la partition, les notes vertes\n sont correct et les rouges fausses");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 14,40)));
	idLabel->setStyleSheet("QLabel { color : black; }");
	horizLayout->addWidget(idLabel);
	mainVLayout->addLayout(horizLayout);

	// rule 7
	horizLayout = new QHBoxLayout(); 
	idLabel = new QLabel();
	idLabel->setFixedWidth(20);
	idLabel->setFixedHeight(20);
	idLabel->setText("7");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 16,60)));
	idLabel->setStyleSheet("QLabel { color : red; }");
	horizLayout->addWidget(idLabel);
	idLabel = new QLabel();
	idLabel->setText(" le nom des notes que vous avez entré\n s'affiche ici");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 14,40)));
	idLabel->setStyleSheet("QLabel { color : black; }");
	horizLayout->addWidget(idLabel);
	mainVLayout->addLayout(horizLayout);

	// rule 8
	horizLayout = new QHBoxLayout(); 
	idLabel = new QLabel();
	idLabel->setFixedWidth(20);
	idLabel->setFixedHeight(20);
	idLabel->setText("8");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 16,60)));
	idLabel->setStyleSheet("QLabel { color : red; }");
	horizLayout->addWidget(idLabel);
	idLabel = new QLabel();
	idLabel->setText(" clavier du piano, clickez sur une touche\n pour l'assigner à la note courrante");
	idLabel->setFont((QFont("Helvetica [Cronyx]", 14,40)));
	idLabel->setStyleSheet("QLabel { color : black; }");
	horizLayout->addWidget(idLabel);
	mainVLayout->addLayout(horizLayout);

	QFrame* line = new QFrame();
	line->setFrameShape(QFrame::VLine);
	line->setFrameShadow(QFrame::Sunken);	
	mainHLayout->addWidget(line);
	mainHLayout->addLayout(mainVLayout);

	setLayout(mainHLayout);
}

EzHelp::~EzHelp(){}


