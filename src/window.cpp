#include "window.hpp"

Window::Window() : \
		width(800), height(600){};

Window::Window(uint32_t w, uint32_t h) : \
		width(w), height(h){};

Window::~Window(){}

void Window::print(){
	std::cout << width << " " << height << std::endl;
}

