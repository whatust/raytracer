#ifndef __RAY_TRACER_H__
#define __RAY_TRACER_H__

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "util.hpp"
#include "object.hpp"
#include "light.hpp"
#include "material.hpp"
#include "scene.hpp"
#include "camera.hpp"
#include "window.hpp"

#define MIN_DELTA 1.0e-10

class RayTracer{
public:

	RayTracer();
	RayTracer(const std::string &filename);
	~RayTracer();
	
	void renderScene();
	cv::Mat calcCenterVector(const cv::Mat &intersection, const cv::Mat &origin);
	cv::Mat calcAmbientComp(const cv::Mat &objColor, const double intensity);
	cv::Mat calcSpecVector(const cv::Mat &normal, const cv::Mat &v_ight);
	cv::Mat calcLightVector(const cv::Mat &intersection, const cv::Mat &p_light);
	cv::Mat calcSpecularComp(const cv::Mat &v_specular, const cv::Mat &v_camera, const Material &material, const Light &light);
	cv::Mat calcDifusalComp(const cv::Mat &normal, const cv::Mat &v_light, const Light &light);
	cv::Mat calcReflectionVector(const cv::Mat &ray, const cv::Mat &v_normal);
	cv::Mat calcCameraRay(double width, double height, int i, int j);
	cv::Mat castRay(const cv::Mat &ray, const cv::Mat &origin, uint8_t level);
	bool isShadow(const cv::Mat &v_light, const cv::Mat &intersection, const Light &light);
	double findClosestIntersection(const cv::Mat &ray, const cv::Mat &origin, std::shared_ptr<Object> *object);
	cv::Mat calcIntersectionCord(const cv::Mat &camera_pos, const cv::Mat &ray, double dist);
	cv::Mat TransfPoint(const cv::Mat &p, const cv::Mat &M, double w);

	Scene scene;
private:

	//cv::Mat castRay(const cv::Mat &ray, const cv::Mat &origin, uint8_t level);
	
	//cv::Mat calcRefractionVector(const cv::Mat &incidence, const cv::Mat &normal, Material &material);

};


#endif
