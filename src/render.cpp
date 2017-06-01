#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//#include "parser.hpp"


void render(uint32_t w_width, uint32_t w_height){

	std::string window_name = "main_window";
	cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

	cv::Mat image_scene(w_height, w_width, CV_8UC3);

	for(uint32_t r = 0; r < image_scene.rows; r++){

		cv::Point3_<uint8_t> *Mr = image_scene.ptr<cv::Point3_<uint8_t> >(r);

		for(uint32_t c = 0; c < image_scene.cols; c++){

			Mr[c].x = r%256;
			Mr[c].y = c%256;
			Mr[c].z = (c+r)%256;
		}
	}

	cv::imshow(window_name, image_scene);

	cv::waitKey(0);

	cv::destroyAllWindows();

	image_scene.release();
}

int main(int argc, char *argv[]){

	render(1920, 1080);

	//rayTracer.calcCenterVector(p, q);

	//rayTracer.render();
}
