#include "material.hpp"

Material::Material() : color(Color()), reflectance(0.0), refractance(0.0), specular_coeff(0), diffuse_coeff(0), f(10.0){}

Material::Material(Color color) : color(color), reflectance(0.0), refractance(0.0), specular_coeff(0), diffuse_coeff(0), f(10.0){}

Material::Material(Color color, double refletance, double refractance) : color(color), reflectance(refletance), refractance(refractance),\
specular_coeff(0), diffuse_coeff(0), f(10.0){}

Material::Material(Color color, double refletance, double refractance, double specular_coeff, double diffuse_coeff, double f) : color(color), reflectance(refletance), refractance(refractance),\
specular_coeff(specular_coeff), diffuse_coeff(diffuse_coeff), f(f){}

void Material::print(){
	std::cout << "Color ";
	color.print();

	std::cout << "reflectance/refractance " << reflectance << " " << refractance << std::endl;
	std::cout << "specular_coeff/diffuse_coeff " << specular_coeff << " " << diffuse_coeff << std::endl;
	std::cout << "f " << f << std::endl;
}
