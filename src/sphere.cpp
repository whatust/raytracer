#include <math.h>
#include "sphere.hpp"

Sphere::Sphere(std::shared_ptr<Material> materila_ptr) : Object(SPHERE, materila_ptr) {}

Sphere::Sphere(cv::Mat M, std::shared_ptr<Material> materila_ptr) : Object(SPHERE, M, materila_ptr) {}

Sphere::Sphere(double pos[3], double rot[3], double scl[3], std::shared_ptr<Material> materila_ptr) : Object(SPHERE, pos, rot, scl, materila_ptr) {}

double Sphere::intersect(
						const cv::Mat &e,
						const cv::Mat &d){
	
	double eSize = e.dot(e) - 1;
	double dSize = d.dot(d);
	double edSize = e.dot(d);

	double delta = edSize*edSize - eSize*dSize;

	/*std::cout << "ed " << edSize << " e " << eSize << " d " << dSize << std::endl;
	std::cout << "delta " << delta << std::endl;*/

	if(delta < 0)
		return -1.0;
	
	if(delta == 0)
		return -edSize/dSize;

	double t0, t1;

	t0 = (-edSize/dSize) + sqrt(delta)/dSize;
	t1 = (-edSize/dSize) - sqrt(delta)/dSize;

	if(t0 < t1)
		return t0;
	else
		return t1;
}

cv::Mat Sphere::getNormal(const cv::Mat &p){
	return p;
}
