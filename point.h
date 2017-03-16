#ifdef __POINT_H__
#define __POINT_H__

class Point{
	
public:
	double x, y, z;

	Point() :
		x(0.0), y(0.0), z(0.0){}

	Point(double x_, double y_, double z_) :
		x(x_), y(y_), z(z_){}

	Point operator + (Point const p) const;

	Point operator += (Point const p);

	Point operator - (Point const p)const;

	Point operator -= (Point const p);
};