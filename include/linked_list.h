#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdio.h>
#include "http_request.h"
#include "http_response.h"

enum linkedlist_type {
	LL_HttpRequest,
	LL_HttpResponse,
};

union node_value {
	struct http_request *req;
	struct http_response *res;
};

struct linkedlist {
	struct node *first;
	struct node *last;
	size_t size;
	enum linkedlist_type type;
};

struct node {
	struct node *prev;
	union node_value *val;
	struct node *next;
};

struct linkedlist *init_linkedlist(enum linkedlist_type type);
struct node *init_node(struct node *prev, union node_value *val, struct node *next);
void add_last(struct linkedlist *ll, union node_value *val);
void print_linkedlist(struct linkedlist *ll);
void print_linkedlist_request(struct linkedlist *ll);
void print_linkedlist_response(struct linkedlist *ll);

#endif
