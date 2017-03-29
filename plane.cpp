#include <math.h>
#include "plane.hpp"

double Plane::itersect(const Vector &e, const Vector &d){
	
	double ez;
	double dz;

	ez = e.z;
	dz = d.z;
	
	if(!dz)
		return −1;
	
	return −ez/dz;
}