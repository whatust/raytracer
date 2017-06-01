#include <math.h>
#include "plane.hpp"

Plane::Plane(std::shared_ptr<Material> materila_ptr) : Object(PLANE, materila_ptr) {}

Plane::Plane(cv::Mat M, std::shared_ptr<Material> materila_ptr) : Object(PLANE, M, materila_ptr){}

Plane::Plane(double pos[3], double rot[3], double scl[3], std::shared_ptr<Material> materila_ptr) : Object(PLANE, pos, rot, scl, materila_ptr){}

double Plane::intersect(
						const cv::Mat &e,
 						const cv::Mat &d){

	double ez = e.at<double>(2);
	double dz = d.at<double>(2);
	
	if(!dz)
		return -1;
	
	double ex = e.at<double>(0);
	double dx = d.at<double>(0);

	double ey = e.at<double>(1);
	double dy = d.at<double>(1);

	double px = ex + dx * -ez/dz;
	double py = ey + dy * -ez/dz;

	if(px > 0.5 || px < -0.5)
		return -1;

	if(py > 0.5 || py < -0.5)
		return -1;

	return -ez/dz;
}

cv::Mat Plane::getNormal(const cv::Mat &p){
	
	return (cv::Mat_<double>(3,1) << 0, 0, 1);
}
