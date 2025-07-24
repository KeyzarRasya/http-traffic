#ifndef YAMLPARSER
#define YAMLPARSER

struct endpoints{
    char *url;
    char *method;
    float load;
    char *body;
    char *params;
    char *query;
};

struct url_list {
    char *baseUr;
    struct endpoints *endpoint[];
};

struct url_list *parse(char *filepath);


#endif