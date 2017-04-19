#include "ray_tracer.hpp"

void RayTracer::render(){
    return;
}

void RayTracer::addObject(Object *obj){

    objects.push_back(obj);
    return;
}

void RayTracer::addLight(Light *light){

    lights.push_back(light);
    return;
}

Vector RayTracer::calcCameraRay(
                                Camera &camera,
                                double width, double height, 
                                int i, int j){

    Vector r;

    double x = -1.0 * camera.near * camera.n.x +
    width * (2.0 * i / camera.window.width - 1.0) * camera.u.x +
    height * (2.0 * j / camera.window.height - 1.0) * camera.v.x;

    double y = -1.0 * camera.near * camera.n.y +
    width * (2.0 * i / camera.window.width - 1.0) * camera.u.y +
    height * (2.0 * j / camera.window.height - 1.0) * camera.v.y;

    double z = -1.0 * camera.near * camera.n.z +
    width * (2.0 * i / camera.window.width - 1.0) * camera.u.z +
    height * (2.0 * j / camera.window.height - 1.0) * camera.v.z;

    double w = 0.0;
    r = Vector(x, y, z, w);

    return r;
}

bool RayTracer::isShadow(
                        Vector &v_light,
                        Point &intersection){

    for(std::vector<Object*>::iterator obj = objects.begin(); obj != objects.end(); ++obj){
        if((*obj)->intersect(intersection, v_light))
            return true;
    }
    return false;
}

Point RayTracer::findClosestIntersection(
                                        Vector &ray,
                                        Object **object){

    double min_dist = -1.0;
    Object *min_obj = NULL;

    for(std::vector<Object*>::iterator obj = objects.begin(); obj != objects.end(); ++obj){
        
        double dist = (*obj)->intersect(this->camera.pos, ray);

        if(dist < min_dist && dist > 0){
            min_dist = dist;
            min_obj = *obj;
        }
    }

    *object = min_obj;

    return findPointOnVector(ray, min_dist);
}

Color RayTracer::castRay(
                        Vector &ray,
                        Point origin,
                        int level){

    Object *object;
    Color pixel_color;
    Point intersection;

    intersection = findClosestIntersection(ray, &object);

    if(object != NULL){
        
        Color specular_comp = Color();
        Color diffuse_comp = Color();

        Material material = object->material;
        Vector v_normal = object->getNormal(intersection);
        Vector v_camera = calcCenterVector(intersection, origin);
        
        for(std::vector<Light*>::iterator light = lights.begin(); light != lights.end(); ++light){
            
            Vector v_light = calcLightVector(intersection, **light);
            Vector v_specular = calcSpecVector(v_normal, v_light);

            specular_comp += calcSpecularComp(v_specular, v_camera, **light, material)
            diffuse_comp += calcDifusalComp(v_normal, v_light, *light, material);
        }

        Color ambient_comp = calcAmbientComp(object->material.color, ambient_light_intensity);

        if(level){
            //Reflection
            Vector v_reflection = calcReflectionVector(ray, v_normal);
            Color reflection_comp = castRay(v_reflection, intersection, level-1);

            //Refraction
            Vector v_refraction = calcRefractionVector(ray, v_normal, material);
            Color refraction_comp = castRay(v_refraction, intersection, level-1);

            pixel_color = ambient_comp + specular_comp + diffuse_comp + refraction_comp + reflection_comp;
        }else{
            pixel_color = ambient_comp + specular_comp + diffuse_comp;
        }

    }else{
        pixel_color = Color();
    }

    return pixel_color;
}

Vector RayTracer::calcCenterVector(
                                Point &intersection, 
                                Point &origin){

    return Vector(origin - intersection).normalize();
}

Vector RayTracer::calcLightVector(
                                Point &intersection,
                                Light &light){

    return Vector(light.pos - intersection).normalize();
}

Vector RayTracer::calcSpecVector(
                                Vector &normal,
                                Vector &light){
    
    Vector spec_vector = Vector();
    double sn = dot_product(light, normal);
    double nn = dot_product(normal, normal);

    spec_vector -= light;
    spec_vector += normal * (2 * sn / nn);

    spec_vector.normalize();

    return spec_vector;
}

Color RayTracer::calcAmbientComp(
                                Color objColor,
                                double intensity){
    
    return objColor*intensity;
}

Color RayTracer::calcDifusalComp(
                                Vector &normal,
                                Vector &v_light,
                                Light &light,
                                Material &material){

    double nl = dot_product(normal, v_light);
    double nSize = sqrt(dot_product(normal, normal));
    double lSize = sqrt(dot_product(v_light, v_light));

    double i_diffuse = material.diffuse_coeff * std::max(0.0, nl/(nSize*lSize));
    Color diffuse_comp = Color(material.color * i_diffuse);

    return diffuse_comp;
}

Color RayTracer::calcSpecularComp(
                                Vector &specular,
                                Vector &camera,
                                Light &light,
                                Material &material){

    double sc = dot_product(specular, camera);
    double sSize = sqrt(dot_product(specular, specular));
    double cSize = sqrt(dot_product(camera, camera));

    double i_specular = material.specular_coeff * std::pow(std::max(0.0, sc/(sSize*cSize)), material.f);
    Color specular_comp = Color(material.color * i_specular);

    return specular_comp;
}

Vector RayTracer::calcReflectionVector(
                                    Vector &normal,
                                    Vector &incidence){


}

Vector calcRefractionVector(
                            Vector &incidence,
                            Vector &normal,
                            Material &material){

}