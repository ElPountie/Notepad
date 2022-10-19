#include <QtWidgets/QMainWindow>
#include "ui_Notepad.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class NotepadClass;
}
QT_END_NAMESPACE
class Notepad : public QMainWindow
{
	Q_OBJECT

public:
	explicit Notepad(QWidget* parent = nullptr);
	~Notepad();
private:
	Ui::NotepadClass ui; 
	QString currentFile;

private slots: //Liste de toutes les actions réalisable sur la fenetre ATTENTION : les action doivent avoir le meme nom !!!
	void openFile();
	void textChanged();
	void copyText();
	void cutText();
	void pasteText();
	void undoEdit();
	void selectFont();
	void switchItalic(bool italic);
	void switchBold(bool bold);
	void switchUnderline(bool underline);
	void dialogAbout();
	void on_actionNew_triggered();
	void on_actionOpen_triggered();
	void on_actionSave_triggered();
	void on_actionSave_as_triggered();
	void on_actionExit_triggered();
};