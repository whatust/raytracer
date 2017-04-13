#include <iostream>

#include "camera.hpp"
#include "color.hpp"
#include "point.hpp"
#include "vector.hpp"
#include "window.hpp"
#include "material.hpp"
#include "object.hpp"
#include "plane.hpp"
#include "light.hpp"

void testCamera();
void testColor();
void testPoint();
void testVector();
void testWindow();
void testMaterial();
void testPlane();
void testLight();

int main(){

	testCamera();
	testColor();
	testPoint();
	testVector();
	testWindow();
	testMaterial();
	testPlane();
	testLight();

	return 0;
}

void testColor(){
	Color a = Color();
	Color b = Color(1,2,3);
	Color c;

	std::cout << "Tesiting Color" << std::endl;

	a.print();
	b.print();
	
	a = b;
	std::cout << "a=b" << std::endl;
	a.print();
	b.print();
	
	c = a+b;
	std::cout << "c=a+b" << std::endl;
	a.print();
	b.print();
	c.print();
	
	c = a-b;
	std::cout << "c=a-b" << std::endl;
	a.print();
	b.print();
	c.print();
	
	c = a*4;
	std::cout << "c=a*4" << std::endl;
	a.print();
	c.print();
	
	c = a/2;
	std::cout << "c=a/2" << std::endl;
	a.print();
	c.print();
	
	c += a;
	std::cout << "c+=a" << std::endl;
	a.print();
	c.print();
	
	c -= a;
	std::cout << "c-=a" << std::endl;
	a.print();
	c.print();

	c *= 4;
	std::cout << "c*=4" << std::endl;
	c.print();

	std::cout << "c/=2" << std::endl;
	c /= 2;
	c.print();

	Color d,e,f,g,h,i,j;
	d = Color();
	e = Color();
	f = Color();
	g = Color();
	h = Color();
	i = Color();
	j = Color();

	a.print();
	b.print();
	c.print();
}

void testPoint(){
	Point a = Point();
	Point b = Point(1,2,3);
	Point c;

	std::cout << "Tesiting Point" << std::endl;

	a.print();
	b.print();
	
	a = b;
	std::cout << "a=b" << std::endl;
	a.print();
	b.print();
	
	c = a+b;
	std::cout << "c=a+b" << std::endl;
	a.print();
	b.print();
	c.print();
	
	c = a-b;
	std::cout << "c=a-b" << std::endl;
	a.print();
	b.print();
	c.print();
	
	c += a;
	std::cout << "c+=a" << std::endl;
	a.print();
	c.print();
	
	c -= a;
	std::cout << "c-=a" << std::endl;
	a.print();
	c.print();

	Point d,e,f,g,h,i,j;
	d = Point();
	e = Point();
	f = Point();
	g = Point();
	h = Point();
	i = Point();
	j = Point();

	a.print();
	b.print();
	c.print();
}

void testVector(){
	Vector a = Vector();
	Vector b = Vector(1,2,3);
	Vector c;

	std::cout << "Tesiting Vector" << std::endl;

	a.print();
	b.print();
	
	a = b;
	std::cout << "a=b" << std::endl;
	a.print();
	b.print();
	
	c = a+b;
	std::cout << "c=a+b" << std::endl;
	a.print();
	b.print();
	c.print();
	
	c = a-b;
	std::cout << "c=a-b" << std::endl;
	a.print();
	b.print();
	c.print();
	
	c = a*4;
	std::cout << "c=a*4" << std::endl;
	a.print();
	c.print();
	
	c = a/2;
	std::cout << "c=a/2" << std::endl;
	a.print();
	c.print();
	
	c += a;
	std::cout << "c+=a" << std::endl;
	a.print();
	c.print();
	
	c -= a;
	std::cout << "c-=a" << std::endl;
	a.print();
	c.print();

	c *= 4;
	std::cout << "c*=4" << std::endl;
	c.print();

	std::cout << "c/=2" << std::endl;
	c /= 2;
	c.print();

	std::cout << "Vector(Point(1,2,3))" << std::endl;
	c = Vector(Point(1,2,3));
	c.print();

	std::cout << "a.dot_product(b)" << std::endl;
	std::cout << a.dot_product(b) << std::endl;

	a.print();
	b.print();

	std::cout << "c=a.cross_product(b)" << std::endl;
	c = a.cross_product(b);

	std::cout << "a.size()" << std::endl;
	std::cout << a.size() << std::endl;

	std::cout << "a.normalize()" << std::endl;
	a.normalize();
	a.print();

	std::cout << "a.size()" << std::endl;
	std::cout << a.size() << std::endl;

	a.print();
	b.print();
	c.print();

	Vector d,e,f,g,h,i,j;
	d = Vector();
	e = Vector();
	f = Vector();
	g = Vector();
	h = Vector();
	i = Vector();
	j = Vector();

	a.print();
	b.print();
	c.print();
}

void testWindow(){

	std::cout << "Tesiting Window" << std::endl;

	Window w1 = Window();
	w1.print();

	Window w2 = Window(200, 300);
	w2.print();
}

void testCamera(){

	std::cout << "Testing Camera" << std::endl;

	Camera c1 = Camera();
	c1.print();

	Camera c2 = Camera(Point(10.0,10.0,10.0), Point(1.0,1.0,1.0), Vector(0.0,0.0,1.0,1.0));
	c2.print();

	Camera c3 = Camera(Point(10.0,10.0,10.0), Point(1.0,1.0,1.0), Vector(0.0,0.0,1.0,1.0), 450.0, 1200.0);
	c3.print();
}

void testMaterial(){

	std::cout << "Testing Material" << std::endl;

	Material m1 = Material();
	m1.print();

	Material m2 = Material(Color(255.0, 255.0, 255.0));
	m2.print();

	Material m3 = Material(Color(255.0, 255.0, 255.0), 0.4, 0.3);
	m3.print();

	Material m4 = Material(Color(255.0, 255.0, 255.0), 0.4, 0.3, 0.2, 0.3, 24.0);
	m4.print();
}

void testPlane(){
	std::cout << "Testing Plane" << std::endl;

	Plane p1 = Plane();
	p1.print();

	Plane p2 = Plane(Point(3.0, 5.0, 7.0));
	p2.print();

	Plane p3 = Plane(Point(3.0, 1.0, 25.0), Vector(1.0, 2.3, 42.0));
	p3.print();
}

void testLight(){
	std::cout << "Testing Light" << std::endl;

	Light l1 = Light();
	l1.print();

	Light l2 = Light(Point(3.0, 5.0, 7.0), 10.0);
	l2.print();

	Light l3 = Light(Point(3.0, 1.0, 25.0), Color(255, 255, 255), 20.0);
	l3.print();
}

