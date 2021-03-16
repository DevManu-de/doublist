#include <stdio.h>
#include <string.h>

#include "doublist.h"
#include "xmemtools.h"

int main() {

	char *a = "asdfghjklv";
	
	struct doublist *list = doublist_create();

	unsigned int i;
	for (i = 0; i < strlen(a); ++i) {
		char *b = xmalloc(2);
		b[0] = a[i];
		b[1] = '\0';
			
		node_insert_after(list, NULL, node_create(b, 1));
	}

	char *x = strdup("A");
	node_modify(list, list->tail, node_create(x, 1), 2, 1);

	struct node  *node = list->head;
	while (node != NULL) {
		putc(((char *)(node->value))[0], stdout);
		node = node->next;
	}

	printf("\n%s\n", ((char *) node_find(list, NULL, "A", 1, 1, FORWARD)->value));
	printf("%d\n", doublist_get_size(list));

	doublist_free(list);

	return 0;
}

