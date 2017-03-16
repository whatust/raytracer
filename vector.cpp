#include <math.h>
#include "vector.h"

void Vector::normalize(){
	double l = this->length();
	x = x/l; y = y/l; z = z/l;

	return;
}

double Vector::length() const{
   return sqrtf(x*x + y*y + z*z);
}

Vector Vector::operator +(Vector const &v) const{
	return Vector(x+v.x, y+v.y.z+v.z);
}

Vector Vector::operator -(Vector const &v) const{
	return Vector(x-v.x, y-v.y.z-v.z);
}

Vector Vector::operator +=(Vector const &v) const{
	x += v.x;	y += v.y;	z += v.z;
	return this;
}

Vector Vector::operator -=(Vector const &v) const{
	x -= v.x;	y -= v.y;	z -= v.z;
	return this;
}

Vector cross_product(Vector const v1, Vector const v2){
	return Vector(v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x);
}

double dot_product(Vector const &v1, Vector const &v2){
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}