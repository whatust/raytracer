#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "object.hpp"
#include "point.hpp"
#include "vector.hpp"


class Sphere: public Object{

public:	
	Sphere();
	Spehre(Sphere &other);

	double intersect(Point &e, Vector &d);
	Vector getNormal(Point &p);

private:
	double radius;

};

#endif