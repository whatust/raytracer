#include "raytracer.hpp"

RayTracer::RayTracer(){
}

RayTracer::RayTracer(const std::string &filename){
    scene.loadScene(filename);
}

RayTracer::~RayTracer(){}

cv::Mat RayTracer::TransfPoint(
                            const cv::Mat &p,
                            const cv::Mat &M,
                            double w){

    cv::Mat aux = p;
    aux.push_back(w);
    cv::Mat p_inv = M * aux;
    p_inv.pop_back();

    return p_inv;
}

cv::Mat RayTracer::calcCenterVector(
                                const cv::Mat &origin,
                                const cv::Mat &intersection){ 

    cv::Mat vect;
    cv::normalize((origin - intersection), vect);

    return vect;}

cv::Mat RayTracer::calcLightVector(
                                const cv::Mat &intersection,
                                const cv::Mat &p_light){

    cv::Mat vect;
    cv::normalize((p_light - intersection), vect);

    return vect;
}

cv::Mat RayTracer::calcSpecVector(
                                const cv::Mat &normal,
                                const cv::Mat &v_light){

    cv::Mat spec_vector = (cv::Mat_<double>(3,1) << 0, 0, 0);

    double sn = v_light.dot(normal);
    double nn = normal.dot(normal);

    spec_vector -= v_light;
    spec_vector += normal * (2 * sn / nn);

    cv::normalize(spec_vector, spec_vector);

    return spec_vector;
}

cv::Mat RayTracer::calcAmbientComp(
                                const cv::Mat &objColor,
                                double intensity){

    /*std::cout << "func ambient_comp ";
    util::printMat<double>(intensity * objColor);
    std::cout << std::endl;*/

    return intensity * objColor;
}

cv::Mat RayTracer::calcDifusalComp(
                                const cv::Mat &normal,
                                const cv::Mat &v_light,
                                const Light &light){

    double nl = normal.dot(v_light);
    double nSize = sqrt(normal.dot(normal));
    double lSize = sqrt(v_light.dot(v_light));

    double i_diffuse = std::max(0.0, nl/(nSize*lSize));
    cv::Mat diffuse_comp = i_diffuse * light.getColor();

    /*std::cout << "func diffuse_comp ";
    util::printMat<double>(diffuse_comp);
    std::cout << std::endl;*/

    return diffuse_comp;
}

cv::Mat RayTracer::calcSpecularComp(
                                const cv::Mat &v_specular,
                                const cv::Mat &v_camera,
                                const Material &material,
                                const Light &light){

    double sc = v_specular.dot(v_camera);
    double sSize = sqrt(v_specular.dot(v_specular));
    double cSize = sqrt(v_camera.dot(v_camera));

    double i_specular = std::pow(std::max(0.0, sc/(sSize*cSize)), material.f);
    cv::Mat specular_comp = i_specular * light.getColor();//.getColor();

    return specular_comp;
}

cv::Mat RayTracer::calcCameraRay(
                                double width,
                                double height, 
                                int i, int j){

    double x = -1.0 * scene.camera.near * scene.camera.n.at<double>(0) +
    width * (2.0 * i / scene.camera.window.getWidth() - 1.0) * scene.camera.u.at<double>(0) +
    height * (2.0 * j / scene.camera.window.getHeight() - 1.0) * scene.camera.v.at<double>(0);

    double y = -1.0 * scene.camera.near * scene.camera.n.at<double>(1) +
    width * (2.0 * i / scene.camera.window.getWidth() - 1.0) * scene.camera.u.at<double>(1) +
    height * (2.0 * j / scene.camera.window.getHeight() - 1.0) * scene.camera.v.at<double>(1);

    double z = -1.0 * scene.camera.near * scene.camera.n.at<double>(2) +
    width * (2.0 * i / scene.camera.window.getWidth() - 1.0) * scene.camera.u.at<double>(2) +
    height * (2.0 * j / scene.camera.window.getHeight() - 1.0) * scene.camera.v.at<double>(2);

    cv::Mat ray = (cv::Mat_<double>(3,1) << x, y, z);

    return ray;
}

bool RayTracer::isShadow(
                        const cv::Mat &v_light,
                        const cv::Mat &intersection,
                        const Light &light){

    cv::Mat new_intersection = intersection + v_light * MIN_DELTA;
    double light_dist = sqrt((light.getPosition() - new_intersection).dot(light.getPosition() - new_intersection));

    for(std::vector<std::shared_ptr<Object>>::iterator obj = scene.objects.begin(); obj != scene.objects.end(); ++obj){
        
        double obj_dist = (obj->get())->intersect(new_intersection, v_light);

        if(obj_dist > 0 && obj_dist < light_dist)
            return true;
    }
    return false;
}


double RayTracer::findClosestIntersection(
                                        const cv::Mat &ray,
                                        const cv::Mat &origin,
                                        std::shared_ptr<Object> *object){

    double min_dist = -1.0;
    std::shared_ptr<Object> min_obj = NULL;

    for(std::vector<std::shared_ptr<Object>>::iterator obj = scene.objects.begin(); obj != scene.objects.end(); ++obj){

        cv::Mat Minv = obj->get()->getMinv();
        cv::Mat ray_inv = TransfPoint(ray, Minv, 0.0);
        cv::Mat pos_inv = TransfPoint(origin, Minv, 1.0);

        double dist = (obj->get())->intersect(pos_inv, ray_inv);

        //std::cout << "dist " << dist << std::endl;

        if((min_dist == -1 || dist < min_dist) && dist > 0){
            min_dist = dist;
            min_obj = *obj;
        }
    }
    *object = min_obj;

    //std::cout << min_dist << std::endl;

    return min_dist;
}

cv::Mat RayTracer::calcReflectionVector(
                                    const cv::Mat &incidence,
                                    const cv::Mat &normal){

    cv::Mat v_reflect = (cv::Mat_<double>(3,1) << 0, 0, 0);

    double sn = incidence.dot(normal);
    double nn = normal.dot(normal);

    v_reflect -= incidence;
    v_reflect += normal * (2 * sn / nn);

    cv::normalize(v_reflect, v_reflect);

    return v_reflect;
}

/*cv::Mat RayTracer::calcRefractionVector(const cv::Mat &incidence, const cv::Mat &normal, Material &material){

}*/

cv::Mat RayTracer::calcIntersectionCord(const cv::Mat &origin, const cv::Mat &ray, double dist){

    return origin + dist * ray;
}

cv::Mat RayTracer::castRay(
                        const cv::Mat &ray,
                        const cv::Mat &origin,
                        uint8_t level){

    std::shared_ptr<Object> object;
    cv::Mat intersection;
    cv::Mat pixel_color;

    double dist = findClosestIntersection(ray, origin, &object);

    //std::cout << object << std::endl;

    if(object != NULL){
        
        cv::Mat Minv = object->getMinv();
        cv::Mat M = object->getM();
        Material material = *(object->getMaterial());

        cv::Mat origin_inv = TransfPoint(origin, Minv, 1.0);
        cv::Mat ray_inv = TransfPoint(ray, Minv, 0.0);

        intersection = calcIntersectionCord(origin_inv, ray_inv, dist);

        cv::Mat v_normal = object->getNormal(intersection);
        cv::Mat v_origin = calcCenterVector(origin_inv, intersection);
        
        cv::Mat specular_comp = (cv::Mat_<double>(3,1) << 0, 0, 0);
        cv::Mat diffuse_comp = (cv::Mat_<double>(3,1) << 0, 0, 0);

        for(std::vector<Light>::iterator light = scene.lights.begin(); light != scene.lights.end(); ++light){
            
            cv::Mat light_inv = TransfPoint(light->getPosition(), Minv, 1.0);
            cv::Mat v_light = calcLightVector(intersection, light_inv);

            if(! isShadow(v_light, intersection, *light)){
                
                cv::Mat v_specular = calcSpecVector(v_normal, v_light);
                specular_comp += calcSpecularComp(v_specular, v_origin, material, *light);
                diffuse_comp += calcDifusalComp(v_normal, v_light, *light);
            }
        }

        specular_comp = specular_comp * (material.specular_coeff/scene.lights.size());
        diffuse_comp = diffuse_comp * (material.diffuse_coeff/scene.lights.size());

        cv::Mat ambient_comp = calcAmbientComp(material.color, scene.getAmbientIntensity());

        if(level){
            //Reflection
            cv::Mat v_reflection = calcReflectionVector(-ray_inv, v_normal);
            cv::Mat new_origin = TransfPoint(calcIntersectionCord(intersection, v_reflection, MIN_DELTA), M, 1.0);
            cv::Mat reflection_comp = castRay(TransfPoint(v_reflection, M, 0.0), new_origin, level-1) * material.reflectance;

            //Refraction
            //cv::Mat v_refraction = calcRefractionVector(ray, v_normal, material);
            //cv::Mat refraction_comp = castRay(v_refraction, intersection, level-1) * material.refractance;

            pixel_color = ambient_comp + specular_comp + diffuse_comp + reflection_comp;// + refraction_comp;
        }else{
            pixel_color = ambient_comp + specular_comp + diffuse_comp;
        }

        /*
        std::cout << "specular_comp: ";
        util::printMat<double>(specular_comp);
        std::cout << std::endl;

        std::cout << "diffuse_comp: ";
        util::printMat<double>(diffuse_comp);
        std::cout << std::endl;

        std::cout << "ambient_comp: ";
        util::printMat<double>(ambient_comp);
        std::cout << std::endl;*/

    }else{
		pixel_color = cv::Mat::zeros(3, 1, CV_64F);
    }

    return pixel_color;
}

void RayTracer::renderScene(){

    std::string window_name = "main_window";
    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

    cv::Mat image_scene(scene.camera.window.getHeight(), scene.camera.window.getWidth(), CV_8UC3);
    double aspect = 1.0;
    double height = scene.camera.near*tan(M_PI/180.0 * 45.0/2.0);
    double width = height*aspect;

    std::cout << "nObject" << scene.objects.size() << std::endl;
    for(std::vector<std::shared_ptr<Object>>::iterator obj = scene.objects.begin(); obj != scene.objects.end(); ++obj){
        obj->get()->print();
    }

    for(uint32_t r = 0; r < image_scene.rows; r++){

        cv::Point3_<uint8_t> *Mr = image_scene.ptr<cv::Point3_<uint8_t> >(image_scene.rows-r);

        for(uint32_t c = 0; c < image_scene.cols; c++){

            cv::Mat ray = calcCameraRay(width, height, c, r);
            cv::Mat color = castRay(ray, scene.camera.pos, 1);

            const double *data = color.ptr<double>(0);
            Mr[c] = cv::Point3d(data[0], data[1], data[2]);
        }
    }

    cv::imshow(window_name, image_scene);

    cv::waitKey(0);

    cv::destroyAllWindows();

    image_scene.release();
}

int main(){

    RayTracer rayTracer;

    std::cout << "Loading Scene" << std::endl;
    rayTracer = RayTracer("../scenes/chess.scn");

    util::printMat<double>(rayTracer.scene.camera.pos);
    util::printMat<double>(rayTracer.scene.camera.up);
    util::printMat<double>(rayTracer.scene.camera.lookAt);
    util::printMat<double>(rayTracer.scene.camera.n);
    util::printMat<double>(rayTracer.scene.camera.u);
    util::printMat<double>(rayTracer.scene.camera.v);


    std::cout << "Testing calcCameraRay" <<std::endl;
    
    double aspect = 16/9;
    double height = rayTracer.scene.camera.near*tan(M_PI/180.0 * 45.0/2.0);
    double width = height*aspect;

    int i = 400;
    int j = 300;

    std::cout << "width: " << width << "  height: " << height << std::endl;
    std::cout << "i: " << i << "  j: " << j << std::endl; 

    cv::Mat camera_ray = rayTracer.calcCameraRay(width, height, i , j);

    std::cout << "camera_ray";
    util::printMat<double>(camera_ray);
    std::cout << std::endl;

    std::cout << "Testing calcCenterVector" <<std::endl;

    cv::Mat p = (cv::Mat_<double>(3,1) << 0, 0, 0);
    cv::Mat q = (cv::Mat_<double>(3,1) << 1, 3, 2);

    std::cout << "p";
    util::printMat<double>(p);
    std::cout << "q";
    util::printMat<double>(q);

    cv::Mat r = rayTracer.calcCenterVector(p, q);

    std::cout << "r";
    util::printMat<double>(r);
    std::cout << std::endl;
    

    std::cout << "Testing calcAmbientComp" << std::endl;

    cv::Mat amb_c = (cv::Mat_<double>(3,1) << 255, 201, 125);
    double intensity_amb = 0.3;

    std::cout << "intensity" << intensity_amb << std::endl;
    std::cout << "amb_c";
    util::printMat<double>(amb_c);

    cv::Mat amb_comp = rayTracer.calcAmbientComp(amb_c, intensity_amb);

    std::cout << "amb_comp";
    util::printMat<double>(amb_comp);
    std::cout << std::endl;


    std::cout << "Testing calcLightVector" << std::endl;

    cv::Mat p_light = (cv::Mat_<double>(3,1) << 1, 1, 10);
    cv::Mat intersection = (cv::Mat_<double>(3,1) << 0, 0, 0);

    std::cout << "p_light";
    util::printMat<double>(p_light);
    std::cout << "intersection";
    util::printMat<double>(intersection);

    cv::Mat v_light = rayTracer.calcLightVector(intersection, p_light);

    std::cout << "v_light";
    util::printMat<double>(v_light);
    std::cout << std::endl;


    std::cout << "Testing calcSpecVector" << std::endl;

    cv::Mat normal = (cv::Mat_<double>(3,1) << 0, 0, 1);

    std::cout << "v_light";
    util::printMat<double>(v_light);
    std::cout << "normal";
    util::printMat<double>(normal);

    cv::Mat spec_vector = rayTracer.calcSpecVector(normal, v_light);

    std::cout << "spec_vector";
    util::printMat<double>(spec_vector);
    std::cout << std::endl;

    std::cout << "Testing calcSpecularComp" << std::endl;

    cv::Mat v_camera = (cv::Mat_<double>(3,1) << -.705346, -0.705346, -0.705346);

    std::cout << "v_camera";
    util::printMat<double>(v_camera);
    std::cout << "spec_vector";
    util::printMat<double>(spec_vector);

    Material material = Material("test_material", (cv::Mat_<double>(3,1) << 255, 150, 200), 1, 1, 0.5, 0.2, 10);
    Light light = Light();

    cv::Mat spec_comp = rayTracer.calcSpecularComp(spec_vector, v_camera, material, light);

    std::cout << "spec_comp";
    util::printMat<double>(spec_comp);
    std::cout << std::endl;

    std::cout << "Testing calcDifusalComp" << std::endl;

    std::cout << "v_light";
    util::printMat<double>(v_light);
    std::cout << "normal";
    util::printMat<double>(normal);

    cv::Mat diffuse_comp = rayTracer.calcDifusalComp(normal, v_light, light);

    std::cout << "diffuse_comp";
    util::printMat<double>(diffuse_comp);
    std::cout << std::endl;

    std::cout << "Testing Casting Ray" << std::endl;  

    cv::Mat origin = (cv::Mat_<double>(3,1) << 1, 1, 1);

    std::cout << "camera_ray";
    util::printMat<double>(camera_ray);
    std::cout << "origin";
    util::printMat<double>(rayTracer.scene.camera.pos);

    cv::Mat color = rayTracer.castRay(camera_ray, rayTracer.scene.camera.pos, 1);

    std::cout << "color";
    util::printMat<double>(color);

    std::cout << "Testing Render" << std::endl;
    rayTracer.renderScene();

    return 0;
}

