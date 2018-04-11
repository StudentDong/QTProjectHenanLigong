#include <OBB.h>
#include <pcl/features/moment_of_inertia_estimation.h>
#include <boost/thread/thread.hpp>
void CreateOBB(
pcl::PointCloud<pcl::PointXYZRGB>::Ptr &cloud,
pcl::PointXYZ &min_point_OBB,
pcl::PointXYZ &max_point_OBB,
pcl::PointXYZ &position_OBB,
Eigen::Matrix3f &rotational_matrix_OBB,
Eigen::Vector3f &mass_center,
Eigen::Vector3f &major_vector, 
Eigen::Vector3f &middle_vector,
Eigen::Vector3f &minor_vector)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr Incloud(new pcl::PointCloud<pcl::PointXYZ>);

	//pcl::MomentOfInertiaEstimation<pcl::PointXYZRGB> feature_extractor;
	pcl::MomentOfInertiaEstimation <pcl::PointXYZ> feature_extractor; //¹ßÐÔ¾Ø¹À¼Æ
	for (int i = 0; i < cloud->points.size(); i++)
	{
		pcl::PointXYZ cloudtemp;
		cloudtemp.x = cloud->points[i].x;
		cloudtemp.y = cloud->points[i].y;
		cloudtemp.z = cloud->points[i].z;
		Incloud->push_back(cloudtemp);
	}
	feature_extractor.setInputCloud(Incloud);
	feature_extractor.compute();
	std::vector <float> moment_of_inertia;
	std::vector <float> eccentricity;
	float major_value, middle_value, minor_value;
	feature_extractor.getMomentOfInertia(moment_of_inertia);
	feature_extractor.getEccentricity(eccentricity);
	feature_extractor.getOBB(min_point_OBB, max_point_OBB, position_OBB, rotational_matrix_OBB);
	feature_extractor.getEigenValues(major_value, middle_value, minor_value);
	feature_extractor.getEigenVectors(major_vector, middle_vector, minor_vector);
	feature_extractor.getMassCenter(mass_center);
	
}