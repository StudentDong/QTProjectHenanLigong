#pragma once

#include <QWidget>
#include "ui_FileMean.h"

class FileMean : public QWidget
{
	Q_OBJECT

public:
	FileMean(QWidget *parent = Q_NULLPTR);
	~FileMean();

private:
	Ui::FileMean ui;
};
