#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "util.hpp"

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

class Material{
	public:
	std::string name;
	cv::Mat color;
	double reflectance;
	double refractance;
	double specular_coeff;
	double diffuse_coeff;
	double f;

	Material(const std::string name);
	Material(const std::string name, cv::Mat color);
	Material(const std::string name, cv::Mat color, double reflectance, double refractance);
	Material(const std::string name, cv::Mat color, double refletance, double refractance, double specular_coeff, double diffuse_coeff, double f);

	void print();
};

#endif