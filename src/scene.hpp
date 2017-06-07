#ifndef __SCENE_H__
#define __SCENE_H__

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "camera.hpp"
#include "object.hpp"
#include "sphere.hpp"
#include "plane.hpp"
#include "light.hpp"

class Scene{
	public:
		Scene();
		Scene(const double amb_light, const uint32_t level);
		~Scene();

		void loadScene(const std::string &filename);
		//void saveScene(const std::string &filename);

		Camera camera;
		std::vector<std::shared_ptr<Object>> objects;
		std::vector<std::shared_ptr<Material>> materials;
		std::vector<Light> lights;

		double getAmbientIntensity();
		uint32_t getLevel();

	private:	
		double ambient_light_intensity;
		uint32_t level;

		void parseLight(std::ifstream &input_stream);
		void parseObject(std::ifstream &input_stream);
		void parseCamera(std::ifstream &input_stream);
		void parseMaterial(std::ifstream &input_stream);
		void parseGeneral(std::ifstream &input_stream);

};

#endif
