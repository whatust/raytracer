#include "light.hpp"

Light::Light() : pos(Point()), intensity(1.0), color(Color()){}

Light::Light(Point pos, double intensity) : pos(pos), intensity(intensity),	color(Color()){}

Light::Light(Point pos, Color color, double intensity) : pos(pos), color(color), intensity(intensity){}

void Light::print(){
	std::cout << "pos ";
	this->pos.print();
	std::cout << "color ";
	this->color.print();
	std::cout << "intensity" << this->intensity << std::endl; 
}
