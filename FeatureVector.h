#ifndef  FEATURE_VECTOR_H
#define  FEATURE_VECTOR_H
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
//向量计算
void FeaVector(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud,float &m1, float &m2,float &m3);
//顶部与底部投影比值

//投影密度
void ProjectedDensity(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud, float &m, float &Density_XOY, float &Density_YOZ, float &Density_XOZ);

#endif



