#ifndef _DOUBLIST_H
#define _DOUBLIST_H

#define __STANDALONE__ 0
#define __INLIST__ 1

struct __node__ {
	
	void *value;
	int type;
	struct __node__ *next;
	struct __node__ *prev;
	int is_in_list : 1;

};

struct __doublist__ {
	
	struct __node__ *head;
	struct __node__ *tail;
	int size;

};

struct __doublist__ *doublist_create();
struct __node__ *node_create(void *value, int type);

void node_insert_after(struct __doublist__ *doublist, struct __node__ *node, struct __node__ *new_node);
void node_insert_before(struct __doublist__ *doublist, struct __node__ *node, struct __node__ *new_node);

#define FORWARD 0
#define BACKWARD 1
struct __node__ *node_find(struct __doublist__ *doublist, struct __node__ *start, void *value, int type, unsigned long size, int direction);
struct __node__ *node_modify(struct __doublist__ *doublist, struct __node__ *node_old, struct __node__ *node_new);

struct __node__ *node_remove(struct __doublist__ *doublist, struct __node__ *node);

void doublist_free(struct __doublist__ *doublist);
void node_free(struct __doublist__ *doublist, struct __node__ *node);

int doublist_get_size(struct __doublist__ *doublist);

#endif
