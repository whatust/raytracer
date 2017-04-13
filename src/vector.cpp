#include <math.h>
#include "vector.hpp"


Vector::Vector() : x(0), y(0), z(0), w(1){};

Vector::Vector(Point p) : \
		x(p.get_x()), y(p.get_y()), z(p.get_z()), w(1.0){};

Vector::Vector(double x, double y, double z) : \
		x(x), y(y), z(z), w(1.0){};

Vector::Vector(double x, double y, double z, double w) : \
		x(x), y(y), z(z), w(w){};

void Vector::swap(Vector& first, Vector& second){

	using std::swap;

	swap(first.x, second.x);
	swap(first.y, second.y);
	swap(first.z, second.z);
	swap(first.w, second.w);
}

Vector& Vector::operator=(Vector other){
	swap(*this, other);
	return *this;
}

Vector& Vector::operator+=(const Vector &rhs){
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	this->w += rhs.w;
	return *this;
}

Vector& Vector::operator-=(const Vector &rhs){
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	this->w -= rhs.w;
	return *this;
}

Vector& Vector::operator*=(const double &rhs){
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	this->w *= rhs;
	return *this;
}

Vector& Vector::operator/=(const double &rhs){
	this->x /= rhs;
	this->y /= rhs;
	this->z /= rhs;
	this->w /= rhs;
	return *this;
}

Vector Vector::operator+(const Vector &rhs){
	Vector lhs = Vector(*this);
	lhs += rhs;
	return lhs;
}

Vector Vector::operator-(const Vector &rhs){
	Vector lhs = Vector(*this);
	lhs -= rhs;
	return lhs;
}

Vector Vector::operator*(const double &rhs){
	Vector lhs = Vector(*this);
	lhs *= rhs;
	return lhs;
}

Vector Vector::operator/(const double &rhs){
	Vector lhs = Vector(*this);
	lhs /= rhs;
	return lhs;
}

double Vector::size(){
   return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vector Vector::normalize(){
	*this /= this->size();
	return *this;
}

double Vector::dot_product(const Vector &other){
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vector Vector::cross_product(const Vector &other){
	Vector lhs = Vector();
	lhs.x = this->y * other.z - this->z * other.y;
	lhs.y = this->z * other.x - this->x * other.z;
	lhs.z = this->x * other.y - this->y * other.x;
	return lhs;
}

Point Vector::findPoint(double d){
	Vector lhs = Vector(*this);
	lhs *= d;
	return Point(lhs.x, lhs.y, lhs.z);
}

void Vector::print(){
	std::cout << this->x << " " << this->y << " " << this->z << std::endl;
}

double Vector::get_x(){return this->x;}
double Vector::get_y(){return this->y;}
double Vector::get_z(){return this->z;}
