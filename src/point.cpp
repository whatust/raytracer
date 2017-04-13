#include "point.hpp"


Point::Point() : x(0.0), y(0.0), z(0.0){}

Point::Point(double x, double y, double z) : x(x), y(y), z(z){}

Point::~Point(){}

void Point::swap(Point& first, Point& second){

	using std::swap;

	swap(first.x, second.x);
	swap(first.y, second.y);
	swap(first.z, second.z);
}

Point& Point::operator=(Point other){
	swap(*this, other);
	return *this;
}

Point& Point::operator+=(const Point &rhs){
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}

Point& Point::operator-=(const Point &rhs){
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	return *this;
}

Point Point::operator+(const Point &rhs){
	Point lhs = Point(*this);
	lhs += rhs;
	return lhs;
}

Point Point::operator-(const Point &rhs){
	Point lhs = Point(*this);
	lhs -= rhs;
	return lhs;
}

void Point::print(){
	std::cout << this->x << " " << this->y << " " << this->z << std::endl;
}

double Point::get_x(){return this->x;}
double Point::get_y(){return this->y;}
double Point::get_z(){return this->z;}
