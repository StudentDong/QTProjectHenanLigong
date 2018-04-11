#pragma once

#include <QDialog>
#include "ui_OneParameDialogClass.h"

class OneParameDialogClass : public QDialog
{
	Q_OBJECT

public:
	OneParameDialogClass(QWidget *parent = Q_NULLPTR);
	~OneParameDialogClass();
public:
	int flag=1;
	float Param1;
	Ui::OneParameDialogClass ui;
private:
	private slots :
		void onEnsure();
		void onClose();
};
