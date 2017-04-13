#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <algorithm>

#include "point.hpp"

class Vector{
	
	public:
		Vector();
		Vector(Point p);
		Vector(double x, double y, double z);
		Vector(double x, double y, double z, double w);

		Vector& operator=(Vector rhs);
		Vector& operator+=(const Vector &rhs);
		Vector& operator-=(const Vector &rhs);
		Vector& operator*=(const double &rhs);
		Vector& operator/=(const double &rhs);
		Vector operator+(const Vector &rhs);
		Vector operator-(const Vector &rhs);
		Vector operator*(const double &rhs);
		Vector operator/(const double &rhs);

		void print();
		void swap(Vector& first, Vector& second);

		double size();
		Vector normalize();
		double dot_product(const Vector &other);
		Vector cross_product(const Vector &rhs);
		Point findPoint(double d);

		double get_x();
		double get_y();
		double get_z();

	private:

		double x, y, z, w;
};

#endif