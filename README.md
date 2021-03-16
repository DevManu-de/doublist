# doublist
A simple implementation of a doubly linked list.

# Usage
doublist is equipped with a makefile that allows you to generate a `.a` file.
To do so just type `make` in the root directory of the project.

## Structures
>
> struct node (more info in include/doublist.h)
> 
> struct doublist (more info in include/doublist.h)


## doublist_create() 
> Returns a pointer to doublist
>

## node_create()
> 1. Argument is a void \*
> 2. Argument is an integer. (Use this to determine the value of argument 1)
>
> Returns a pointer to a 

## node_insert_after()
> 1. Argument is the pointer to an allocated doublist
> 2. Argument is the pointer to a node (If NULL then append to end of doublist)
> 3. Argument is the pointer to a new node that should be inserted after argument 2
>
> Returns NONE (void)

## node_insert_before()
> 1. Argument is the pointer to an allocated doublist
> 2. Argument is the pointer to a node (If NULL then insert to start of doublist)
> 3. Argument is the pointer to a new node that should be inserted before argument 2
>
> Returns NONE (void)

## node_find()
> 1. Argument is the pointer to an allocated doublist
> 2. Argument is the pointer to a node from where to start looking for (If NULL then use argument 6 to determine whether to start from head or tail of doublist)
> 3. Argument is a void * (Same as node_create)
> 4. Argument is an integer (Same as node_create)
> 5. Argument is an unsigned long for comparing the void \*'s
> 6. Argument is a direction (FORWARD / BACKWARD) 
>
> Returns a pointer to the found node that matches the void * and type (NULL if not found)

## node_modify()
> 1. Argument is the pointer to an allocated doublist
> 2. Argument is the pointer to the node that should be changed
> 3. Argument is the pointer to the node thats values should be used to overwrite argument 2
> 4. Size of the void * from argument 3
> 5. If argument 3 should be free'd or not (1 == FREE / 1 != NOT FREE)
>
> Returns the pointer to the changed node (Same as argument 2)

## node_remove()
> 1. Argument is the pointer to an allocated doublist
> 2. Argument is the pointer to the node that should be removed
> 
> Returns a pointer to the node that is now isolated from any list but not free'd

## doublist_free()
> 1. Argument is the pointer to an allocated doublist that should be free'd and all of its nodes
>
> Returns NONE (void)

## node_free()
> 1. Argument is the pointer to an allocated doublist
> 2. Argument is the pointer to an allocated node that should be removed from the list and free'd
>
> Returns NONE (void)

## doublist_get_size()
> 1. Argument is the pointer to an allocated doublist
> 
> Returns the amount of nodes in the list as an integer
