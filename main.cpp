#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <qtextcodec.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QPixmap pix;
	//pix.load("Resources/Initialize.bmp");
	//QSplashScreen splash(pix);
	//splash.show();
	//a.processEvents();
	//_sleep(1000);
	MainWindow w;
	w.show();
	//splash.finish(&w);//程序启动画面结束
	return a.exec();
}
