#include <stdio.h>
#include <string.h>

#include "doublist.h"
#include "xmalloc.h"

int main() {

	char *a = "asdfghjkl";
	
	struct __doublist__ *list = doublist_create();


	unsigned int i;
	for (i = 0; i < strlen(a); ++i) {
		char *b = xmalloc(2);
		b[0] = a[i];
		b[1] = '\0';
			
		node_insert_after(list, NULL, node_create(b, 1));
	}

	struct __node__  *node = list->head;
	while (node != NULL) {
		putc(((char *)(node->value))[0], stdout);
		node = node->next;
	}
	
	printf("\n");

	doublist_free(list);

	return 0;
}

