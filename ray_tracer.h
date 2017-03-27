#ifndef __RAY_TRACER_H__
#define __RAY_TRACER_H__

#include "vector.h"
#include "camera.h"
#include "light.h"

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

	Color castRayOnScreenPixel(uint32_t x, uint32_t y);

	Vector calcCenterVector(const Point &intersection, const Camera &camera);

	Vector calcLightVector(const Point &intersection, const Light &light);

	Vector calcSpecVector(const Vector &specular, const Vector &light);

	Color calcAmbientComp(const Color &objColor, const double intensity);

	Color calcDifusalComp(const Vector &normal, const Vector &v_light, const Light &light, const Material &material);

	Color calcSpecularComp(const Vector &specular, const &camera, const Light &light, const Material &material);

	Color calcReflectiveLight(const Point intersection);

	Color calcRefractiveLight(const Point intersection);
};

#endif