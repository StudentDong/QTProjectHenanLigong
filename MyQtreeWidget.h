//#pragma once
#include <QTreeWidget>
class myQTreeWidget:public QTreeWidget
{
	Q_OBJECT
public:
	//构造函数
	myQTreeWidget(QWidget *parent = 0);
	//myQTreeWidget();
	//myQTreeWidget();
	//析构函数
	~myQTreeWidget();
public:
	QTreeWidget* m_tree;//节点父窗体
	QStringList m_title;
	bool Flag;
public:
	void creattree(QStringList fileName);
private:
	private slots:
	

};


