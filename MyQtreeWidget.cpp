#include "MyQtreeWidget.h"
#include <QMessageBox>

//myQTreeWidget::myQTreeWidget()
//{
//}
myQTreeWidget::myQTreeWidget(QWidget *parent /*= 0*/) :QTreeWidget(parent)
{
	this->m_tree = new QTreeWidget;

}
myQTreeWidget::~myQTreeWidget()
{
}

void myQTreeWidget::creattree(QStringList Title)
{
	
	//模拟读取的文件名
	//添加 QTreeWidgetItem(这里是读取文件夹里文件的名字作为item的名字)
	for (unsigned i = 0; i < Title.size(); i++)
	{
		
		QTreeWidgetItem *leaf = new QTreeWidgetItem(this->m_tree, QStringList() << Title[i]);//插入对象
		leaf->setFlags(leaf->flags() | Qt::ItemIsEditable);// 设置该项的标志。例如该项是否被选择，是否被点击，是否使能等
		leaf->setCheckState(0, Qt::Checked);
		//root->addChild(leaf);
	}
}


