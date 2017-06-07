#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <memory>
#include <math.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "material.hpp"

typedef enum object_{SPHERE, PLANE} object_t;

class Object{
protected:
	cv::Mat M;
	cv::Mat Minv;
	object_t type;
	std::shared_ptr<Material> material;
	
public:

	Object(object_t t, std::shared_ptr<Material> materila_ptr);
	Object(object_t t, cv::Mat M, std::shared_ptr<Material> materila_ptr);
	Object(object_t t, double pos[3], double rot[3], double scl[3], std::shared_ptr<Material> materila_ptr);
	~Object();

	std::shared_ptr<Material> getMaterial();

	cv::Mat getM();
	cv::Mat getMinv();

	virtual cv::Mat getNormal(const cv::Mat &p) = 0;
	virtual double intersect(const cv::Mat &p, const cv::Mat &d) = 0;

	void print();
};

#endif