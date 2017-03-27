#ifndef __WINDOW_H__
#define __WINDOW_H__

class Window{
public:
	int width;
	int height;

	Window(int w, int h){
		width = w;
		height = h;
	}

	Window(){
		width = 800;
		height = 600;
	}

};

#endif