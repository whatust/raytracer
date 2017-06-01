#include "material.hpp"

Material::Material(const std::string name) : name(name), color(cv::Mat(3, 1, CV_64F, cv::Scalar::all(0))), reflectance(0.0), refractance(0.0), specular_coeff(0), diffuse_coeff(0), f(10.0){}

Material::Material(const std::string name, cv::Mat color) : name(name), color(color), reflectance(0.0), refractance(0.0), specular_coeff(0), diffuse_coeff(0), f(10.0){}

Material::Material(const std::string name, cv::Mat color, double refletance, double refractance) : name(name), color(color), reflectance(refletance), refractance(refractance),\
specular_coeff(0), diffuse_coeff(0), f(10.0){}

Material::Material(const std::string name, cv::Mat color, double refletance, double refractance, double specular_coeff, double diffuse_coeff, double f) : color(color), reflectance(refletance), refractance(refractance),\
specular_coeff(specular_coeff), diffuse_coeff(diffuse_coeff), f(f){}

void Material::print(){
	std::cout << "Color ";
	util::printMat<double>(color);

	std::cout << "reflectance/refractance " << reflectance << " " << refractance << std::endl;
	std::cout << "specular_coeff/diffuse_coeff " << specular_coeff << " " << diffuse_coeff << std::endl;
	std::cout << "f " << f << std::endl;
}
