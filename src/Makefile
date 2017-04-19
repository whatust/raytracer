CXX=g++
CXXFLAGS=-Wall -std=c++11
LDFLAGS=
LDLIBS=-lm

SRC=color.cpp point.cpp vector.cpp
OBJ=color.o point.o vector.o window.o camera.o material.o object.o plane.o light.o parser.o value.o

build: render.cpp $(OBJ)
	$(CXX) -o render render.cpp $(OBJ) $(LDLIBS)

color.o: color.cpp color.hpp
	$(CXX) $(CXXFLAGS) -c color.cpp

point.o: point.cpp point.hpp
	$(CXX) $(CXXFLAGS) -c point.cpp

vector.o: vector.cpp vector.hpp
	$(CXX) $(CXXFLAGS) -c vector.cpp

window.o: window.cpp window.hpp
	$(CXX) $(CXXFLAGS) -c window.cpp

camera.o: camera.cpp camera.hpp
	$(CXX) $(CXXFLAGS) -c camera.cpp

material.o: material.cpp material.hpp
	$(CXX) $(CXXFLAGS) -c material.cpp

object.o: object.cpp object.hpp
	$(CXX) $(CXXFLAGS) -c object.cpp	

plane.o: plane.cpp plane.hpp
	$(CXX) $(CXXFLAGS) -c plane.cpp	

light.o: light.cpp light.hpp
	$(CXX) $(CXXFLAGS) -c light.cpp	

value.o: value.cpp value.hpp
	$(CXX) $(CXXFLAGS) -c value.cpp

parser.o: parser.cpp parser.hpp
	$(CXX) $(CXXFLAGS) -c parser.cpp

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp

test: $(OBJ) test.o value.o
	$(CXX) $(CXXFLAGS) -o test test.o $(OBJ) $(LDLIBS)

test_valgrind: test
	valgrind --leak-check=yes ./test

clean:
	rm *.o