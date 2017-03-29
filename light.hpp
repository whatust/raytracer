#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "point.hpp"
#include "vector.hpp"
#include "color.hpp"

class Light{

public:
	Point pos;
	Color color;
	double intensity;

	Light(Point pos_, double intensity_);
	Light(Point pos_, Color color_, double intensity_);
};

#endif