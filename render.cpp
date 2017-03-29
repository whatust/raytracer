#include "ray_tracer.hpp"
#include "parser.hpp"

int main(int argc, char *argv[]){

	arguments_t *arguments = initParser(argc, argv);
	RayTracer rayTracer = RayTracer();

	rayTracer.render();
}