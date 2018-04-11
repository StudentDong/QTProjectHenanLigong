#include "MyVtkWidget.h"
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
myVtkWidget::myVtkWidget(QWidget *parent /* = 0 */) :
QVTKWidget(parent)
{
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	this->ren1 = vtkRenderer::New();
	this->GetRenderWindow()->AddRenderer(ren1);
	this->iren = this->GetInteractor();
	SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(GetInteractor(), GetRenderWindow());
	update();
}