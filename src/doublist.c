#include "doublist.h"

#include <string.h>

#include "xmalloc.h"

struct __doublist__ *doublist_create() {

	struct __doublist__ *doublist = xmalloc(sizeof(struct __doublist__));
	doublist->head = NULL;
	doublist->tail = NULL;
	doublist->size = 0;

	return doublist;
}

struct __node__ *node_create(void *value, int type) {
	
	struct __node__ *node = xmalloc(sizeof(struct __node__));
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	node->type = type;
	node->is_in_list = __STANDALONE__;
	
	return node;

}

void node_insert_after(struct __doublist__ *doublist, struct __node__ *node, struct __node__ *new_node) {

	if (node == NULL) {
		if (doublist_get_size(doublist) == 0) {
			
			doublist->head = new_node;
			doublist->tail = new_node;

		} else {

			doublist->tail->next = new_node;
			new_node->prev = doublist->tail;
			doublist->tail = new_node;

		}

	} else {
		if (node->next == NULL) {
			
			node->next = new_node;
			new_node->prev = node;
			doublist->tail = new_node;

		} else {
			
			node->next->prev = new_node;
			new_node->prev = node;
			new_node->next = node->next;
			node->next = new_node;

		}

	}
	
	++doublist->size;
	new_node->is_in_list = __INLIST__;

}

void node_insert_before(struct __doublist__ *doublist, struct __node__ *node, struct __node__ *new_node) {

	if (node == NULL) {
		if (doublist_get_size(doublist) == 0) {
			
			doublist->head = new_node;
			doublist->tail = new_node;

		} else {
			
			doublist->head->prev = new_node;
			new_node->next = doublist->head;
			doublist->head = new_node;

		}

	} else {
		if (node->prev == NULL) {
			
			node->prev = new_node;
			new_node->next = node;
			doublist->head = new_node;

		} else {
			
			node->prev->next = new_node;
			new_node->next = node;
			new_node->prev = node->prev;
			node->prev = new_node;
			
		}

	}

	++doublist->size;
	new_node->is_in_list = __INLIST__;

}


struct __node__ *node_find(struct __doublist__ *doublist, struct __node__ *start, void *value, int type, unsigned long size, int direction) {

	if (start == NULL) {
		if (direction == FORWARD) {
			start = doublist->head;
		} else {
			start = doublist->tail;
		}
	}

	if (direction == FORWARD) {
		while (start != NULL) {
			if (start->type == type) {
				if (memcmp(start->value, value, size) == 0) {
					return start;
				}
				start = start->next;
			}
		}

	} else {
		while (start != NULL) {
			if (start->type == type) {
				if (memcmp(start->value, value, size)) {
					return start;
				}
				start = start->prev;
			}
		}
	}

	return NULL;
}

struct __node__ *node_modify(struct __doublist__ *doublist, struct __node__ *node_old, struct __node__ *node_new) {

	node_old->value = node_new->value;
	node_old->type = node_new->type;
	node_free(doublist, node_new);
	return node_old;

}

struct __node__ *node_remove(struct __doublist__ *doublist, struct __node__ *node) {

	if (node->is_in_list != __STANDALONE__) {
		if (doublist->head == node && doublist->tail == node) {
			doublist->head = NULL;
			doublist->tail = NULL;
		} else if (doublist->head == node) {
			doublist->head = node->next;
			doublist->head->prev = NULL;
		} else if (doublist->tail == node) {
			doublist->tail = node->prev;
			doublist->tail->next = NULL;
		} else {
			node->next->prev = node->prev;
			node->prev->next = node->next;

		}

		node->next = NULL;
		node->prev = NULL;
		--doublist->size;

	}
	
	return node;

}

void doublist_free(struct __doublist__ *doublist) {

	struct __node__ *node = doublist->head;
	while (node != NULL) {
		struct __node__ *tmp = node->next;
		node_free(doublist, node);
		node = tmp;
	}
	xfree(doublist);

}

void node_free(struct __doublist__ *doublist, struct __node__ *node) {

	node = node_remove(doublist, node);
	xfree(node->value);
	xfree(node);

}

int doublist_get_size(struct __doublist__ *doublist) {
	return doublist->size;

}
