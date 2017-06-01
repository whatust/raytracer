#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "object.hpp"
#include "util.hpp"

class Sphere: public Object{

public:	

Sphere(std::shared_ptr<Material> materila_ptr);
Sphere(cv::Mat M, std::shared_ptr<Material> materila_ptr);
Sphere(double pos[3], double rot[3], double scl[3], std::shared_ptr<Material> materila_ptr);

	double intersect(const cv::Mat &e, const cv::Mat &d);
	cv::Mat getNormal(const cv::Mat &p);

private:
};

#endif