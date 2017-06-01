#include "camera.hpp"

Camera::Camera() : near(1.0), far(25){
	
	lookAt = (cv::Mat_<double>(3,1) << 0,0,0);
	up = (cv::Mat_<double>(3,1) << 0,0,1);
	pos = (cv::Mat_<double>(3,1) << 10, 10, 10);

	std::cout << "camera" << std::endl;
	util::printMat<double>(pos);
	util::printMat<double>(up);
	util::printMat<double>(lookAt);

	CalcWUV();

	util::printMat<double>(n);
	util::printMat<double>(u);
	util::printMat<double>(v);

}

Camera::Camera(cv::Mat pos, cv::Mat lookAt, cv::Mat up):
	pos(pos), lookAt(lookAt), up(up), near(1.0), far(25){
	CalcWUV();
}

Camera::Camera(cv::Mat pos, cv::Mat lookAt, cv::Mat up, uint32_t width, uint32_t height) : \
	pos(pos), lookAt(lookAt), up(up), near(1.0), far(25){
	window = Window(width, height);
	CalcWUV();
}

void Camera::print(){
	std::cout << "pos ";
	util::printMat<double>(pos);

	std::cout << "lookAt ";
	util::printMat<double>(lookAt);

	std::cout << "up ";
	util::printMat<double>(up);

	std::cout << "n ";
	util::printMat<double>(n);

	std::cout << "u ";
	util::printMat<double>(u);

	std::cout << "v ";
	util::printMat<double>(v);

	std::cout << width << " " << height << std::endl;
}

void Camera::CalcWUV(){
	cv::normalize((pos - lookAt), n);
	cv::normalize(up.cross(n), u);
	cv::normalize(n.cross(u), v);
}

