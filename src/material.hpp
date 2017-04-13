#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "color.hpp"

class Material{
	public:
	Color color;
	double reflectance;
	double refractance;
	double specular_coeff;
	double diffuse_coeff;
	double f;

	Material();
	Material(Color color);
	Material(Color color, double reflectance, double refractance);
	Material(Color color, double refletance, double refractance, double specular_coeff, double diffuse_coeff, double f);

	void print();
};

#endif