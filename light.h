#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "vector.h"

class Light{

public:
	Point pos;
	Color color;
	double intensity;

	Light(Point pos_, double intensity){
		pos(pos_); intensity(intensity_);
		color.r = 255; color.g = 255; color.b = 255;
	}

	Light(Point pos_, Color color_, double intensity_) :
		pos(pos_), color(color_), intensity(intensity_){};
}

#endif