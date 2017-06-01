#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <iostream>
#include <stdint.h>

class Window{
	public:
		Window(uint32_t w, uint32_t h);
		Window();
		~Window();

		uint32_t getWidth();
		uint32_t getHeight();

		void print();
	private:
		uint32_t width;
		uint32_t height;
};

#endif