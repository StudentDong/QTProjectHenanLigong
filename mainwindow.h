#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QDockWidget>
#include <QLabel>
#include<qlist.h>
#include "ui_mainwindow.h"
#include <MyQtreeWidget.h>
#include <MyVtkWidget.h>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent=0);
	~MainWindow();
public:
	void removeAllDock();//移除并所有dock
	//Displaying dock Window
	void showDock(const QList<int> &index);
public:
	int PointSize;
	bool isDrawCoordinate;
	bool isObbSwitch;
	bool isDisappear;
	//属性窗口
	//QDockWidget* Properties ;
	QLabel* Infromation;
private:
	Ui::MainWindowClass ui;
private:
	//界面相关变量
	QList<QDockWidget*> myDocks;
	QList<int> index;//dock索引
	myVtkWidget *view;//点云显示对象
	myQTreeWidget* tree;//文件树dock内的树状图
	QToolBar* viewToolBar;//视图工具栏
	QLabel* label_PointSize;
	//数据相关变量
	std::vector<pcl::PointCloud<pcl::PointXYZRGB>::Ptr> cloud;
	struct PointMaxMin
	{
		pcl::PointXYZRGB MaxPoint;
		pcl::PointXYZRGB MinPoint;
	};
	
	std::vector<PointMaxMin> PointMaxMinArray;
	QStringList FilePathName;
	QStringList fileName;
	///////////////////////////
	QStringList head;//表头
//私有函数声明
private:
	void creatdockwindow();
	void InitializeVar();
	void MainWindow::connectButtonSlots();
	void creatToolBar();
	void creatStatusBar();
	//槽函数声明
	private slots:
	void onOpen();
	void onSetBackGroundColor();
	void onSetBackGroundBlack();
	void onSetBackGroundWhite();
	void onSelectPointColor();
	void onSetPointCloudRed();
	void onSetPointCloudGreen();
	void onSetPointCloudBlue();
	void onIncrease();
	void onDecrease();
	void onCoordinate();
	void onClear();
	void onRansacCycle();
	void onRansacPlane();
	void onFeatureValue();
	void onEuropeCluster();
	void onFeatureOutput();
	void onSave();
	////////////////////三视图
	void onTopView();
	void onLeftView();
	void onMainView();
	private slots:
	void onCreatureObbCube();
	///////////////////////////鼠标键盘操作
	void itemSelected(QTreeWidgetItem* item, int count);
	void treeItemChanged(QTreeWidgetItem* item, int);
	void popMenu(const QPoint&);
};

#endif // MAINWINDOW_H
