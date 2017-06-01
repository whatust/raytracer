#ifndef __PLANE_H__
#define __PLANE_H__

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "object.hpp"

class Plane: public Object{
public:

Plane(std::shared_ptr<Material> materila_ptr);
Plane(cv::Mat M, std::shared_ptr<Material> materila_ptr);
Plane(double pos[3], double rot[3], double scl[3], std::shared_ptr<Material> materila_ptr);

	double intersect(const cv::Mat &e, const cv::Mat &d);
	cv::Mat getNormal(const cv::Mat &p);
	
private:
};

#endif