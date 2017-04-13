#include "camera.hpp"

Camera::Camera() : 
	pos(Point(1.0, 1.0, 1.0)), lookAt(Point(0.0, 0.0, 0.0)), up(Vector(0.0, 0.0, 1.0, 1.0)), width(800), height(600){
	CalcWUV();
}

Camera::Camera(Point pos, Point lookAt, Vector up):
	pos(pos), lookAt(lookAt), up(up), width(800), height(600){
	CalcWUV();
}

Camera::Camera(Point pos, Point lookAt, Vector up, uint32_t width, uint32_t height) : \
	pos(pos), lookAt(lookAt), up(up), width(width), height(height){
	CalcWUV();
}

void Camera::print(){
	std::cout << "pos ";
	pos.print();

	std::cout << "lookAt ";
	lookAt.print();

	std::cout << "up ";
	up.print();

	std::cout << "n ";
	n.print();

	std::cout << "u ";
	u.print();

	std::cout << "v ";
	v.print();

	std::cout << width << " " << height << std::endl;
}

void Camera::CalcWUV(){
	n = Vector(pos - lookAt).normalize();
	u = up.cross_product(n).normalize();
	v = n.cross_product(u);
}

