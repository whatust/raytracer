#include "light.hpp"

Light::Light() : pos((cv::Mat_<double>(3, 1) << 0, 0, 0)), intensity(1.0), color((cv::Mat_<double>(3, 1) << 0, 0, 0)){}

Light::Light(cv::Mat pos, double intensity) : pos(pos), intensity(intensity),	color((cv::Mat_<double>(3, 1) << 0, 0, 0)){}

Light::Light(cv::Mat pos, cv::Mat color, double intensity) : pos(pos), color(color), intensity(intensity){}

Light::~Light(){
	pos.release();
	color.release();
}

cv::Mat Light::getPosition() const {
	return pos;
}

cv::Mat Light::getColor() const {
	return color;
}

void Light::print(){
	std::cout << "pos ";
	util::printMat<double>(pos);
	std::cout << "color ";
	util::printMat<double>(color);
	std::cout << "intensity" << intensity << std::endl; 
}
