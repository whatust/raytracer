#ifndef __RAY_TRACER_H__
#define __RAY_TRACER_H__

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include "vector.hpp"
#include "camera.hpp"
#include "light.hpp"
#include "object.hpp"
#include "material.hpp"

class RayTracer{
public:
	Camera camera;
	std::vector<Light*> lights;
	std::vector<Object*> objects;

	double ambient_light_intensity;

	void loadObjects(std::string file_name);

	void loadLights(std::string file_name);

	void render();

private:
	void addObject(Object *obj);

	void addLight(Light *light);

	Point calcClosestIntersection(Vector &ray);

	Color castRay(Vector &ray, Point origin, int level);

	Point findClosestIntersection(Vector &ray, Object **object);

	bool isShadow(Vector &v_light, Point &intersection);

	Vector calcCameraRay(Camera &camera, double width, double height, int i, int j);

	Vector calcCenterVector(Point &intersection, Point &origin);

	Vector calcLightVector(Point &intersection, Light &light);

	Vector calcSpecVector(Vector &normal, Vector &light);

	Color calcAmbientComp(Color objColor, double intensity);

	Color calcDifusalComp(Vector &normal, Vector &v_light, Light &light, Material &material);

	Color calcSpecularComp(Vector &specular, Vector &camera, Light &light, Material &material);

	Vector calcReflectionVector(Vector &normal, Vector &incidence);
	
	Vector calcRefractionVector(Vector &incidence, Vector &normal, Material &material);
};

#endif