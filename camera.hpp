//Ray Tracer Camera 
//William Tustumi;
//13 Mar, 2016

#include "point.hpp"
#include "vector.hpp"
#include <stdint.h>

#ifndef __CAMERA_H__
#define __CAMERA_H__

class Camera{

public:
	Point lookAt;
	Point pos;
	Vector up;
	Vector u, v, w;
	uint32_t width, height;

	Camera();
	Camera(Point pos, Point lookAt, Vector up);
	Camera(Point pos, Point lookAt, Vector up, uint32_t width, uint32_t height);

private:
	void CalcWUV();

};

#endif