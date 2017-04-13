#ifndef __PARSER_H__
#define __PARSER_H__ 

#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

const char *argp_program_version = "ray_tracer 0.1";
static char doc[] = "Simple Ray tracer in C++ and CUDA";
static char args_doc[] = "[FILENAME]... -s SCENE_FILE_NAME -w WIDTH -h HEIGHT -l LEVEL";

class Parser{
private:
    char argp_program_version[];
    char doc[];
    char args_doc[];
    std::vector<argument_t> argument_list;

public:
    Parser();
    Parser(char[] version, char[] doc, char[] arg_doc);
    void addArgument(char[] flag, char[] type, char[] default_value, bool optional, char[] help_message);
    void printArguments(const arguments_t &args);
}

#endif