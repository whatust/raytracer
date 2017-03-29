#include "light.hpp"

Light::Light(Point pos, double intensity) : pos(pos), intensity(intensity),	color(Color()){}

Light::Light(Point pos, Color color, double intensity) : pos(pos), color(color), intensity(intensity){}