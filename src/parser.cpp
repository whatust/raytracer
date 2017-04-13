
Parser::Parser(){}

Parser::Parser(char[] version, char[] doc, char[] arg_doc) : \
	version(atof(version)),	doc(doc), arg_doc(arg_doc){}

void Parser::addArgument(char[] flag, char[] type, char[] default_value, bool optional, char[] help_message){
	argument_t arg;

	arg.flag = flag;
	arg.type = type;
	arg.default_value = default_value;
	arg.optional = optional;
	arg.help_message = help_message;

	this->argument_list.push_back(arg);

	return;
}

void Parser::printArgumentList(){
	for(std::vector<argument_t>::iterator itr = argument_list.begin(); itr != argument_list.end(); itr++){
		std::cout << itr->flag << " " << itr->type << " " << itr->default_value;
		std::cout << " " << itr->optional << " " << itr->help_message << std::endl;
	}
	return;
}

void Parser::printHelp(){
	std::cout << "version: ray_tracer" << version << std::endl;
	std::cout << doc << std::endl;
	std::cout << arg_doc << std::endl <<std::endl;

	for(std::vector<argument_t>::iterator itr = argument_list.begin(); itr != argument_list.end(); itr++){
		std::cout << itr->flag << "   " << itr->help_message << std::endl;
	}
	return;
}
