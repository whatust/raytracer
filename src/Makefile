CXX=g++
CXXFLAGS=-std=c++11 -O3
LDFLAGS=
LDLIBS=-lm
OPENCVFLAGS=`pkg-config --cflags --libs opencv`

SRC=parser.cpp value.cpp scene.cpp sphere.cpp plane.cpp object.cpp material.cpp light.cpp camera.cpp window.cpp util.cpp
OBJ=parser.o value.o scene.o sphere.o plane.o object.o material.o light.o camera.o window.o util.o

camera.o: camera.cpp camera.hpp
	$(CXX) $(CXXFLAGS) -c camera.cpp

light.o: light.cpp light.hpp
	$(CXX) $(CXXFLAGS) -c light.cpp

material.o: material.cpp material.hpp
	$(CXX) $(CXXFLAGS) -c material.cpp

object.o: object.cpp object.hpp
	$(CXX) $(CXXFLAGS) -c object.cpp	
	
parser.o: parser.cpp parser.hpp
	$(CXX) $(CXXFLAGS) -c parser.cpp

plane.o: plane.cpp plane.hpp
	$(CXX) $(CXXFLAGS) -c plane.cpp	

scene.o: scene.cpp scene.hpp
	$(CXX) $(CXXFLAGS) -c scene.cpp

sphere.o: sphere.cpp sphere.hpp
	$(CXX) $(CXXFLAGS) -c sphere.cpp

util.o:util.cpp util.hpp
	$(CXX) $(CXXFLAGS) -c util.cpp

value.o: value.cpp value.hpp
	$(CXX) $(CXXFLAGS) -c value.cpp

window.o: window.cpp window.hpp
	$(CXX) $(CXXFLAGS) -c window.cpp

raytracer: raytracer.cpp raytracer.hpp $(OBJ)
	$(CXX) $(CXXFLAGS) raytracer.cpp $(OBJ) $(OPENCVFLAGS) $(LDLIBS) -o raytracer

render: render.cpp
	$(CXX) $(CXXFLAGS) render.cpp $(OBJ) $(OPENCVFLAGS) $(LDLIBS) -o render


clean:
	rm -rf *.o
