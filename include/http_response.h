#ifndef HTTP_RESPONSE
#define HTTP_RESPONSE

#include <stdint.h>

struct http_response {
	uint32_t status;
	char *response;
};

#endif
