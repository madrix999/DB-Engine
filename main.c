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
	} if (check_parents(parent, argv[1]) == 0) {
		
	}
	node_p * parent = NULL;
	node_s * child = NULL;
	parent = malloc(sizeof(node_p));
	child = malloc(sizeof(node_s));
	if (parent && child == NULL) {
		return 1;
	}
	
	parent->element[0] = "test";
	parent->itemid = 0;
	parent->next = NULL;
	
	add_parent_node(parent, 1, "Username");
	add_parent_node(parent, 2, "Password");
	
	
	print_parent(parent, argv[1]);
	
	return 0;
}
