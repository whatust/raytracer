//Ray Tracer Camera 
//William Tustumi;
//13 Mar, 2016

#ifndef __CAMERA_H__
#define __CAMERA_H__

class Camera{

public:
	Point pos;
	Vector up;
	Vector lookAt;
	Vector w,u,v;
	uint32_t width, height;

	Camera() {
		pos = Vector(0.0, 0.0, 100.0, 1.0);
		up = Vector(0.0, 1.0, 0.0, 1.0);
		lookAt = Vector(0.0, 0.0, 0.0, 1.0);
		width = 800;
		hright = 600;
		calculateWUV();
	}

	Camera(Vector pos_, Vector up_, Vector lookAt_, uint32_t width_, uint32_t height_){
		pos(pos_),up(up_),lootAt(lookAt_),width(width_),height(height_);
		CalcWUV();
	}
};

#endif