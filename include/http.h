#ifndef URIFIC
#define URIFIC

#include "http_request.h"
#include "http_response.h"
#include "linked_list.h"

#define METHOD_GET 	0
#define METHOD_POST	1


struct urific {
	struct linkedlist http_request;
	http_response *response[];
};

#endif
