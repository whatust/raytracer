#include "ray_tracer.h"

	void RayTracer::addObject(Object *obj){
		objects.push_back(obj);
		return;
	}

	void RayTracer::addLight(Light *light){
		lights.push_back(light);
		return;
	}

	Color RayTracer::castRayOnScreenPixel(uint32_t x, uint32_t y);

	bool RayTracer::isShadow(
							const Vector v_light
							const double distance){
		for(std::Vector<Object*>::iterator obj = objects.begin(); obj != objects.end(); ++obj){

		}

	}

	Color RayTracer::castRay(
							const Vector &ray,
							const Point origin,
							int level){

		int obj_idx=0;
		Color pixel_color;

		intersection = findClosestIntersection(ray, &obj_idx);

		if(obj_idx >= 0){
			
			Color specular_comp = Color();
			Color diffuse_comp = Color();

			Material material = objects[obj_idx].material;
			Vector v_normal = calcNormalVector(intersection, objects[obj_idx]);
			Vector v_camera = calcCenterVector(intersection, origin);
			
			for(std::Vector<Light*>::iterator light = lights.begin(); light != lights.end(); ++light){
				
				Vector v_light = calcLightVector(intersection, *light);
				Vector v_specular = calcSpecVector(v_normal, v_light);

				specular_comp += calc calcSpecularComp(v_specular, v_camera, *light, material)
				diffuse_comp += calcDifusalComp(v_normal, v_light, *light, material);
			}

			Color ambient_comp = getAmbientComp(material.obj, ambient_light_intensity);

			if(level){
				//Reflection
				Vector v_reflection = calcReflectionVector(ray, normal);
				Color reflection_comp = castRay(v_reflection, intersection, level-1);

				//Refraction
				Vector v_refraction = calcRefractionVector(ray, normal, material)
				Color refraction_comp = castRay(v_refraction, intersection, level-1);

				pixel_color = ambient_comp + specular_comp + diffuse_comp + refraction_comp + reflection_comp;
			}else{
				pixel_color = ambient_comp + specular_comp + diffuse_comp;
			}

		}else{
			pixel_color = Color();
		}

		return pixel_color;
	}

	double RayTracer::findClosestIntersection(const Vector &ray){

	}

	Vector RayTracer::calcCenterVector(
									const Point &intersection, 
									const Point &origin){
		return Vector(origin - intersection).normalize();
	}

	Vector RayTracer::calcLightVector(
									const Point &intersection,
									const Light &light){

		return Vector(light.pos - intersection).normalize();
	}

	Vector RayTracer::calcSpecVector(
									const Vector &normal,
									const Vector &light,){
		
		spec_vector = Vector();
		double sn = dot_product(light, normal);
		double nn = dot_product(normal, normal);

		spec_vector -= light;
		spec_vector += normal*(2*sn/nn);

		spec_vector.normalize()

		return spec_vector;
	}

	Color RayTracer::getAmbientComp(
						const Color objColor,
						double intensity){
		
		return objColor*intensity;
	}

	Color RayTracer::calcDifusalComp(
						const Vector &normal,
						const Vector &v_light,
						const Light &light,
						const Material &material){

		double nl = dot_product(normal, light_v);
		double nSize = sqrt(dot_product(normal, normal));
		double lSize = sqrt(dot_product(v_light, v_light));

		i_diffuse = material.diffuse_coeff * max(0.0, nc/(nSize*lSize));
		Color diffuse_comp = Color(i_diffuse * material.diffuse_color);

		return diffuse_comp;
	}

	Color RayTracer::calcSpecularComp(
						const Vector &specular,
						const Vector &camera,
						const Light &light,
						const Material &material){

		double sc = dot_product(specular, camera);
		double sSize = sqrt(dot_product(specular, specular));
		double cSize = sqrt(dot_product(camera, camera));

		double i_specular = material.specular_coeff * pow(max(0.0, sc/(sSize*cSize)), material.f);
		Color specular_comp = Color(i_specular * material.specular_color);

		return specular_comp;
	}

	Vector RayTracer::calcReflectionVector(
										const Vector &normal,
										const Vector &incident){


	}

	Vector RayTracer::calcRefractionVector(
										const Vector &incident,
										const Materia &material){
		
	}