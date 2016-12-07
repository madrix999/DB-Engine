#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dbFunctions.h"
#include "main.h"

int main(int argc, char *argv[]) {
	if (argc > 1) {
		printf("Do not run the program with arguments!");
		return 0;
	}
	// Init and malloc parent and child nodes
	node_p * parent = NULL;
	node_c * child = NULL;
	parent = malloc(sizeof(node_p));
	child = malloc(sizeof(node_c));

	// Default parent and child node, will not be printed to database file.
	parent->element = "test";
	parent->itemid = 0;
	parent->next = NULL;

	child->var = 123;
	child->parentid = 0;
	child->itemid = 0;
	child->element = "test";
	child->next = NULL;
<<<<<<< HEAD
	
=======

	print_parent(parent, child);

>>>>>>> 0092189c709a4c7884de4cc29c3bf75598d12915
	init(parent, child);

	return 0;
}
