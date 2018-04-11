#include "FourParameDialogClass.h"

FourParameDialogClass::FourParameDialogClass(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.OK, SIGNAL(clicked()), this, SLOT(onEnsure()));
  	connect(ui.Cancal, SIGNAL(clicked()), this, SLOT(onClose()));

 }

FourParameDialogClass::~FourParameDialogClass()
{
}
void FourParameDialogClass::connectButtonSlots()
{
	
}
int FourParameDialogClass::onEnsure()
{
	
	Param1 = ui.lineEdit_1->text().toFloat();
	Param2 = ui.lineEdit_2->text().toFloat();
	Param3 = ui.lineEdit_3->text().toFloat();
	param4 = ui.lineEdit_4->text().toFloat();
	
	this->close();
	return 1;
}
int FourParameDialogClass::onClose()
{
	flag = 0;
	this->close();
	
	return 0;
}
