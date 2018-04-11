#pragma once

#include <QWidget>
#include "ui_QtGuiClass.h"

class QtGuiClass : public QWidget
{
	Q_OBJECT

public:
	QtGuiClass(QWidget *parent = Q_NULLPTR);
	~QtGuiClass();

private:
	Ui::QtGuiClass ui;
};
