#include "mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <File.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/common/common.h>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowState(Qt::WindowState::WindowMaximized);//窗口最大化
	InitializeVar();
	creatdockwindow();
	creatToolBar();
	creatStatusBar();
	connectButtonSlots();
}

MainWindow::~MainWindow()
{

}
//初始化函数
void MainWindow::InitializeVar()
{
	PointSize = 1;
	isDrawCoordinate = false;
	isObbSwitch = false;
	//view->viewer->setCameraPosition(0, 0, 0, 0, 0, 0);
}

void MainWindow::connectButtonSlots()
{
	///////////////////////////////////////////////////////////////////////////////////系统部分
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(onOpen()));
	connect(ui.actionBackGroundSelect, SIGNAL(triggered()), this, SLOT(onSetBackGroundColor()));
	connect(ui.actionBlack, SIGNAL(triggered()), this, SLOT(onSetBackGroundBlack()));
	connect(ui.actionWhite, SIGNAL(triggered()), this, SLOT(onSetBackGroundWhite()));
	connect(ui.actionSelect, SIGNAL(triggered()), this, SLOT(onSelectPointColor()));
	connect(ui.actionRed, SIGNAL(triggered()), this, SLOT(onSetPointCloudRed()));
	connect(ui.actionGreen, SIGNAL(triggered()), this, SLOT(onSetPointCloudGreen()));
	connect(ui.actionBule, SIGNAL(triggered()), this, SLOT(onSetPointCloudBlue()));
	connect(ui.actionIncrease, SIGNAL(triggered()), this, SLOT(onIncrease()));
	connect(ui.actionDecrease, SIGNAL(triggered()), this, SLOT(onDecrease()));
	connect(ui.actionCoordinate, SIGNAL(triggered()), this, SLOT(onCoordinate()));
	connect(ui.actionClear, SIGNAL(triggered()), this, SLOT(onClear()));
	connect(ui.actionSave ,SIGNAL(triggered()), this, SLOT(onSave()));
	connect(ui.actionTop_View, SIGNAL(triggered()), this, SLOT(onTopView()));
	connect(ui.actionLeft_View, SIGNAL(triggered()), this, SLOT(onLeftView()));
	connect(ui.actionMain_View, SIGNAL(triggered()), this, SLOT(onMainView()));
	/////////////////////////////////////////////////////////////////////////////////////算法部分
	connect(ui.actionRansac, SIGNAL(triggered()), this, SLOT(onRansacCycle()));
	connect(ui.actionRansacPlane, SIGNAL(triggered()), this, SLOT(onRansacPlane()));
	connect(ui.actionFeatureValue, SIGNAL(triggered()), this, SLOT(onFeatureValue()));
	connect(ui.actionEuropeCluster, SIGNAL(triggered()), this, SLOT(onEuropeCluster()));
	connect(ui.actionFeatureOutput, SIGNAL(triggered()), this, SLOT(onFeatureOutput()));
	connect(ui.actionObbCube, SIGNAL(triggered()), this, SLOT(onCreatureObbCube()));
	///////////////////////////////////////////////////////////////////////////////////鼠标事件
	connect(tree->m_tree, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(itemSelected(QTreeWidgetItem*, int)));
	
	connect(tree->m_tree, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(treeItemChanged(QTreeWidgetItem*, int)));
	
	connect(tree->m_tree, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(popMenu(const QPoint&)));
}

//创建dock窗体
void MainWindow::creatdockwindow()
{
	//The dock is allowed as a insertion 
	setDockNestingEnabled(true);
	removeAllDock();
	//文件树窗体
	

	std::string std_str("DB Tree");
	QString q_str = QString::fromStdString(std_str);
	QDockWidget*DB_Tree = new QDockWidget(q_str);
	DB_Tree->setBaseSize(QSize(100, 100));
	DB_Tree->setFeatures(QDockWidget::DockWidgetMovable);////指定停靠窗体的样式，此处为可移动 
	addDockWidget(Qt::LeftDockWidgetArea, DB_Tree);
	myDocks.push_back(DB_Tree);
	index.push_back(0);
	head << "Files List";
	//QString strMessage = QString::fromLocal8Bit("点云数据列表");
	tree = new myQTreeWidget;
	tree->m_tree->setHeaderLabels(head);
	DB_Tree->setWidget(tree->m_tree);
	
	QDockWidget* Properties = new QDockWidget(tr("properties"), this);
	Properties->setFeatures(QDockWidget::DockWidgetMovable);
	Infromation = new QLabel;
	myDocks.push_back(Properties);
	index.push_back(1);
	Properties->setWidget(Infromation);
	//点云视图窗体
	QDockWidget*cloudview = new QDockWidget(tr("cloud viewer"), this);
	myDocks.push_back(cloudview);
	index.push_back(2);
	splitDockWidget(DB_Tree, cloudview, Qt::Horizontal);
	splitDockWidget(DB_Tree, Properties, Qt::Vertical);
	setCentralWidget(cloudview);
	view = new myVtkWidget;
	view->update();
	cloudview->setWidget(view);//Sets the widget for the dock widget to widget.
	/*If the dock widget is visible when widget is added, you must show() it explicitly.
		Note that you must add the layout of the widget before you call this function; if not, the widget will not be visible.
		See also widget()*/
	showDock(index);

}
void MainWindow::removeAllDock()
{
	for (unsigned i = 0; i < myDocks.size(); ++i)
	{
		removeDockWidget(myDocks[i]);
	}
}
///
/// \brief 显示指定序号的dock
/// \param index 指定序号，如果不指定，则会显示所有
///
void MainWindow::showDock(const QList<int> &index)
{
	if (index.isEmpty())
	{
		for (int i = 0; i < myDocks.size(); ++i)
		{
			myDocks[i]->show();
		}
	}
	else
	{
		foreach(int i, index) {//index 依次赋给i
			myDocks[i]->show();
		}
	}
}

//工具框
void MainWindow::creatToolBar()
{
	//系统工具栏
	
	ui.mainToolBar->addAction(ui.actionOpen);
	ui.mainToolBar->addAction(ui.actionClear);
	ui.mainToolBar->addAction(ui.actionSave);
	//视图工具
	
	viewToolBar = this->addToolBar(tr("viewToolBar"));
	viewToolBar->addAction(ui.actionTop_View);
	viewToolBar->addAction(ui.actionLeft_View);
	viewToolBar->addAction(ui.actionMain_View);
	viewToolBar->addAction(ui.actionBlack);
	viewToolBar->addAction(ui.actionWhite);
	viewToolBar->addAction(ui.actionRed);
	viewToolBar->addAction(ui.actionGreen);
	viewToolBar->addAction(ui.actionBule);
	viewToolBar->addAction(ui.actionIncrease);
	viewToolBar->addAction(ui.actionDecrease);
	viewToolBar->addAction(ui.actionCoordinate);
	viewToolBar->addAction(ui.actionObbCube);
	
}
//状态栏
void MainWindow::creatStatusBar()
{
	label_PointSize = new QLabel;
	label_PointSize->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
	label_PointSize->setAlignment(Qt::AlignCenter);
	ui.statusBar->addWidget(label_PointSize, 0);
	//label_PointSize->adjustSize();
	label_PointSize->setStyleSheet("background-color:rgb(0,191,255)");
	label_PointSize->setText(tr((std::string("pointSize:") + std::to_string(PointSize)).c_str()));
	
}
void MainWindow::onOpen()
{
	InitializeVar();
	QFileDialog FileDlg(this);
	FileDlg.setFileMode(QFileDialog::ExistingFiles);
	FileDlg.setNameFilter(tr("Open PCD Files(*.pcd);;Open Las Files(*.las);;Open ASCII files(*.txt)"));
	FileDlg.setDirectory(NULL);
	if (FileDlg.exec() == QDialog::Accepted)//当调用exec方法时，弹出，等待用户响应，用户可能点击确定，那么exec返回QDialog::Accepted值，如果点击取消则返回QDialog::Rejected,这句话是通过返回值来确定用户的响应结果
		FilePathName = FileDlg.selectedFiles();
	else
	{
		QMessageBox::information(NULL, tr("warring"), tr("You didn't select any files."));
		return;
	}
	for (size_t i = 0; i < FilePathName.size(); ++i)
	{
		QFileInfo fileinfo = QFileInfo(FilePathName.at(i));
		QString m_strPathName = fileinfo.absolutePath();//文件路径名
		QString m_strFileExt = fileinfo.suffix();//文件扩展名
		QString m_filename = fileinfo.fileName();
		fileName.push_back(m_filename);
		pcl::PointCloud<pcl::PointXYZRGB>::Ptr tempCloud;
		if (!FilePathName.at(i).isEmpty())
		{
			PointMaxMin temp;
			std::string file_name = std::string((const char*)FilePathName.at(i).toLocal8Bit());
			//判断文件格式进行判断
			if (m_strFileExt.toStdString() == "pcd")
			{

				tempCloud = pcdRead(file_name,tempCloud);
				pcl::getMinMax3D(*tempCloud, temp.MinPoint, temp.MaxPoint);
			}
			if (m_strFileExt.toStdString() == "txt" || m_strFileExt.toStdString() == "asc" || m_strFileExt.toStdString() == "txt")
			{
				tempCloud = txtRead(file_name,tempCloud);
				pcl::getMinMax3D(*tempCloud, temp.MinPoint, temp.MaxPoint);
			}
			if (m_strFileExt.toStdString() == "las")
			{
				//tempCloud = lasRead(file_name);
			}
			cloud.push_back(tempCloud);
			PointMaxMinArray.push_back(temp);
			

			/*if (Qt::MoveAction == 0)
			{
				view->viewer->addPointCloud<pcl::PointXYZRGB>(tempCloud, std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
			}
			else
			{
				pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGB>);
				pcl::VoxelGrid<pcl::PointXYZRGB> sor;
				sor.setInputCloud(tempCloud);
				sor.setLeafSize(0.2f, 0.2f, 0.2f);
				sor.filter(*cloud_filtered);
				view->viewer->addPointCloud<pcl::PointXYZRGB>(cloud_filtered, std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
			}*/
			view->viewer->addPointCloud<pcl::PointXYZRGB>(tempCloud, std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
			
			
		}
		else
			return;
		//view->viewer->setCameraPosition(0,0,0,0,0,0);
		view->viewer->resetCamera();
		view->update();
			
		}
	this->setWindowTitle("Point Cloud Process System--" + FilePathName.at(0));//更新程序标题
	tree->creattree(fileName);
	
	}



void MainWindow::onClear()
{
	InitializeVar();
	while (tree->m_tree->topLevelItemCount())
	{
		QTreeWidgetItem* item = tree->m_tree->takeTopLevelItem(0);
		delete item;
	}
	FilePathName.clear();
	fileName.clear();
	cloud.clear();
	view->viewer->removeAllPointClouds();
	view->viewer->resetCamera();
	view->update();
}
//背景颜色
void MainWindow::onSetBackGroundColor()
{
	QColor color = QColorDialog::getColor(Qt::black, this);
	if (color.isValid())
	{
		view->viewer->setBackgroundColor(color.red(), color.green(), color.blue());
		//viewer->resetCamera();
		view->update();
	}
}
void MainWindow::onSetBackGroundBlack()
{
	QColor color = Qt::black;
	if (color.isValid())
	{
		view->viewer->setBackgroundColor(color.red(), color.green(), color.blue());
		//viewer->resetCamera();
		view->update();
	}
}
void MainWindow::onSetBackGroundWhite()
{
	QColor color = Qt::white;
	if (color.isValid())
	{
		view->viewer->setBackgroundColor(color.red(), color.green(), color.blue());
		//viewer->resetCamera();
		view->update();
	}
}

//点颜色
void MainWindow::onSelectPointColor()
{
	QColor color = QColorDialog::getColor(Qt::red, this);
	if (color.isValid())
	{
		//采用迭代器遍历
		for (unsigned i = 0; i < cloud.size(); ++i)
		{
			for (unsigned j = 0; j < cloud[i]->points.size(); j++)
			{
				cloud[i]->points[j].r = color.red();
				cloud[i]->points[j].g = color.green();
				cloud[i]->points[j].b = color.blue();
			}
			view->viewer->updatePointCloud(cloud[i],
				std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
		}
	}

	view->update();
}
void MainWindow::onSetPointCloudRed()
{
	QColor color = Qt::red;
	if (color.isValid())
	{
		//采用迭代器遍历
		for (unsigned i = 0; i < cloud.size(); ++i)
		{
			for (unsigned j = 0; j < cloud[i]->points.size(); j++)
			{
				cloud[i]->points[j].r = color.red();
				cloud[i]->points[j].g = color.green();
				cloud[i]->points[j].b = color.blue();
			}
			view->viewer->updatePointCloud(cloud[i],
				std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
		}
	}

	view->update();
	
}
void MainWindow::onSetPointCloudGreen()
{
	QColor color = Qt::green;
	if (color.isValid())
	{
		//采用迭代器遍历
		for (unsigned i = 0; i < cloud.size(); ++i)
		{
			for (unsigned j = 0; j < cloud[i]->points.size(); j++)
			{
				cloud[i]->points[j].r = color.red();
				cloud[i]->points[j].g = color.green();
				cloud[i]->points[j].b = color.blue();
			}
			view->viewer->updatePointCloud(cloud[i],
				std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
		}
	}

	view->update();
}
void MainWindow::onSetPointCloudBlue()
{
	QColor color = Qt::blue;
	if (color.isValid())
	{
		//采用迭代器遍历
		for (unsigned i = 0; i < cloud.size(); ++i)
		{
			for (unsigned j = 0; j < cloud[i]->points.size(); j++)
			{
				cloud[i]->points[j].r = color.red();
				cloud[i]->points[j].g = color.green();
				cloud[i]->points[j].b = color.blue();
			}
			view->viewer->updatePointCloud(cloud[i],
				std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
		}
	}

	view->update();
}
//点大小
void MainWindow::onIncrease()
{
	if (PointSize > 0 && PointSize < 6)
	{
		PointSize++;
	}
	else
		return;
	for (unsigned i = 0; i < cloud.size(); i++)
	{
		view->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, PointSize, std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
	}
	label_PointSize->setText(tr((std::string("pointSize:") + std::to_string(PointSize)).c_str()));
	//view->viewer->resetCamera();
	view->update();
	
}
void MainWindow::onDecrease()
{
	if (PointSize > 0 && PointSize < 6)
	{
		PointSize--;
	}
	else
		return;
	for (unsigned i = 0; i < cloud.size(); i++)
	{
		view->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, PointSize, std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
	}

	view->update();
}
//坐标轴
void MainWindow::onCoordinate()
{

	if (isDrawCoordinate == false)
	{
		if (cloud.size())
		{
			view->viewer->addCoordinateSystem(1.0, cloud[0]->points[0].x, cloud[0]->points[0].y, cloud[0]->points[0].z, "coordinate", 0);
			//view->viewer->resetCamera();
			view->update();
			isDrawCoordinate = true;
		}
		else
		{
			view->viewer->addCoordinateSystem(1.0, 0, 0, 0, "coordinate", 0);
			//view->viewer->resetCamera();
			view->update();
			isDrawCoordinate = true;
		}

	}
	else
	{
		view->viewer->removeCoordinateSystem("coordinate", 0);
		view->viewer->resetCamera();
		view->update();
		isDrawCoordinate = false;
	}
}
//////////////////////////////////////////////////////三视图
void MainWindow::onMainView()
{
	view->viewer->setCameraPosition(0, -1, 0, 0.5, 0.5, 0.5, 0, 0, 1);
	//view->viewer->setCameraPosition(0, -1, 0, 0, 0, 1);
	view->update();
}
void MainWindow::onLeftView()
{
	view->viewer->setCameraPosition(-1, 0, 0, 0, 0, 0, 0, 0, 1);
	//view->viewer->setCameraPosition(-1, 0, 0, 0, 0, 1);
	view->update();
}
void MainWindow::onTopView()
{
	view->viewer->setPosition(int(cloud[0]->points[0].x), int(cloud[0]->points[0].y));
	view->viewer->setCameraPosition(0, 0, 1, 0, 0, 0, 0, 1, 0);

	//view->viewer->setCameraPosition(0, 1, 0, 0,0,0,0, 1, 0);
	
	view->update();
}
//////////////////////////////////////////////////////////////////////////算法部分
#include "Ransac.h"
#include "FourParameDialogClass.h"
void MainWindow::onRansacCycle()
{
	FourParameDialogClass a;
	
	a.ui.label_1->setText(QString::fromLocal8Bit("设置表面法线权重系数"));
	a.ui.label_2->setText(QString::fromLocal8Bit("最大迭代次数"));
	a.ui.label_3->setText(QString::fromLocal8Bit("内点到模型的距离允许的最大值"));
	a.ui.label_4->setText(QString::fromLocal8Bit("估计出的圆柱模型的半径范围"));

	//a.exec();// = QDialog::Rejected;//对话框停靠
	a.exec();
	
	if (a.flag== 0)
	{
		return;
	}
	
	float num1 = 0.2, num2 = 100, num3 = 0.1, num4 = 0.5;
	num1 = Param1;
	num2 = Param2;
	num3 = Param3;
	num4 = param4;

	pcl::PointCloud < pcl::PointXYZRGB>::Ptr TempCloud(new pcl::PointCloud<pcl::PointXYZRGB>);
	std::vector<pcl::PointCloud<pcl::PointXYZRGB>::Ptr> TempCloudV;
	TempCloudV.clear();
	//TempCloudV.resize(cloud.size());
	for (unsigned int i = 0; i <MainWindow::cloud.size(); i++)
	{
		TempCloud=CylinderSegmentation(cloud[i],num1,num2,num3,num4);
		TempCloudV.push_back(TempCloud);
	}
	
	//view->viewer->removeAllPointClouds();
	for (unsigned int i = 0; i < TempCloudV.size(); i++)
	{
		//view->viewer->addPointCloud(TempCloudV[i], std::string("Tempcloud"+i).c_str());
		view->viewer->updatePointCloud(TempCloudV[i], std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
		
	}
	view->update();
	
}
#include "OneParameDialogClass.h"
void MainWindow::onRansacPlane()
{
	OneParameDialogClass a;
	a.ui.OK->setText(QString::fromLocal8Bit("确定"));
	a.ui.Cancal->setText(QString::fromLocal8Bit("取消"));

	a.ui.label_1->setText(QString::fromLocal8Bit("表面阈值"));
	a.exec();
	if (a.flag == 0)
	{
		return;
	}
	pcl::PointCloud < pcl::PointXYZRGB>::Ptr TempCloud(new pcl::PointCloud<pcl::PointXYZRGB>);
	std::vector<pcl::PointCloud<pcl::PointXYZRGB>::Ptr> TempCloudV;
	TempCloudV.clear();
	float a1, b, c, d;
	for (unsigned int i = 0; i < MainWindow::cloud.size(); i++)
	{
		TempCloud = RandomSampleConsensus(cloud[i], a.Param1,a1,b,c,d);
		TempCloudV.push_back(TempCloud);
	}
	for (unsigned int i = 0; i < TempCloudV.size(); i++)
	{
		view->viewer->updatePointCloud(TempCloudV[i], std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());

	}
	view->update();

}
#include <FeatureVector.h>
void MainWindow::onFeatureValue(){
	float m1, m2, m3, ProjectionDivision, Density_x,Density_y,Density_z, ResidualSum, ResidualSquares;
	for (unsigned int i = 0; i < MainWindow::cloud.size(); i++)
	{
		FeaVector(cloud[i], m1, m2, m3);//3方向特征向量
		ProjectedDensity(cloud[i], ProjectionDivision, Density_x,Density_y,Density_z);//投影比，稠密度
		PointToPlant(cloud[i], ResidualSum, ResidualSquares);//总参差，残差均方根
		QString str1, str2, str3, str4, str5, str6, str7, str8, str9, str0;

		str1 = QString::number(m1, 'f', 4);
		str2 = QString::number(m2, 'f', 4);
		str3 = QString::number(m3, 'f', 4);
		str4 = QString::number(ProjectionDivision, 'f', 4);
		str5 = QString::number(Density_x, 'f', 4);
		str6 = QString::number(ResidualSum, 'f', 4);
		str7 = QString::number(ResidualSquares, 'f', 4);
		str8 = QString::number(Density_y, 'f', 4);
		str9 = QString::number(Density_z, 'f', 4);
		str0 = "Vector: " + str1 + " " + str2 + " " + str3 + " " + "\n" + "ProjectionDivision:  "
			+ str4 + " " + str5 +" "+ str8+" "+str9 + "\n" + "ResidualSum:  " + str6 + " " +" "+ str7;
		QMessageBox::information(NULL, tr("Fature"), str0);
	}

}
void MainWindow::onEuropeCluster()
{
	FourParameDialogClass a;

	a.ui.label_1->setText(QString::fromLocal8Bit("搜索半径"));
	a.ui.label_2->setText(QString::fromLocal8Bit("最少点数"));
	a.ui.label_3->setText(QString::fromLocal8Bit("最大点数"));
	a.ui.label_4->setText(QString::fromLocal8Bit("没有用到"));
	a.ui.lineEdit_1->setText("0.4");
	a.ui.lineEdit_2->setText("100");
	a.ui.lineEdit_3->setText("25000");
	a.exec();
	float num1 = 0.2, num2 = 100, num3 = 0.1;
	num1 = Param1;
	num2 = Param2;
	num3 = Param3;
	//num4 = param4;
	if (a.flag == 0)
	{
		return;
	}
	std::vector<pcl::PointCloud<pcl::PointXYZRGB>::Ptr > OutCloud;
	std::vector<pcl::PointCloud<pcl::PointXYZRGB>::Ptr > tempCloud;
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloudT(new pcl::PointCloud<pcl::PointXYZRGB>);
	//{ 255, 0, 0 }, { 0, 255, 0 }, { 0, 0, 255 }
	float color[8][3] = { {128,128,0},{ 205, 0, 0 }, { 0, 0, 205 }, { 0, 128, 128 }, { 205, 205, 0 },
	{ 0, 205, 255 },{ 205, 0, 205 }, { 128, 128, 128 } };
	for (unsigned int i = 0; i < MainWindow::cloud.size(); i++)
	{
		EuropeCluster(cloud[i],num1,num2,num3,OutCloud);
		//////////////////////////////////////////////////////////////////////////reset(new),vec[0].reset(new)
		
		
		int m = 0;
		for (unsigned int j = 0; j < OutCloud.size(); j++)
		{
			
			
			for (unsigned int k = 0; k < OutCloud[j]->points.size(); k++)
			{
	
				int s = m ;
				
				OutCloud[j]->points[k].r = color[s][1];
				OutCloud[j]->points[k].g = color[s][2];
				OutCloud[j]->points[k].b = color[s][3];
			}
			if (m < 6)
			{
				m++;
			}
			else
			{
				m = 0;
			}
			  
		}
		for (unsigned int j = 0; j < OutCloud.size(); j++)
		{
			for (unsigned int k = 0; k < OutCloud[j]->points.size(); k++)
			{
				cloudT->push_back(OutCloud[j]->points[k]);
			}
		}
		tempCloud.push_back(cloudT);
		
	}
	for (unsigned int i = 0; i < tempCloud.size(); i++)
	{
		view->viewer->updatePointCloud(tempCloud[i], std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());

	}
	view->update();
	
	

}
/////////
void MainWindow::onFeatureOutput()
{
	FourParameDialogClass a;
	a.ui.label_1->setText(QString::fromLocal8Bit("搜索半径"));
	a.ui.label_2->setText(QString::fromLocal8Bit("最少点数"));
	a.ui.label_3->setText(QString::fromLocal8Bit("最大点数"));
	a.ui.label_4->setText(QString::fromLocal8Bit("没有用到"));
	a.ui.lineEdit_1->setText("0.4");
	a.ui.lineEdit_2->setText("100");
	a.ui.lineEdit_3->setText("25000");
	a.exec();
	float num1 = 0.2, num2 = 100, num3 = 0.1;
	num1 = Param1;
	num2 = Param2;
	num3 = Param3;
	//num4 = param4;
	if (a.flag == 0)
	{
		return;
	}
	std::vector<pcl::PointCloud<pcl::PointXYZRGB>::Ptr > OutCloud;
	std::vector<pcl::PointCloud<pcl::PointXYZRGB>::Ptr > TempCloud;
	for (unsigned int i = 0; i < MainWindow::cloud.size(); i++)
	{
		EuropeCluster(cloud[i], num1, num2, num3, OutCloud);
	}
	TempCloud.resize(OutCloud.size());
	for (int i = 0; i < TempCloud.size(); i++)
	{
		TempCloud[i].reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	}
	float m1, m2, m3, ProjectionDivision, Density_x,Density_y,Density_z, ResidualSum, ResidualSquares;
	QStringList out_list;
	QString str1, str2, str3, str4, str5, str6, str7, str8, str9, str0, strOut;
	
	FILE *file;//qstring filename;fopen(string(filename+i+".txt".cstr()),"w")
	file = fopen("Feature.txt", "w");
	for (int i = 0; i < OutCloud.size(); i++)
	{
		FeaVector(OutCloud[i], m1, m2, m3);//3方向特征向量
		ProjectedDensity(OutCloud[i], ProjectionDivision, Density_x, Density_y, Density_z);//投影比，稠密度
		PointToPlant(OutCloud[i], ResidualSum, ResidualSquares);//总参差，残差均方根
		fprintf(file, "%.4f  %.4f  %.4f  %.4f  %.4f  %.4f  %.4f  %.4f   %.4f  %f\n", m1, m2, m3, ProjectionDivision,
			Density_x,Density_y,Density_z, ResidualSum, ResidualSquares,2.0f);
		str1 = QString::number(m1, 'f', 4);
		str2 = QString::number(m2, 'f', 4);
		str3 = QString::number(m3, 'f', 4);
		str4 = QString::number(ProjectionDivision, 'f', 4);
		str5 = QString::number(Density_x, 'f', 4);
		str6 = QString::number(ResidualSum, 'f', 4);
		str7 = QString::number(ResidualSquares, 'f', 4);
		str8 = QString::number(Density_y, 'f', 4);
		str9 = QString::number(Density_z, 'f', 4);
		str0 = "Vector: " + str1 + "  " + str2 + "  " + str3 + "  "  +"  "+ "ProjectionDivision:  "
			+ str4 + "  " +"  "+ str5 + "  "+str8+"  "+str9+" " + "ResidualSum:  " + str6 + "   " + str7;
		//out_list.push_back(str0);

		strOut += (str0+"\n");
	}

	QMessageBox::information(NULL, tr("Feature"), strOut);
	fclose(file);


}
void MainWindow::onSave()
{
	QFileDialog *fileDlg = new QFileDialog(this);
	fileDlg->setWindowTitle(tr("Save as"));
	fileDlg->setAcceptMode(QFileDialog::AcceptSave);
	fileDlg->setFileMode(QFileDialog::AnyFile);
	fileDlg->setNameFilter(tr("PCD Files(*.pcd);;Las Files(*.las);;ASCII files(*.txt)"));
	QStringList fileNamesList;
	if (fileDlg->exec() == QDialog::Accepted) {
		fileNamesList = fileDlg->selectedFiles();
	}
	QString fileName = fileNamesList.at(0).toLocal8Bit().constData();
	//QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),  
	//  "../USBData",  
	//  tr("USB files (*.usb *.USB)"));  
	QStringList list = fileName.split(".");
	std::string str = fileName.toStdString();
	if (list.last() == "txt" || list.last() == "TXT")
		WriteTxt(str, MainWindow::cloud[0]);
	if (list.last() == "pcd" || list.last() == "PCD")
		WirtePcd(str, MainWindow::cloud[0]);
	//if (list.last() == "las" || list.last() == "LAS")
		//Wirtelas();
}
#include <OBB.h>
void MainWindow::onCreatureObbCube()
{
	if (isObbSwitch == false)
	{
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloudTemp;
		pcl::PointXYZ min_point_OBB;
		pcl::PointXYZ max_point_OBB;
		pcl::PointXYZ position_OBB;
		Eigen::Matrix3f rotational_matrix_OBB;
		Eigen::Vector3f mass_center;
		Eigen::Vector3f major_vector;
		Eigen::Vector3f middle_vector;
		Eigen::Vector3f minor_vector;
		for (int i = 0; i < MainWindow::cloud.size(); i++)
		{
			CreateOBB(cloud[i], min_point_OBB, max_point_OBB, position_OBB, rotational_matrix_OBB, mass_center,
				major_vector, middle_vector, minor_vector);
			Eigen::Vector3f position(position_OBB.x, position_OBB.y, position_OBB.z);
			Eigen::Quaternionf quat(rotational_matrix_OBB);
			view->viewer->addCube(position, quat, max_point_OBB.x - min_point_OBB.x, max_point_OBB.y - min_point_OBB.y, max_point_OBB.z - min_point_OBB.z, "OBB");
			//view->viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_REPRESENTATION, pcl::visualization::PCL_VISUALIZER_REPRESENTATION_WIREFRAME, "cube");
			view->viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_REPRESENTATION, pcl::visualization::PCL_VISUALIZER_REPRESENTATION_WIREFRAME, "OBB");
			pcl::PointXYZ center(mass_center(0), mass_center(1), mass_center(2));
			pcl::PointXYZ x_axis(major_vector(0) + mass_center(0), major_vector(1) + mass_center(1), major_vector(2) + mass_center(2));
			pcl::PointXYZ y_axis(middle_vector(0) + mass_center(0), middle_vector(1) + mass_center(1), middle_vector(2) + mass_center(2));
			pcl::PointXYZ z_axis(minor_vector(0) + mass_center(0), minor_vector(1) + mass_center(1), minor_vector(2) + mass_center(2));
			view->viewer->addLine(center, x_axis, 1.0f, 0.0f, 0.0f, "major eigen vector");
			view->viewer->addLine(center, y_axis, 0.0f, 1.0f, 0.0f, "middle eigen vector");
			view->viewer->addLine(center, z_axis, 0.0f, 0.0f, 1.0f, "minor eigen vector");
		}
		isObbSwitch = true;
	}
	else
	{
		view->viewer->removeShape("OBB");
		view->viewer->removeShape("major eigen vector");
		view->viewer->removeShape("middle eigen vector");
		view->viewer->removeShape("minor eigen vector");
	}
}

//////////////////////////////鼠标////////////////////////////////////

void MainWindow::itemSelected(QTreeWidgetItem* item, int count)
{
	
	count = MainWindow::tree->m_tree->indexOfTopLevelItem(item);  //获取item的行号
	//for (int i = 0; i != MainWindow::cloud.size(); i++)
	//{
	//	view->viewer->updatePointCloud(MainWindow::cloud[i], std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
	//	view->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
	//}
	//提取当前点云的RGB,点云数量等信息
	int cloud_size = MainWindow::cloud[count]->points.size();
	unsigned int cloud_r = MainWindow::cloud[count]->points[0].r;
	unsigned int cloud_g = MainWindow::cloud[count]->points[0].g;
	unsigned int cloud_b = MainWindow::cloud[count]->points[0].b;
	float cloud_x= PointMaxMinArray[count].MaxPoint.x;
	float cloud_y = PointMaxMinArray[count].MaxPoint.y;
	float cloud_z = PointMaxMinArray[count].MaxPoint.z;
	float cloudi_x = PointMaxMinArray[count].MinPoint.x;
	float cloudi_y = PointMaxMinArray[count].MinPoint.y;
	float cloudi_z = PointMaxMinArray[count].MinPoint.z;
	QString str1 = QString::number(cloud_size);
	QString str2 = QString::number(cloud_r);
	QString str3 = QString::number(cloud_g);
	QString str4 = QString::number(cloud_b);
	QString str5 = QString::number(cloud_x);
	QString str6 = QString::number(cloud_y);
	QString str7 = QString::number(cloud_z);
	QString str8 = QString::number(cloudi_x);
	QString str9 = QString::number(cloudi_y);
	QString str10 = QString::number(cloudi_z);
	QString strOut = "Size :" + str1 + "\n" + "RGB:" + str2 + "," + str3 + "," + str4
		+ "\n" + "X:" + str5 + "," + str8 + "\n" + "Y:" + str6 + "," + str9 + "\n" + "Z:" + str7 + "," + str10;
	//bool multi_color = true;
	//if (mycloud_vec[count].cloud->points.begin()->r == (mycloud_vec[count].cloud->points.end() - 1)->r) //判断点云单色多色的条件（不是很严谨）
	//	multi_color = false;
	
	Infromation->clear();
	Infromation->setText(strOut);
	
	//QMessageBox::information(NULL, tr("INFROMATION"), strOut);
	
}

void MainWindow::treeItemChanged(QTreeWidgetItem *item, int column)
{
	column = tree->m_tree->indexOfTopLevelItem(item);
	if (item->checkState(0) == Qt::Checked)
	{
		isDisappear = 1;

	}
	else if (item->checkState(0) == Qt::Unchecked)
	{
		
		isDisappear = 0;
	}
	if (isDisappear == 1)
	{
		/*view->viewer->updatePointCloud(cloud[column],
			std::string((const char*)fileName.at(column).toLocal8Bit()).c_str());
		view->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, std::string((const char*)fileName.at(column).toLocal8Bit()).c_str());*/
		view->viewer->setPointCloudRenderingProperties(pcl::visualization::RenderingProperties::PCL_VISUALIZER_OPACITY, 1.0, std::string((const char*)fileName.at(column).toLocal8Bit()).c_str(), 0);
	}
	if (isDisappear == 0)
	{
	/*	view->viewer->updatePointCloud(cloud[column],
			std::string((const char*)fileName.at(column).toLocal8Bit()).c_str());*/
		view->viewer->setPointCloudRenderingProperties(pcl::visualization::RenderingProperties::PCL_VISUALIZER_OPACITY, 0.0, std::string((const char*)fileName.at(column).toLocal8Bit()).c_str(), 0);
		//view->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 0, std::string((const char*)fileName.at(column).toLocal8Bit()).c_str());
	}
	view->update();

}
void MainWindow::popMenu(const QPoint&)
{
	QTreeWidgetItem* curItem = tree->m_tree->currentItem();
	if (NULL == curItem) return;
	//QString name = curItem->text(0);
	int id = tree->m_tree->indexOfTopLevelItem(curItem);
	QAction deleteItemAction("Delete", this);
	QAction changeColorAction("Change color", this);
	connect(&changeColorAction, &QAction::triggered, this, &MainWindow::ChangeColour);
	connect(&deleteItemAction, &QAction::triggered, this, &MainWindow::deleteItem);
	QMenu menu(tree->m_tree);
	menu.addAction(&deleteItemAction);
	menu.addAction(&changeColorAction);
	menu.exec(QCursor::pos()); //在当前鼠标位置显示
	

}
void MainWindow::deleteItem()
{
	QList<QTreeWidgetItem*> itemList = tree->m_tree->selectedItems();
	// ui.dataTree->selectedItems().size() 随着迭代次数而改变，因此循环条件要设置为固定大小的 selected_item_count
	int selected_item_count = tree->m_tree->selectedItems().size();
	for (int i = 0; i != selected_item_count; i++){
		//QTreeWidgetItem* curItem = ui.dataTree->currentItem();
		//QMessageBox::information(this, "itemList's size", QString::number(ui.dataTree->selectedItems().size()));
		QTreeWidgetItem* curItem = itemList[i];
		QString name = curItem->text(0);
		int id = tree->m_tree->indexOfTopLevelItem(curItem);
		//QMessageBox::information(this, "information", "curItem: " + name + " " + QString::number(id));
		auto it = cloud.begin() + tree->m_tree->indexOfTopLevelItem(curItem);//for (auto i = vs.begin(); i != vs.end(); i++)
	
		// 删除点云之前，将其点的数目保存
		//int delete_points = it->;
		it = cloud.erase(it);
		//QMessageBox::information(this, "information", QString::number(delete_points) + " " + QString::number(mycloud_vec.size()));
		tree->m_tree->takeTopLevelItem(tree->m_tree->indexOfTopLevelItem(curItem));
	}

	// 移除之后再添加，避免 id 和资源管理树行号不一致的情况
	view->viewer->removeAllPointClouds();
	for (int i = 0; i != cloud.size(); i++)
	{
		view->viewer->addPointCloud(cloud[i], std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
		view->viewer->updatePointCloud(cloud[i], std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
	}
	view->update();
}

void MainWindow::ChangeColour()
{
	QColor color = QColorDialog::getColor(Qt::white, this, "Select color for point cloud");
	if (color.isValid())
	{
		QList<QTreeWidgetItem*> itemList = tree->m_tree->selectedItems();
		int selected_item_count = tree->m_tree->selectedItems().size();
		if (0 == selected_item_count)
		{
			for (int i = 0; i != cloud.size(); i++)
			{
				for (int j = 0; j != cloud[i]->points.size(); j++)
				{
					cloud[i]->points[j].r = color.red();
					cloud[i]->points[j].g = color.green();
					cloud[i]->points[j].b = color.blue();
				}
			}
		}
		else
		{
			for (int i = 0; i != selected_item_count; i++)
			{
				int cloud_id = tree->m_tree->indexOfTopLevelItem(itemList[i]);
				for (int j = 0; j != cloud[cloud_id]->size(); j++)
				{
					cloud[cloud_id]->points[j].r = color.red();
					cloud[cloud_id]->points[j].g = color.green();
					cloud[cloud_id]->points[j].b = color.blue();
				}
				//view->viewer->addPointCloud(cloud[cloud_id], std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
			}
		}
		

	}
	for (unsigned i = 0; i < cloud.size(); ++i)
	{
		view->viewer->updatePointCloud(cloud[i],
			std::string((const char*)fileName.at(i).toLocal8Bit()).c_str());
	}
	view->update();

}



	
	



