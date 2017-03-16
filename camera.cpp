#include "camera.h"

void Camera::CalcWUV(){
	w = (lookAt - pos).normalize();
	u = up.cross(w).normalize();
	v = w.cross(u);

	return;
}