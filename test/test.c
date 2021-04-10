#include <stdio.h>
#include <string.h>

#include "doublist.h"
#include "xmemtools.h"

int main() {

	char *a = "asdfghjklv";
	
	struct doublist *list = doublist_create();

	unsigned int i;
	for (i = 0; i < strlen(a); ++i) {
		node_insert_after(list, NULL, node_create(strndup(a+i, 1), STRING_TYPE));
	}

	char *x = strdup("ASDF");
	node_modify(list, list->tail, node_create(x, STRING_TYPE), 5, 1);
    node_free(list, list->head);
    node_free(list, list->tail);

    ITER_DOUBLIST(list, n, 
            putc(((char *)(n->value))[0], stdout);
            )

    putc('\n', stdout);
    doublist_print(list);

    ITER_DOUBLIST(list, n, 
            putc(((char *)(n->value))[0], stdout);
            )
    putc('\n', stdout);

	//printf("\n%s\n", ((char *) node_find(list, NULL, "f", STRING_TYPE, 1, FORWARD)->value));
	//printf("%d\n", doublist_get_size(list));
    puts("SUCCESS");

	doublist_free(list);

	return 0;
}

