#include "parser.hpp"

Parser::Parser() : version(1.0), doc(""), args_doc(""){}

Parser::Parser(char version[], char doc[], char args_doc[]) : \
	version(atof(version)),	doc(doc), args_doc(args_doc){}

bool Parser::stob(const std::string str){
	return (str.compare("True") == 0);
}

void Parser::addArgument(const std::string name, const std::string default_value, const std::string type, const std::string help_message){

	if(type.compare("int") == 0){
		TypedValue<int> *conv_value = new TypedValue<int>(std::stoi(default_value), type, help_message);
		argument_list.insert(std::pair<std::string, Value*>(name, conv_value));
	}else if(type.compare("double") == 0){
		TypedValue<double> *conv_value = new TypedValue<double>(std::stod(default_value), type, help_message);
		argument_list.insert(std::pair<std::string, Value*>(name, conv_value));
	}else if(type.compare("bool") == 0){
		TypedValue<bool> *conv_value = new TypedValue<bool>(stob(default_value), type, help_message);
		argument_list.insert(std::pair<std::string, Value*>(name, conv_value));
	}else if(type.compare("str") == 0){
		TypedValue<std::string> *conv_value = new TypedValue<std::string>(default_value, type, help_message);
		argument_list.insert(std::pair<std::string, Value*>(name, conv_value));
	}else{
		std::cerr << "Unknown argument type: " << type << std::endl;
	}
}

void Parser::deleteArguments(){
	for(std::map<std::string, Value*>::iterator itr = argument_list.begin(); itr != argument_list.end(); itr++){
		delete itr->second;
	}
	argument_list.clear();
}

void Parser::printArguments(){
	for(std::map<std::string, Value *>::iterator itr = argument_list.begin(); itr != argument_list.end(); itr++){
		std::cout << itr->first;
		itr->second->print();
	}
	return;
}

void Parser::printHelp(){
	std::cout << "version: ray_tracer" << version << std::endl;
	std::cout << doc << std::endl;
	std::cout << args_doc << std::endl <<std::endl;

	for(std::map<std::string, Value *>::iterator itr = argument_list.begin(); itr != argument_list.end(); itr++){
		std::cout << itr->first << "   " << itr->second->getHelpMessage() << std::endl;
	}
	return;
}

void Parser::setValue(const std::string name, const std::string value){
	//argument_list[name]->setValue(value);
}

void Parser::parseArguments(int argc, char* argv[]){


	for(int idx = 1; idx < argc; idx++){
		
		int arg_idx = idx++;
		int val_idx = idx;

		std::map<std::string, Value *>::iterator it;
		it = argument_list.find(argv[arg_idx]);

		setValue(argv[arg_idx], argv[val_idx]);
	}
	return;
}
