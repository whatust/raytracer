#ifndef __SCENE_H__
#define __SCENE_H__

#include <iostream>
#include <vector>

#include "sphere.hpp"
#include "plane.hpp"

class Scene{
	public:
		Scene();
		~Scene();

		void loadScene(file_name);
		void saveScene(file_name);

	private:
		double ambient_intensity;
		std::vector<Lights *> lights;
		std::vector<object *> object;
 }

#endif
