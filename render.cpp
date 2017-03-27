#include "ray_tracer.h"
#include "parser.h"

int main(int argc, char *argv[]){

	arguments_t arguments = initParser(argc, argv);
	RayTracer rayTracer = RayTracer();

	rayTracer.render();
}