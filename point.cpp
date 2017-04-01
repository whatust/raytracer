#include "point.hpp"


Point::Point() : x(0.0), y(0.0), z(0.0){}

Point::Point(double x, double y, double z) : x(x), y(y), z(z){}

Point Point::operator +(Point const &p) const{
	return Point(x+p.x, y+p.y, z+p.z);
}

Point Point::operator -(Point const &p) const{
	return Point(x-p.x, y-p.y, z-p.z);
}

Point Point::operator +=(Point const &p){
	x += p.x;	y += p.y;	z += p.z;
	return *this;
}

Point Point::operator -=(Point const &p){
	x -= p.x;	y -= p.y;	z -= p.z;
	return *this;
}