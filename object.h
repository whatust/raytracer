#ifdef __OBJECT_H__
#define __OBJECT_H__

typedef enum object_t{SPHERE, PLANE};

class object{
	
private:
	Point center;
	object_t type;

public:
	Point intersect(Vector const &v, Point const &p);

};