#include "color.hpp"

Color::Color() : red(0.0), green(0.0), blue(0.0){}

Color::Color(const Color& other) : red(other.red), green(other.green), blue(other.blue){}

Color::Color(int red, int green, int blue) : red(red), green(green), blue(blue){}

Color::~Color(){}

void Color::swap(Color& first, Color& second){

	using std::swap;

	swap(first.red, second.red);
	swap(first.green, second.green);
	swap(first.blue, second.blue);
}

Color& Color::operator=(Color other){
	swap(*this, other);
	return *this;
}

Color& Color::operator+=(const Color &rhs){

	this->red += rhs.red;
	this->green += rhs.green;
	this->blue += rhs.blue;
	return *this;
}

Color& Color::operator-=(const Color &rhs){

	this->red -= rhs.red;
	this->green -= rhs.green;
	this->blue -= rhs.blue;
	return *this;
}

Color& Color::operator*=(const double &rhs){

	this->red *= rhs;
	this->green *= rhs;
	this->blue *= rhs;
	return *this;
}

Color& Color::operator/=(const double &rhs){

	this->red /= rhs;
	this->green /= rhs;
	this->blue /= rhs;
	return *this;
}

Color Color::operator+(const Color& rhs){
	Color lhs = Color(*this);
	lhs += rhs;
	return lhs;
}

Color Color::operator*(const double& rhs){
	Color lhs = Color(*this);
	lhs *= rhs;
	return lhs;
}

Color Color::operator-(const Color& rhs){
	Color lhs = Color(*this);
	lhs -= rhs;
	return lhs;
}

Color Color::operator/(const double& rhs){
	Color lhs = Color(*this);
	lhs /= rhs;
	return lhs;
}

void Color::print(){
	std::cout << this->red << " " << this->green << " " << this->blue << std::endl;
}
