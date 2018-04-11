//http://tieba.baidu.com/p/4101387026

#pragma once
#include <QVTKWidget.h>
#include <vtkAutoInit.h> 
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

#include<pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
class vtkRenderer;
class	vtkRenderWindowInteractor;
class myVtkWidget:
	public QVTKWidget
{
	Q_OBJECT
public:
	explicit myVtkWidget(QWidget *parent = 0);
	vtkRenderer *ren1;
	vtkRenderWindowInteractor *iren;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;

};