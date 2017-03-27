#include <math.h>
#include "plane.h"

double Plane::itersect(const Vector &e, const Vector &d){
	
	double ez;
	double dz;

	ez = e.z;
	dz = d.z;
	
	if(!dz)
		return −1;
	
	return −ez/dz;
}