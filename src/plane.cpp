#include <math.h>
#include "plane.hpp"

Plane::Plane() : Object(PLANE), normal(Vector(0.0, 0.0, 1.0, 1.0)) {}

Plane::Plane(Point p) : Object(PLANE, p), normal(Vector(0.0, 0.0, 1.0, 1.0)) {}

Plane::Plane(Point p, Vector v) : Object(PLANE, p), normal(v) {}

double Plane::intersect(Point &e, Vector &d){
	
	double ez;
	double dz;

	ez = e.get_z();
	dz = d.get_z();
	
	if(!dz)
		return -1;
	
	return -ez/dz;
}

Vector Plane::getNormal(Point &p){
	return normal;
}

void Plane::print(){
	std::cout << "Center ";
	center.print();

	std::cout << "Normal ";
	normal.print();
}
