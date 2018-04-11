#include "Ransac.h"
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/passthrough.h>
#include <pcl/features/normal_3d.h>
#include <pcl/sample_consensus/method_types.h>
//#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <boost/thread/thread.hpp>
#include <pcl/kdtree/kdtree.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/extract_clusters.h>
pcl::PointCloud<pcl::PointXYZRGB>::Ptr  CylinderSegmentation(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &Cloud, float &InParam1, float &InParam2,
	float &InParam3, float &InParam4)
{
	// All the objects needed
	pcl::PassThrough<pcl::PointXYZRGB> pass;
	pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal> ne;
	pcl::SACSegmentationFromNormals<pcl::PointXYZRGB, pcl::Normal> seg;
	pcl::ExtractIndices<pcl::PointXYZRGB> extract;
	pcl::ExtractIndices<pcl::Normal> extract_normals;
	pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGB>());
	// Datasets
	//pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
	//pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGB>);
	pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(new pcl::PointCloud<pcl::Normal>);
	//pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered2(new pcl::PointCloud<pcl::PointXYZRGB>);
	//pcl::PointCloud<pcl::Normal>::Ptr cloud_normals2(new pcl::PointCloud<pcl::Normal>);
	pcl::ModelCoefficients::Ptr coefficients_plane(new pcl::ModelCoefficients), coefficients_cylinder(new pcl::ModelCoefficients);
	pcl::PointIndices::Ptr inliers_plane(new pcl::PointIndices), inliers_cylinder(new pcl::PointIndices);
	//点云进行法线统计
	ne.setInputCloud(Cloud);

	ne.setSearchMethod(tree);
	//ne.setRadiusSearch(0.02);
	ne.setKSearch(30);
	ne.compute(*cloud_normals);
	// Create the segmentation object for cylinder segmentation and set all the parameters
	seg.setOptimizeCoefficients(true);   //设置对估计模型优化
	seg.setModelType(pcl::SACMODEL_CYLINDER);  //设置分割模型为圆柱形
	seg.setMethodType(pcl::SAC_RANSAC);       //参数估计方法
	seg.setNormalDistanceWeight(InParam1);       //设置表面法线权重系数
	seg.setMaxIterations(InParam2);              //设置迭代的最大次数10000
	seg.setDistanceThreshold(InParam3);         //设置内点到模型的距离允许最大值
	seg.setRadiusLimits(0, InParam4);             //设置估计出的圆柱模型的半径的范围
	seg.setInputCloud(Cloud);
	seg.setInputNormals(cloud_normals);
	// Obtain the cylinder inliers and coefficients
	seg.segment(*inliers_cylinder, *coefficients_cylinder);
	extract.setInputCloud(Cloud);
	extract.setIndices(inliers_cylinder);

	extract.setNegative(false);//提取为外点ture
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_cylinder(new pcl::PointCloud<pcl::PointXYZRGB>());
	extract.filter(*cloud_cylinder);
	return cloud_cylinder;
}
//////////////////////////////
pcl::PointCloud<pcl::PointXYZRGB>::Ptr  RandomSampleConsensus(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &Cloud, float &InParam1, float &a, float &b, float &c, float &d)
{
	//保存局内点索引
	std::vector<int > inliers;
	//采样一致性
	pcl::SampleConsensusModelPlane<pcl::PointXYZRGB>::Ptr model_p(new pcl::SampleConsensusModelPlane<pcl::PointXYZRGB>(Cloud));
	pcl::RandomSampleConsensus<pcl::PointXYZRGB> ransac(model_p);
	ransac.setDistanceThreshold(InParam1);
	ransac.computeModel();
	ransac.getInliers(inliers);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr final(new pcl::PointCloud<pcl::PointXYZRGB>);
	final->resize(inliers.size());

	pcl::copyPointCloud<pcl::PointXYZRGB>(*Cloud, inliers, *final);
	Eigen::VectorXf coef = Eigen::VectorXf::Zero(4, 1);
	ransac.getModelCoefficients(coef);
	//a = coef[0] / coef[3]; b = coef[1] / coef[3]; c = coef[2] / coef[3]; d = 1
	a = 0.0f, b = 0.0f, c = 0.0f, d = 0.0f;
	a = coef[0]; c = coef[2];
	b = coef[1]; d = coef[3];
	return final;

}

/////////////////点到方程的距离
void PointToPlant(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &Cloud,float &ResidualSum,float &ResidualSquares)
{
	float a, b, c, d;
	float Inparame = 0.1f;
	ResidualSum = 0;
	//std::vector<float> &Dis_V;
	RandomSampleConsensus(Cloud, Inparame, a, b, c, d);
	float dis;
	for (int i = 0; i < Cloud->points.size(); i++)
	{
		dis = abs(a*Cloud->points[i].x + b*Cloud->points[i].y + c*Cloud->points[i].z + d) / sqrt(a*a + b*b + c*c);
		//Dis_V.push_back(dis);
		////总参差
		ResidualSum += (dis*dis);
		
	}
	ResidualSquares = sqrt(ResidualSum / Cloud->points.size());
}
///////////////欧式聚类
void EuropeCluster(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &Cloud, float &a, float &b, float &c, 
	std::vector<pcl::PointCloud<pcl::PointXYZRGB>::Ptr> &OutCloud)
{

	pcl::PointCloud<pcl::PointXYZRGB>::Ptr Incloud(new pcl::PointCloud<pcl::PointXYZRGB>);
	pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGB>);
	tree->setInputCloud(Cloud);//创建点云索引向量
	std::vector<pcl::PointIndices> cluster_indices;//点云组，用于储存分类后的点云
	pcl::EuclideanClusterExtraction<pcl::PointXYZRGB> ec;
	ec.setClusterTolerance(a);                     // 设置近邻搜索的搜索半径为2cm
	ec.setMinClusterSize(b);                 //设置一个聚类需要的最少的点数目为100
	ec.setMaxClusterSize(c);               //设置一个聚类需要的最大点数目为25000
	ec.setSearchMethod(tree);
	ec.setInputCloud(Cloud);
	ec.extract(cluster_indices);
	//迭代访问点云索引，直到分出所有类
	int j = 0;
	for (std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin(); it != cluster_indices.end(); ++it)
	{
		pcl::PointCloud<pcl::PointXYZRGB>::Ptr Cloud_Cluster(new pcl::PointCloud<pcl::PointXYZRGB>);
		for (std::vector<int>::const_iterator pit = it->indices.begin(); pit != it->indices.end(); pit++)
		{
			Cloud_Cluster->points.push_back(Cloud->points[*pit]);
		}
		Cloud_Cluster->width = Cloud_Cluster->points.size();
		Cloud_Cluster->height = 1;
		Cloud_Cluster->is_dense = true;
		OutCloud.push_back(Cloud_Cluster);
		j++;
	}
	
}

