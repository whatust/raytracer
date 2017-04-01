#include <math.h>
#include "plane.hpp"

Plane::Plane() : Object(PLANE), normal(Vector(0.0, 0.0, 1.0, 1.0)) {}

Plane::Plane(Point p) : Object(PLANE, p), normal(Vector(0.0, 0.0, 1.0, 1.0)) {}

double Plane::intersect(Vector const &e, Vector const &d){
	
	double ez;
	double dz;

	ez = e.z;
	dz = d.z;
	
	if(!dz)
		return -1;
	
	return -ez/dz;
}