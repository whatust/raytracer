#include "camera.hpp"

Camera::Camera() {
	pos = Point(1.0, 1.0, 1.0);
	lookAt = Point(0.0, 0.0, 0.0);
	up = Vector(0.0, 1.0, 0.0, 1.0);
	width = 800;
	height = 600;
	CalcWUV();
}

Camera::Camera(Point pos, Point lookAt, Vector up):
	pos(pos), lookAt(lookAt), up(up), width(width), height(height){
	CalcWUV();
}

Camera::Camera(Point pos, Point lookAt, Vector up, uint32_t width, uint32_t height) : \
	pos(pos), lookAt(lookAt), up(up), width(width), height(height){
	CalcWUV();
}

void Camera::CalcWUV(){
	n = Vector(lookAt - pos).normalize();
	u = cross_product(up, n).normalize();
	v = cross_product(n, u);

	return;
}