#include <stdlib.h>
#include <stdio.h>
#include "../include/linked_list.h"

void init_linkedlist(struct linkedlist *ll) {
	ll = malloc(sizeof(struct linkedlist));
	if (!ll) {
		perror("Failed to allocate linkedlist");
		return;
	}
	ll->first = NULL;
	ll->last = NULL;
	ll->size = 0;
}

struct node *init_node(
	struct node *prev,
	struct http_request *val,
	struct node *next
) {
	struct node *n = malloc(sizeof(struct node));
	if (!n) return  NULL;
	n->prev = prev;
	n->next = next;
	n->val = val;
	return n;
}

void add_last(struct linkedlist *ll, struct http_request *val) {
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
	struct node *current_node = ll->first;
	while (current_node != NULL) {
		printf("%s\n", current_node->val->url);
		current_node = current_node->next;
	}
}
