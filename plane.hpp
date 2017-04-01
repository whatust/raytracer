#ifndef __PLANE_H__
#define __PLANE_H__

#include "object.hpp"
#include "point.hpp"
#include "vector.hpp"

class Plane: public Object{
public:
	Plane();
	Plane(Point p);
	double intersect(Vector const &e, Vector const &d);
	
private:
	Vector normal;
};

#endif