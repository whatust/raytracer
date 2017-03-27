#include "pointer.h"

Point Point::operator +(Point const &v) const{
	return Point(x+v.x, y+v.y.z+v.z);
}

Point Point::operator -(Point const &v) const{
	return Point(x-v.x, y-v.y.z-v.z);
}

Point Point::operator +=(Point const &v) const{
	x += v.x;	y += v.y;	z += v.z;
	return this;
}

Point Point::operator -=(Point const &v) const{
	x -= v.x;	y -= v.y;	z -= v.z;
	return this;
}