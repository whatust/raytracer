#ifndef __PARSER_H__
#define __PARSER_H__ 

#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <utility>
#include <typeinfo>


#include "value.hpp"


class Parser{
private:
	double version;
    std::string argp_program_version;
    std::string doc;
    std::string args_doc;
	std::map<std::string, Value*> argument_list;

	bool stob(const std::string str);

public:
    Parser();
    Parser(const std::string &version, const std::string &doc, const std::string &args_doc);

	void addArgument(const std::string name, const std::string default_value, const std::string type, const std::string help_message);
	void setValue(const std::string name, const std::string value);
	void parseArguments(int argc, char* argv[]);
	void deleteArguments();

	template<typename T>
	T getValue(const std::string name);

    void printHelp();
    void printArguments();
};

#endif
