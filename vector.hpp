#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "point.hpp"

class Vector{
	
public:
	double x, y, z, w;
	
	Vector() : x(0), y(0), z(0), w(1){};

	Vector(Point p);

	Vector(double x, double y, double z);

	Vector(double x, double y, double z, double w);

	void normalize();

	double lenght();

	Vector operator + (Vector const v) const;

	Vector operator += (Vector const v);

	Vector operator - (Vector const v1)const;

	Vector operator -= (Vector const v);
};

Vector cross_product(Vector const v1, Vector const v2);

double dot_product(Vector const v1, Vector const v2);

#endif