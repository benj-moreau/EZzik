#include "../include/EZselection.hpp"

EzSelection::EzSelection():QComboBox(){
	QObject::connect(this,SIGNAL(currentIndexChanged(int)),this,SLOT(selectedScore(int)));
	setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Minimum);
	setMinimumHeight(50);
}
EzSelection::~EzSelection(){}

int EzSelection::setDirPath(std::string path){
	dirPath = path;
	return updateList();
}

int EzSelection::updateList(){
	std::string fileName;
	std::stringstream fileNameNoDot;
	int stringSize;

	clear();

	DIR *pdir = NULL;
	struct dirent *pent = NULL;
	if((pdir = opendir(dirPath.c_str())) == NULL){
		QMessageBox::information(new QWidget(),QString("Error message box"),QString("Can't find selected directory ><'"));
		return 3;
	}

	while((pent = readdir(pdir))){
		if(pent == NULL){
			QMessageBox::information(new QWidget(),QString("Error message box"),QString("Something went wrong while reading files"));
			return 3;
		}
		fileName = std::string(pent->d_name);
		if(fileName != "." && fileName != ".."){
			for(int i = 0; i < (stringSize = fileName.length()); ++i){ if(fileName[i] == '.') fileName[i] = ' '; }
			fileNameNoDot.str(fileName);
			fileNameNoDot >> fileName;
			addItem(QString::fromStdString(fileName));
		}
	}
	closedir(pdir);
	return EXIT_SUCCESS;
}

void EzSelection::recieveDir(QString dirPath){
	emit(sendNewDir());
	setDirPath(dirPath.toUtf8().constData());
}

void EzSelection::selectedScore(int ind){
	QString comboText;
	std::stringstream allNotes;
	std::string noteToken;
	std::string score;
	std::string line;
	std::vector<std::string> notes;
	if((comboText = itemText(ind)) != NULL){
		score = dirPath + "/" + comboText.toUtf8().constData() + ".score";
		std::ifstream myfile(score.c_str());

		if (myfile.is_open()){
			getline(myfile,line);
			
			allNotes.str(line);
			while((allNotes >> noteToken) != NULL){
				notes.push_back(noteToken);
			}
			myfile.close();
			if(notes.size() > 0){
				emit(sendScore(notes)); // send notes read from text file to the EZscore
				emit(sendNewValidInd(ind));
			}
		}else QMessageBox::information(new QWidget(),tr("File Error"),tr("unable to open the file")); 
	}
}
