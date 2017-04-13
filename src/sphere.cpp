#include <math.h>
#include "sphere.hpp"

double Sphere::intersect(Point &e, Vector &d){
	
	double eSize = dot_product(e,e)-1;
	double dSize = dot_product(d,d);
	double edSize = dot_product(e,d);

	double delta = edSize*edSize - eSize*dSize;

	if(delta < 0)
		return -1.0;
	
	if(delta == 0)
		return -edSize/dSize;

	double t0, t1;

	t0 = (-edSize/dSize) + sqrt(delta)/dSize;
	t1 = (-edSize/dSize) - sqrt(delta)/dSize;

	if(t0 < t1)
		return t0;
	else
		return t1;
}