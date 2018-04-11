#ifndef OBB_H
#define OBB_H 

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <vector>
void CreateOBB(
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud,
	pcl::PointXYZ &min_point_OBB,
	pcl::PointXYZ &max_point_OBB,
	pcl::PointXYZ &position_OBB,
	Eigen::Matrix3f &rotational_matrix_OBB,
	Eigen::Vector3f &mass_center,
	Eigen::Vector3f &major_vector,
	Eigen::Vector3f &middle_vector,
	Eigen::Vector3f &minor_vector);
#endif