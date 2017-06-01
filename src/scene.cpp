#include "scene.hpp"

Scene::Scene() : ambient_light_intensity(0.1), level(0) {
    camera = Camera();
}

Scene::~Scene(){}

double Scene::getAmbientIntensity(){
    return ambient_light_intensity;
}

void Scene::loadScene(const std::string &filename){
    
    std::ifstream input_stream;
    std::string line;

    input_stream.open(filename);

    if(!input_stream.is_open()){
        std::cerr << "Could not open file:" << filename << std:: endl;
    }else{
        //fscanf(input_stream, "%s", )
        while(!input_stream.eof()){

            std::getline(input_stream, line);
            std::cout << line << std::endl;

            if(line.compare("__END__") == 0){
                break;
            }

            if(line.compare("__LIGHT__") == 0){
                parseLight(input_stream);
            }else if(line.compare("__OBJECT__") == 0){
                parseObject(input_stream);
            }else if(line.compare("__MATERIAL__") == 0){
                parseMaterial(input_stream);
            }else if(line.compare("__CAMERA__") == 0){
                parseCamera(input_stream);
            }
        }
    }
    input_stream.close();
    return;
}

void Scene::parseLight(std::ifstream &input_stream){

    double pos[3];
    uint32_t col[3];
    double i;

    std::cout << "Loading Light" << std::endl;
    pos[3] = 1.0;

    //Read Data from file
    input_stream >> pos[0] >> pos[1] >> pos[2];
    input_stream >> col[0] >> col[1] >> col[2];
    input_stream >> i;
    
    cv::Mat position = (cv::Mat_<double>(3,1) << pos[0],pos[1],pos[2]);
    cv::Mat color = (cv::Mat_<double>(3,1) << col[0],col[1],col[2]);

    //Create Light Object
    lights.push_back(Light(position, color, i));

    return;
}

void Scene::parseObject(std::ifstream &input_stream){

    double pos[3];
    double rot[3];
    double scl[3];

    uint32_t m;
    std::string t;

    std::cout << "Loading Object" << std::endl;

    //Read Data from file
    input_stream >> pos[0] >> pos[1] >> pos[2];
    input_stream >> rot[0] >> rot[1] >> rot[2];
    input_stream >> scl[0] >> scl[1] >> scl[2];
    input_stream >> m >> t;

    //Create Light Object
    if(t.compare("PLANE") == 0){
        objects.push_back(std::shared_ptr<Object>(new Plane(pos, rot, scl, materials[m])));
    }else if(t.compare("SPHERE") == 0){
        objects.push_back(std::shared_ptr<Object>(new Sphere(pos, rot, scl, materials[m])));
    }

    return;
}

void Scene::parseCamera(std::ifstream &input_stream){

    double pos[3];
    double look[3];
    double up[3];

    int width, height;

    pos[3] = 1.0;
    input_stream >> pos[0] >> pos[1] >> pos[2];
    input_stream >> look[0] >> look[1] >> look[2];
    input_stream >> up[0] >> up[1] >> up[2];

    input_stream >> width >> height;

    cv::Mat position = (cv::Mat_<double>(3,1) << pos[0], pos[1], pos[2]);
    cv::Mat lookAt = (cv::Mat_<double>(3,1) << look[0], look[1], look[2]);
    cv::Mat up_v = (cv::Mat_<double>(3,1) << up[0], up[1], up[2]);

    camera = Camera(position, lookAt, up_v, width, height);

    //cameras.push_back(Camera())

    return;
}

void Scene::parseMaterial(std::ifstream &input_stream){

    std::string name;
    uint32_t col[3];
    double rfr, rfl, spec, diff, f;

    input_stream >> name;
    input_stream >> col[0] >> col[1] >> col[2];
    input_stream >> rfr >> rfl >> spec >> diff >> f;

    cv::Mat color = (cv::Mat_<double>(3,1) << col[0],col[1],col[2]);

    materials.push_back(std::shared_ptr<Material>(new Material(name, color, rfr, rfl, spec, diff, f)));

    return;
}

/*void Scene::saveScene(const std::string &filename){
	
	File file.open(filename.concat(".scene"), "w");
	file.write()
}*/
