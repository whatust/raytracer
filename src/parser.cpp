#include "parser.hpp"

Parser::Parser() : version(1.0), doc(""), args_doc(""){}

Parser::Parser(const std::string &version, const std::string &doc, const std::string &args_doc) : \
	version(std::stof(version)), doc(doc), args_doc(args_doc){}

bool Parser::stob(
				const std::string str){

	return (str.compare("True") == 0);
}

void Parser::addArgument(
					const std::string name,
					const std::string default_value,
					const std::string type,
					const std::string help_message){

	if(type.compare("int") == 0){
		TypedValue<int> *conv_value = new TypedValue<int>(std::stoi(default_value), type, help_message);
		argument_list.insert(std::pair<std::string, TypedValue<int>*>(name, conv_value));
	}else if(type.compare("double") == 0){
		TypedValue<double> *conv_value = new TypedValue<double>(std::stod(default_value), type, help_message);
		argument_list.insert(std::pair<std::string, TypedValue<double>*>(name, conv_value));
	}else if(type.compare("bool") == 0){
		TypedValue<bool> *conv_value = new TypedValue<bool>(stob(default_value), type, help_message);
		argument_list.insert(std::pair<std::string, TypedValue<bool>*>(name, conv_value));
	}else if(type.compare("str") == 0){
		TypedValue<std::string> *conv_value = new TypedValue<std::string>(default_value, type, help_message);
		argument_list.insert(std::pair<std::string, TypedValue<std::string>*>(name, conv_value));
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
		std::cout << itr->first << "    ";
		if(itr->second->getType().compare("int") == 0){
			TypedValue<int> *aux_val = (TypedValue<int> *) itr->second;
			aux_val->print();
		}else if(itr->second->getType().compare("double") == 0){
			TypedValue<double> *aux_val = (TypedValue<double> *) itr->second;
			aux_val->print();
		}else if(itr->second->getType().compare("str") == 0){
			TypedValue<std::string> *aux_val = (TypedValue<std::string> *) itr->second;
			aux_val->print();
		}else if(itr->second->getType().compare("bool") == 0){
			TypedValue<bool> *aux_val = (TypedValue<bool> *) itr->second;
			aux_val->print();
		}
	}
	return;
}

void Parser::printHelp(){
	std::cout << "version: ray_tracer" << version << std::endl;
	std::cout << doc << std::endl;
	std::cout << args_doc << std::endl <<std::endl;

	for(std::map<std::string, Value*>::iterator itr = argument_list.begin(); itr != argument_list.end(); itr++){
		std::cout << itr->first << "   " << itr->second->getHelpMessage() << std::endl;
	}
	return;
}

void Parser::setValue(
					const std::string name,
					const std::string value){

	std::string type = argument_list[name]->getType();

	if(argument_list[name]->getType().compare("int") == 0){
		TypedValue<int> *aux_val = (TypedValue<int> *) argument_list[name];
		aux_val->setValue(std::stoi(value));
	}else if(argument_list[name]->getType().compare("double") == 0){
		TypedValue<double> *aux_val = (TypedValue<double> *) argument_list[name];
		aux_val->setValue(std::stof(value));
	}else if(argument_list[name]->getType().compare("str") == 0){
		TypedValue<std::string> *aux_val = (TypedValue<std::string> *) argument_list[name];
		aux_val->setValue(value);
	}else if(argument_list[name]->getType().compare("bool") == 0){
		TypedValue<bool> *aux_val = (TypedValue<bool> *) argument_list[name];
		aux_val->setValue(stob(value));
	}
}

template<typename T>
T Parser::getValue(const std::string name){

	TypedValue<T> *pointer = (TypedValue<T> *) argument_list[name];
	return pointer->getValue();
}

void Parser::parseArguments(
						int argc,
						char* argv[]){

	for(int idx = 1; idx < argc; idx++){
		
		int arg_idx = idx++;
		int val_idx = idx;

		setValue(std::string(argv[arg_idx]), std::string(argv[val_idx]));
	}
	return;
}
