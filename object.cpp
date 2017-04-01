#include "object.hpp"

Object::Object(object_t t) : type(t), center(Point()){}

Object::Object(object_t t, Point p) : type(t), center(p){}
