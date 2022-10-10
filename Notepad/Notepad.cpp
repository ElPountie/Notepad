#include "Notepad.h"
#include "qfiledialog.h"
#include "qmessagebox.h"
#include "qsavefile.h"

Notepad::Notepad(QWidget * parent) :
	QMainWindow(parent) //heriter les attributs de la fenetre parent sur la fille
{
ui.setupUi(this); //methode herite de QMainWindow
connect(ui.actionOpen, &QAction::triggered, this, &Notepad::openFile);
connect(ui.textEdit, SIGNAL(textChanged()), this, SLOT(textChanged()));
}

Notepad::~Notepad(){}

void Notepad::openFile() {

}

void Notepad :: textChanged() {

}

void Notepad::on_actionNew_triggered()
{
	currentFile.clear();
	ui.textEdit->setText(QString());
}



void Notepad::on_actionOpen_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
	if (fileName.isEmpty())
		return;
	QFile file(fileName);
	currentFile = fileName;
	if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, "Warning", "Cannot open file: " +
			file.errorString());
		return;
	}
	setWindowTitle(fileName);
	QTextStream in(&file);
	QString text = in.readAll();
	ui.textEdit->setText(text);
	/* ALTERNATIVE
	while (!file.atEnd()) {
		QString line = file.readLine();
		do_something_with_line(line);
	}
	*/
	file.close();
}

void Notepad::on_actionSave_triggered()
{
	if (currentFile.isEmpty()) { //verifie sir le fichier existe ou pas 
		Notepad::on_actionSave_as_triggered(); //si oui appelle save as
		return;
	}
	QSaveFile file(currentFile); //sinon save le fichier 
	file.open(QIODevice::WriteOnly); //Possibilit� � l'ecriture
	file.write(ui.textEdit->toPlainText().toUtf8());//recopie le text dans le fichier
	file.commit();//valide
}

void Notepad::on_actionSave_as_triggered()
{
	currentFile = QFileDialog::getSaveFileName(this); //attribue directement le nom du fichier au current file
	if (currentFile.isEmpty()) {
		QSaveFile file(currentFile);
		file.open(QIODevice::WriteOnly);
		file.write(ui.textEdit->toPlainText().toUtf8());
		file.commit();
	}
}
