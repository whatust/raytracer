#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <iostream>

#include "point.hpp"
#include "vector.hpp"
#include "color.hpp"

class Light{
	private:
		Point pos;
		Color color;
		double intensity;

	public:
		Light();
		Light(Point pos, double intensity_);
		Light(Point pos, Color color, double intensity);

		void print();
};

#endif