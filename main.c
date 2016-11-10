#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dbFunctions.h"

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("No arguments given.\n");
		return 0;
	} if (argc != 2){
		printf("Too many arguments given.\n");
		return 0;
	}
	node_p * parent = NULL;
	node_c * child = NULL;
	parent = malloc(sizeof(node_p));
	child = malloc(sizeof(node_c));


	parent->element[0] = "test";
	parent->itemid = 0;
	parent->next = NULL;

	add_parent_node(parent, 1, "Username");
	add_parent_node(parent, 2, "Password");

	//add_child(child, parent, 123, "testuser", 0, 1);
	//add_child(child, parent, 456, "testpass", 0, 2);

	/*if (check_parents(parent, argv[1]) == 0) {
		printf("Invalid argument given.\n");
		return 0;
	}*/

	print_parent(parent, child, 1);

	return 0;
}

/*
if (parent && child == NULL) {
	return 1;
}
*/