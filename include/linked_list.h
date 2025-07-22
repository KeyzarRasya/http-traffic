#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdio.h>
#include "http_request.h"

struct linkedlist {
	struct node *first;
	struct node *last;
	size_t size;
};

struct node {
	struct node *prev;
	struct http_request *val;
	struct node *next;
};

void init_linkedlist(struct linkedlist *ll);
struct node *init_node(struct node *prev, struct http_request *val, struct node *next);
void add_last(struct linkedlist *ll, struct http_request *val);
void print_linkedlist(struct linkedlist *ll);

#endif
