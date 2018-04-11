#pragma  once//保证头文件只被编译一次
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

pcl::PointCloud<pcl::PointXYZRGB>::Ptr pcdRead(std::string file_name, pcl::PointCloud<pcl::PointXYZRGB>::Ptr data);
pcl::PointCloud<pcl::PointXYZ>::Ptr pcdRead(std::string file_name, pcl::PointCloud<pcl::PointXYZ>::Ptr data);

pcl::PointCloud<pcl::PointXYZRGB>::Ptr txtRead(std::string file_name, pcl::PointCloud<pcl::PointXYZRGB>::Ptr data);
pcl::PointCloud<pcl::PointXYZ>::Ptr txtRead(std::string file_name, pcl::PointCloud<pcl::PointXYZ>::Ptr data);

pcl::PointCloud<pcl::PointXYZRGB>::Ptr lasRead(std::string file_name);
/////////////////////////////////////////////////////////////////
void WirtePcd(std::string file_name,pcl::PointCloud<pcl::PointXYZRGB>::Ptr &data);
void WriteTxt(std::string file_name, pcl::PointCloud<pcl::PointXYZRGB>::Ptr &data);