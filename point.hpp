#ifndef __POINT_H__
#define __POINT_H__

class Point{
	
public:
	double x, y, z;

	Point();

	Point(double x, double y, double z);

	Point operator + (Point const &p) const;

	Point operator += (Point const &p);

	Point operator - (Point const &p)const;

	Point operator -= (Point const &p);
};

#endif