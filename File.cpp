#include "File.h"
#include <QMessageBox>
#include <ctime>
#include <fstream> //对文件进行操作
///////////////////////////////////////
pcl::PointCloud<pcl::PointXYZRGB>::Ptr pcdRead(std::string file_name, pcl::PointCloud<pcl::PointXYZRGB>::Ptr data)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr data1(new pcl::PointCloud<pcl::PointXYZRGB>);
	//pcl::PCLPointCloud2
	pcl::io::loadPCDFile(file_name, *data1);
	int colorIndex[3][3] = { { 255, 0, 0 }, { 0, 255, 0 }, { 0, 0, 255 } };
	srand((unsigned)time(0));
 	int t = rand() % 3;
	for (int i = 0; i < data1->points.size(); ++i)
	{
		data1->points[i].r = colorIndex[t][0];
		data1->points[i].g = colorIndex[t][1];
		data1->points[i].b = colorIndex[t][2];
	}
	data.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	data->resize(data1->size());
	pcl::copyPointCloud(*data1,*data);
	return data;
}

pcl::PointCloud<pcl::PointXYZ>::Ptr pcdRead(std::string file_name,pcl::PointCloud<pcl::PointXYZ>::Ptr data)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr data1(new pcl::PointCloud<pcl::PointXYZ>);
	////pcl::PCLPointCloud2
	pcl::io::loadPCDFile(file_name, *data1);
	////int colorIndex[3][3] = { { 255, 0, 0 }, { 0, 255, 0 }, { 0, 0, 255 } };
	data.reset(new pcl::PointCloud<pcl::PointXYZ>);
	data->resize(data1->size());
	pcl::copyPoint(*data1,*data);
	return data;
}

/////////////////////////////////////////////////////////
pcl::PointCloud<pcl::PointXYZRGB>::Ptr txtRead(std::string file_name, pcl::PointCloud<pcl::PointXYZRGB>::Ptr data1)
{
	//pcl::PointCloud<pcl::PointXYZRGB>::Ptr data(new pcl::PointCloud< pcl::PointXYZRGB>);
	data1.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	bool isCoordinateShift = false;
	int colorIndex[5][3] = { { 255, 0, 0 }, { 0, 255, 0 }, { 0, 0, 255 }, { 255, 255, 0 }, { 0, 255, 255 } };
	FILE *fp = NULL;
	fp = fopen(file_name.c_str(), "r");
	if (fp == NULL)
	{
		QMessageBox::information(NULL, QObject::tr("Error"), QObject::tr("Cannot open files."));
		return data1;
	}
	pcl::PointXYZRGB f_xyz;
	float x, y, z;
	srand((unsigned)time(0));
	int t = rand() % 5;
	while (fscanf(fp, "%f %f %f", &x, &y, &z) != EOF)
	{
		//f_xyz = QColor(Qt::red);
		f_xyz.x = x;
		f_xyz.y = y;
		f_xyz.z = z;
		f_xyz.r = colorIndex[t][0];
		f_xyz.g = colorIndex[t][1];
		f_xyz.b = colorIndex[t][2];
		data1->points.push_back(f_xyz);
	}
	
	//data1->resize(data->size());
	//pcl::copyPoint(*data,*data1);
	 

	fclose(fp);
	return data1;
}
pcl::PointCloud<pcl::PointXYZ>::Ptr txtRead(std::string file_name, pcl::PointCloud<pcl::PointXYZ>::Ptr data)
{
	using namespace std;
	pcl::PointCloud<pcl::PointXYZ>::Ptr data1(new pcl::PointCloud<pcl::PointXYZ>);
	bool isCoordinateShift = false;
	ifstream file;
	
	file.open(file_name, ios::in);
	if (file.fail())
	{
		QMessageBox::information(NULL, QObject::tr("Error"), QObject::tr("Cannot open files."));
		file.close();
		return data1;
	}
	//float x,y,z;
	pcl::PointXYZ tempcloud;
	while (!file.eof())
	{
		file >>tempcloud.x>>tempcloud.y>>tempcloud.z ;
		data1->push_back(tempcloud);
		//data->push_back(temp);
	}
	data.reset(new pcl::PointCloud<pcl::PointXYZ>);
	data->resize(data1->size());
	pcl::copyPoint(*data1, *data);
	file.close();
	return data;

	

	//fp=fopen()

}
/////////////////////////////////////////////////////
pcl::PointCloud<pcl::PointXYZRGB>::Ptr lasRead(std::string file_name)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr data;

	return data;
}
//////////////////////////写文件
void WirtePcd(std::string file_name, pcl::PointCloud<pcl::PointXYZRGB>::Ptr &data)
{
	using namespace std;
	pcl::PointCloud<pcl::PointXYZRGB> cloud;
	cloud.width = data->points.size();
	cloud.height = 1;
	cloud.is_dense = false;
	cloud.points.resize(cloud.width);
	for (size_t i = 0; i < cloud.points.size(); ++i)
	{
		cloud.points[i].x = data->points[i].x;
		cloud.points[i].y = data->points[i].y;
		cloud.points[i].z = data->points[i].z;
	}
	pcl::io::savePCDFileASCII(file_name, cloud);
}
void WriteTxt(std::string file_name, pcl::PointCloud<pcl::PointXYZRGB>::Ptr &data)
{
	FILE *p_txt;
	p_txt = fopen(file_name.c_str(), "w");
	if (p_txt == NULL)
	{
		QMessageBox::information(NULL, QObject::tr("Error"), QObject::tr("Cannot Save files."));
	}
	
	for (int i = 0; i < data->points.size(); i++)
	{
		fprintf(p_txt, "%.3f %.3f %.3f \n", data->points[i].x, data->points[i].y, data->points[i].z);
	}
	fclose(p_txt);
}