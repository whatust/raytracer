#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "color.hpp"

class Material{
	public:
	Color color;
	double reflectance;
	double refractance;

	Material();
	Material(Color color);
	Material(Color color, double reflectance, double refractance);
};

#endif