#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "point.hpp"
#include "vector.hpp"

typedef enum object_{SPHERE, PLANE} object_t;

class Object{
public:
	Point center;
	object_t type;

	Object(object_t t);
	Object(object_t t, Point c);
	virtual double intersect(Vector const &e, Vector const &d) = 0;

};

#endif