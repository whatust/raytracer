#ifndef __RAY_TRACER_H__
#define __RAY_TRACER_H__

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

	void loadObjects(std::string file_name);

	void loadLights(std::string file_name);

	void render();

private:
	void addObject(Object *obj);

	void addLight(Light *light);

	Point calcClosestIntersection(Vector &ray);

	Color castRay(const Vector &ray, const Point origin, int level);

	Object *findClosestIntersection(const Vector &ray, Object **obj);

	bool RayTracer::isShadow(const Vector v_light, const Point o_light);

	Vector calcCameraRay(const Camera &camera, double width, double height, int i, int j);

	Vector calcCenterVector(const Point &intersection, const Camera &camera);

	Vector calcLightVector(const Point &intersection, const Light &light);

	Vector calcSpecVector(const Vector &specular, const Vector &light);

	Color calcAmbientComp(const Color &objColor, const double intensity);

	Color calcDifusalComp(const Vector &normal, const Vector &v_light, const Light &light, const Material &material);

	Color calcSpecularComp(const Vector &specular, const Camera &camera, const Light &light, const Material &material);

	Vector calcReflectionVector(const Vector &normal, const Vector &incident);
	
	Vector calcRefractionVector(const Vector &incident, const Material &material);
};

#endif