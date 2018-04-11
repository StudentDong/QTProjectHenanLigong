#pragma once


#include <QWidget>
#include "ui_FourParameDialogClass.h"
#include "Value.h"
#include <QDialog>
class FourParameDialogClass : public QDialog
{
	Q_OBJECT

public:
	FourParameDialogClass(QDialog *parent = Q_NULLPTR);
	~FourParameDialogClass();

public:
	Ui::FourParameDialogClass ui;
public:
	int flag = 1;
	void connectButtonSlots();
	private slots:
	int onEnsure();
	int onClose();
	

public:
	
};
