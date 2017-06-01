#ifndef __UTIL_H__
#define __UTIL_H__

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace util{

	template<typename T>
	void printMat(cv::Mat m){
		std::cout << "size: " << m.total();
		for(int i=0; i < m.total()-1; i++){
			if(i%4 == 0)
				std::cout << std::endl;
	    	std::cout << m.at<T>(i) << " ";
	    }
	    std::cout << m.at<T>(m.total()-1) << std::endl;

	}
}

#endif
