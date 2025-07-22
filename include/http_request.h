#ifndef HTTP_REQUEST
#define HTTP_REQUEST

#include <stdint.h>

struct http_request {
	char *url;
	uint8_t method;
	char *body;
	char *param;
	char *query;
};

#endif
