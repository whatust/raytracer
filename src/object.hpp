#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "point.hpp"
#include "vector.hpp"
#include "material.hpp"

typedef enum object_{SPHERE, PLANE} object_t;

class Object{
protected:
	Point center;
	object_t type;
	Material material;
	
public:

	Object(object_t t);
	Object(object_t t, Point c);
	virtual Vector getNormal(Point &p) = 0;
	virtual double intersect(Point &p, Vector &d) = 0;
};

#endif