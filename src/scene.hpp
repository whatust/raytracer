#ifndef __SCENE_H__
#define __SCENE_H__

#include <iostream>
#include <vector>

#include "camera.hpp"
#include "object.hpp"
#include "sphere.hpp"
#include "plane.hpp"

class Scene{
	public:
		Scene();
		~Scene();

		void loadScene(file_name);
		void saveScene(file_name);

	private:
		Camera camera;
		std::vector<Light*> lights;
		std::vector<Object*> objects;
		double ambient_light_intensity;
}

#endif
