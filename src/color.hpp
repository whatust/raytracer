#ifndef __COLOR_H__
#define __COLOR_H__

#include <algorithm>
#include <iostream>

class Color{

	public:
		Color();
		Color(const Color& other);
		Color(int red, int green, int blue);
		~Color();

		Color& operator=(Color other);
		Color& operator+=(const Color &rhs);
		Color& operator-=(const Color &rhs);
		Color& operator*=(const double &rhs);
		Color& operator/=(const double &rhs);
		Color operator+(const Color &rhs);
		Color operator-(const Color &rhs);
		Color operator*(const double &rhs);
		Color operator/(const double &rhs);

		void print();
		void swap(Color& first, Color& second);

	private:
		double red, green, blue;
};

#endif