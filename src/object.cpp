#include "object.hpp"

#define degree(rad) rad*M_PI/180

Object::Object(object_t t, std::shared_ptr<Material> materila_ptr) : type(t), M(cv::Mat::eye(4, 4, CV_64F)), Minv(cv::Mat::eye(4, 4, CV_64F)), material(materila_ptr){}

Object::Object(object_t t, cv::Mat M, std::shared_ptr<Material> materila_ptr) : type(t), M(M), Minv(M.inv()), material(materila_ptr){}

Object::Object(object_t t, double pos[3], double rot[3], double scl[3], std::shared_ptr<Material> materila_ptr) : type(t), material(materila_ptr){

    cv::Mat M_scl = (cv::Mat_<double>(4,4) << scl[0],      0,      0, 0,
							        			   0, scl[1],      0, 0,
							        			   0,      0, scl[2], 0,
							        			   0,      0,      0, 1);

    cv::Mat M_rotx = (cv::Mat_<double>(4,4) << 1,                   0,                    0, 0,
							    			   0, cos(degree(rot[0])), -sin(degree(rot[0])), 0,
							    			   0, sin(degree(rot[0])),  cos(degree(rot[0])), 0,
							    			   0,                   0,                    0, 1);
    
    cv::Mat M_roty = (cv::Mat_<double>(4,4) <<  cos(degree(rot[1])),  0,  sin(degree(rot[1])), 0,
											                      0,  1,                    0, 0,
							    			   -sin(degree(rot[1])),  0,  cos(degree(rot[1])), 0,
							    			                      0,  0,                    0, 1);

    cv::Mat M_rotz = (cv::Mat_<double>(4,4) << cos(degree(rot[2])), -sin(degree(rot[2])), 0, 0,
							    			   sin(degree(rot[2])),  cos(degree(rot[2])), 0, 0,
							                   					 0,                    0, 1, 0,
							                      				 0,                    0, 0, 1);
    cv::Mat M_trl = (cv::Mat_<double>(4,4) << 1, 0, 0, pos[0],
							   				  0, 1, 0, pos[1],
							   				  0, 0, 1, pos[2],
							   				  0, 0, 0, 1);

	M = (M_trl * (M_rotz * (M_roty * M_rotx)) * M_scl);

	Minv = M.inv();
}

Object::~Object(){
	M.release();
	Minv.release();
}

std::shared_ptr<Material> Object::getMaterial(){
	return material;
}

cv::Mat Object::getM(){
	return M;
}

cv::Mat Object::getMinv(){
	return Minv;
}

void Object::print(){
	std::cout << "M" << std:: endl;
	util::printMat<double>(M);
	std::cout << "M" << std:: endl;
	util::printMat<double>(Minv);
	std::cout << type << std::endl;
	type == PLANE ? std::cout << "PLANE" << std::endl : std::cout << "SPHERE" << std::endl;
	material->print();
}