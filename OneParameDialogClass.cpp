#include "OneParameDialogClass.h"

OneParameDialogClass::OneParameDialogClass(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.OK, SIGNAL(clicked()), this, SLOT(onEnsure()));
	connect(ui.Cancal, SIGNAL(clicked()), this, SLOT(onClose()));

}

OneParameDialogClass::~OneParameDialogClass()
{
}
void OneParameDialogClass::onEnsure()
{
	flag = 1;
	Param1 = ui.lineEdit_1->text().toFloat();
	close();
	return;
}
void OneParameDialogClass::onClose()
{
	flag = 0;
	close();
	return;
}