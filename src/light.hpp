#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "util.hpp"

class Light{
	private:
		cv::Mat pos;
		cv::Mat color;
		double intensity;

	public:
		Light();
		Light(cv::Mat pos, double intensity_);
		Light(cv::Mat pos, cv::Mat color, double intensity);

		cv::Mat getPosition() const;
		cv::Mat getColor() const;

		void print();
};

#endif