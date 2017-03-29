#ifndef __OBJECT_H__
#define __OBJECT_H__

typedef enum object_{SPHERE, PLANE} object_t;

class Object{
	
private:
	Point center;
	object_t type;

public:
	Point intersect(Vector const &v, Point const &p);

};

#endif