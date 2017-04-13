CXX=g++
CXXFLAGS=-Wall
LDFLAGS=
LDLIBS=-lm

SRC=color.cpp point.cpp vector.cpp
OBJ=color.o point.o vector.o window.o camera.o material.o object.o plane.o light.o

build: render.cpp $(OBJ)
	$(CXX) -o render render.cpp $(OBJ) $(LDLIBS)

color.o: color.cpp color.hpp
	$(CXX) $(CPPFLAGS) -c color.cpp

point.o: point.cpp point.hpp
	$(CXX) $(CPPFLAGS) -c point.cpp

vector.o: vector.cpp vector.hpp
	$(CXX) $(CPPFLAGS) -c vector.cpp

window.o: window.cpp window.hpp
	$(CXX) $(CPPFLAGS) -c window.cpp

camera.o: camera.cpp camera.hpp
	$(CXX) $(CPPFLAGS) -c camera.cpp

material.o: material.cpp material.hpp
	$(CXX) $(CPPFLAGS) -c material.cpp

object.o: object.cpp object.hpp
	$(CXX) $(CPPFLAGS) -c object.cpp	

plane.o: plane.cpp plane.hpp
	$(CXX) $(CPPFLAGS) -c plane.cpp	

light.o: light.cpp light.hpp
	$(CXX) $(CPPFLAGS) -c light.cpp	

test.o: test.cpp
	$(CXX) $(CPPFLAGS) -c test.cpp

test: $(OBJ) test.o
	$(CXX) -o test test.o $(OBJ) $(LDLIBS)

test_valgrind: test
	valgrind --leak-check=yes ./test

clean:
	rm *.o