#include "FeatureVector.h"
#include <pcl/common/pca.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <vector>
#include <pcl/common/common.h>
void FeaVector(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud, float &m1, float &m2, float &m3)
{
	pcl::PCA<pcl::PointXYZRGB> PCACloud;
	PCACloud.setInputCloud(cloud);
	Eigen::Vector3f M;
	M = PCACloud.getEigenValues();
	m1 = (M(0) - M(1)) / M(0);
	m2 = (M(1) - M(2) )/ M(0);
	m3 = M(2) / M(0);

}


void ProjectedDensity(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud, float &m, float &Density_XOY,float &Density_YOZ, float &Density_XOZ)
{
	struct point2D
	{
		float x;
		float y;
		float z;
		
	};
	//std::vector<point2D> temp;
	pcl::PointXYZRGB MaxCloud;
	pcl::PointXYZRGB MinCloud;
	pcl::getMinMax3D(*cloud, MinCloud, MaxCloud);
	int m_Gx = ((MaxCloud.x - MinCloud.x) / 0.02) + 1;
	int m_Gy = ((MaxCloud.y - MinCloud.y) / 0.02) + 1;
	int m_Gz = ((MaxCloud.z - MinCloud.z) / 0.02) + 1;
	/////////////////////////////////////////////
	std::vector<std::vector<std::vector<point2D> > > Temp_V(m_Gx,  
		std::vector<std::vector<point2D> >(m_Gy));
	point2D temp_P2D;
	for (int i = 0; i < cloud->points.size(); i++)
	{
		temp_P2D.x = cloud->points[i].x;
		temp_P2D.y = cloud->points[i].y;
		temp_P2D.z = 0;
		Temp_V[floor((temp_P2D.x - MinCloud.x) / 0.02)][floor((temp_P2D.y - MinCloud.y) / 0.02)].push_back(temp_P2D);
	}
	float num = 0;
	for (int i = 0; i < Temp_V.size(); i++)
	{
		for (int j = 0; j < Temp_V[i].size(); j++)
		{
			if (!Temp_V[i][j].empty())
			{
				num++;
			}
		}
	}
	/////////////////////////////////////////
	std::vector<std::vector<std::vector<point2D> > > Temp_VXoZ(m_Gx,
		std::vector<std::vector<point2D> >(m_Gz));
	/*std::vector<point2D> Temp_VXoZ1;
	std::vector<std::vector<point2D> > Temp_VXoZ2(m_Gx+1, Temp_VXoZ1);
	std::vector<std::vector<std::vector<point2D> > > Temp_VXoZ(m_Gz+1, Temp_VXoZ2);*/
	for (int i = 0; i < cloud->points.size(); i++)
	{
		
		temp_P2D.x = cloud->points[i].x;
		temp_P2D.y = 0;
		temp_P2D.z = cloud->points[i].z;
		/*	if (floor((temp_P2D.x - MinCloud.x) / 0.02) < Temp_VXoZ2.size()||floor((temp_P2D.z - MinCloud.z) / 0.02) < Temp_VXoZ.size())
			{*/
		Temp_VXoZ[floor((temp_P2D.x - MinCloud.x) / 0.02)][floor((temp_P2D.z - MinCloud.z) / 0.02)].push_back(temp_P2D);
		
			
	/*	else
		{
			int a = floor((temp_P2D.x - MinCloud.x) / 0.02);
			int b = floor((temp_P2D.z - MinCloud.z) / 0.02);
		}*/

	}
	float num1 = 0;
	for (int i = 0; i < Temp_VXoZ.size(); i++)
	{
		for (int j = 0; j < Temp_VXoZ[i].size(); j++)
		{
			if (!Temp_VXoZ[i][j].empty())
			{
				num1++;
			}
		}
	}
	////////////////////////////////////////////////////////////////////
	/*std::vector<point2D> Temp_VYoZ1;
	std::vector<std::vector<point2D> > Temp_VYoZ2(m_Gy, Temp_VYoZ1);
	std::vector<std::vector<std::vector<point2D> > > Temp_VYoZ(m_Gz, Temp_VYoZ2);´í*/
	///////////////////////////////////////////////////////////////////
	std::vector<std::vector<std::vector<point2D> > > Temp_VYoZ(m_Gy,
		std::vector<std::vector<point2D> >(m_Gz));
	for (int i = 0; i < cloud->points.size(); i++)
	{
		temp_P2D.x = 0;
		temp_P2D.y = cloud->points[i].y;
		temp_P2D.z = cloud->points[i].z;
		Temp_VYoZ[floor((temp_P2D.y - MinCloud.y) / 0.02)][floor((temp_P2D.z - MinCloud.z) / 0.02)].push_back(temp_P2D);
	}
	float num2 = 0;
	for (int i = 0; i < Temp_VYoZ.size(); i++)
	{
		for (int j = 0; j < Temp_VYoZ[i].size(); j++)
		{
			if (!Temp_VYoZ[i][j].empty())
			{
				num2++;
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////
	using namespace std;
	std::vector<std::vector<std::vector<std::vector<point2D> > > > Temp_3V(m_Gx,vector<vector<vector<point2D> > >(
		m_Gy,vector<vector<point2D> >(m_Gz) ) );
	for (int i = 0; i < cloud->points.size(); i++)
	{
		temp_P2D.x = cloud->points[i].x;
		temp_P2D.y = cloud->points[i].y;
		temp_P2D.z = cloud->points[i].z;
		Temp_3V[floor((temp_P2D.x - MinCloud.x) / 0.02)][floor((temp_P2D.y - MinCloud.y) / 0.02)][floor((temp_P2D.z - MinCloud.z) / 0.02)].push_back(temp_P2D);
	}
	float num3 = 0;
	for (int i = 0; i < Temp_3V.size(); i++)
	{
		for (int j = 0; j < Temp_3V[i].size(); j++)
		{
			for (int k = 0; k < Temp_3V[i][j].size(); k++)
			{
				if (!Temp_3V[i][j][k].empty())
				{
					num3++;
				}
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////
	float Area=0.02*0.02*num;
	float Area1 = 0.02*0.02*num1;
	float Area2 = 0.02*0.02*num2;
	Density_XOY= (cloud->points.size()) / Area;
	Density_XOZ = (cloud->points.size()) / Area1;
	Density_YOZ = (cloud->points.size()) / Area2;
	/*Density_XOY = float((num3) /num );
	Density_XOZ =float((num3) / num1);
	Density_YOZ = float((num3) / num2);*/

	//Í·¸Ë±È
	m = Area / (3.14*0.25*0.25);

}