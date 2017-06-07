//Ray Tracer Camera 
//William Tustumi;
//13 Mar, 2016

#include <iostream>
#include <stdint.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "util.hpp"
#include "window.hpp"

#ifndef __CAMERA_H__
#define __CAMERA_H__

class Camera{

public:
	cv::Mat lookAt;
	cv::Mat pos;
	cv::Mat up;
	cv::Mat u, v, n;
	Window window;
	double near, far;
	uint32_t width, height;

	Camera();
	Camera(cv::Mat pos, cv::Mat lookAt, cv::Mat up);
	Camera(cv::Mat pos, cv::Mat lookAt, cv::Mat up, uint32_t width, uint32_t height);
	~Camera();

	void print();

private:
	void CalcWUV();

};

#endif