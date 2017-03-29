#include "material.hpp"

Material::Material() : color(Color()), reflectance(0.0), refractance(0.0){}

Material::Material(Color color) : color(color), reflectance(0.0), refractance(0.0){}

Material::Material(Color color, double refletance, double refractance) : color(color), reflectance(refletance), refractance(refractance){}