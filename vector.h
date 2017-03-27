#ifndef __VECTOR_H__
#define __VECTOR_H__

class Vector{
	
public:
	double x, y, z, w;
	
	Vector() : x(0), y(0), z(0), w(1){};

	Vector(double x_, double y_, double z_) :
		x(x_), y(y_), z(z_), w(1.0){};

	Vector(double x_, double y_, double z_, double w_) :
		x(x_), y(y_), z(z_), w(w_){};

	void normalize();

	double lenght();

	Vector operator + (Vector const v) const;

	Vector operator += (Vector const v);

	Vector operator - (Vector const v1)const;

	Vector operator -= (Vector const v);
};

Vector cross_product(Vector const v1, Vector const v2);

double dot_product(Vector const v1, Vector const v2);

#endif