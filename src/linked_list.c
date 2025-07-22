#include <stdlib.h>
#include <stdio.h>
#include "../include/linked_list.h"

struct linkedlist *init_linkedlist(enum linkedlist_type type) {
	struct linkedlist *ll = malloc(sizeof(struct linkedlist));
	if (!ll) {
		perror("Failed to allocate linkedlist");
		return NULL;
	}
	ll->first = NULL;
	ll->last = NULL;
	ll->size = 0;
	ll->type = type;

	return ll;
}

struct node *init_node(
	struct node *prev,
	union node_value *val,
	struct node *next
) {
	struct node *n = malloc(sizeof(struct node));
	if (!n) return  NULL;
	n->prev = prev;
	n->next = next;
	n->val = val;

	return n;
}

void add_last(struct linkedlist *ll, union node_value *val) {
	struct node *n = init_node(ll->last, val, NULL);
	if (!n) return; 
	if (ll->first == NULL) {
		ll->first = n;
		ll->last = n;
	} else {
		ll->last->next = n;
		ll->last = n;
	}
	ll->size++;
}

void print_linkedlist(struct linkedlist *ll) {
	switch (ll->type) {
		case LL_HttpRequest:
			print_linkedlist_request(ll);
			break;
		case LL_HttpResponse:
			print_linkedlist_response(ll);
			break;
	}
}

void print_linkedlist_request(struct linkedlist *ll) {
	struct node *current_node = ll->first;

	while (current_node != NULL) {
		printf("%s\n", current_node->val->req->url);
		current_node = current_node->next;
	}
}

void print_linkedlist_response(struct linkedlist *ll) {
	struct node *current_node = ll->first;

	while (current_node != NULL) {
		printf("%d\n", current_node->val->res->status);
		current_node = current_node->next;
	}
}
