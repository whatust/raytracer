#ifndef __PLANE_H__
#define __PLANE_H__

#include "object.hpp"
#include "point.hpp"
#include "vector.hpp"

class Plane: public Object{
public:
	Plane();
	Plane(Point p);
	Plane(Point p, Vector v);
	double intersect(Point &e, Vector &d);
	Vector getNormal(Point &p);
	
	void print();
private:
	Vector normal;
};

#endif