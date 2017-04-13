#ifndef __POINT_H__
#define __POINT_H__

#include <algorithm>
#include <iostream>

class Point{
	
	public:

		Point();
		Point(double x, double y, double z);
		~Point();

		Point& operator=(Point other);
		Point& operator+=(const Point &rhs);
		Point& operator-=(const Point &rhs);
		Point operator+(const Point &rhs);
		Point operator-(const Point &rhs);

		void print();
		void swap(Point& first, Point& second);

		double get_x();
		double get_y();
		double get_z();

	private:
		double x, y, z;

};

#endif