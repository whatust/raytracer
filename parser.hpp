#include <argp.h>
#include <stdbool.h>
#include <iostream>

typedef enum { CHARACTER_MODE, WORD_MODE, LINE_MODE } Mode;


const char *argp_program_version = "ray_tracer 0.1";
//const char *argp_program_bug_address = "";
static char doc[] = "Simple Ray tracer in C++ and CUDA";
static char args_doc[] = "[FILENAME]... -s SCENE_FILE_NAME -w WIDTH -h HEIGHT -l LEVEL";
static struct argp_option options[] = {
    {"scene",  'f', "SCENE_FILE_NAME", 0,                   "Scene file, list of objects, materials and light"},
    {"width",  'w', "WIDTH",           OPTION_ARG_OPTIONAL, "Window width in pixels (default = 800)"},
    {"height", 'h', "HEIGHT",          OPTION_ARG_OPTIONAL, "Window height in pixels (default = 600)"},
    {"level",  'l', "LEVEL",           OPTION_ARG_OPTIONAL, "Number of recussion levels for reflection and refraction (default = 3)"},
    {0} 
};

typedef struct arguments {
    int width, height;
    int level;
    char *file_name;
}arguments_t;

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = (struct arguments *) state->input;

    switch (key) {
    case 'w': 
            if(arg ==  NULL)
                arguments->width = 800;
            else
                arguments->width = strtol(arg, NULL, 10);
            break;

    case 'h':
            if(arg == NULL)
                arguments->height = 600;
            else
                arguments->height = strtol(arg, NULL, 10);
            break;

    case 'l':
            if(arg == NULL)
                arguments->level = 3;
            else
                arguments->level = strtol(arg, NULL, 10);
            break;

    case 'f':
            arguments->file_name = arg;
            break;

    case ARGP_KEY_ARG:
    default: return ARGP_ERR_UNKNOWN;
    }   
    return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc, 0, 0, 0 };

arguments_t *initParser(int argc, char *argv[]){

    arguments_t *arguments;

    arguments = new arguments;

    //Default Values
    arguments->width = 800;
    arguments->height = 600;
    arguments->level = 3;

    argp_parse(&argp, argc, argv, 0, 0, arguments);

    return arguments;
}
