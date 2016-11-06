#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dbFunctions.h"

/*void exit() {
	// Write database structure to file
}*/

void print_parent(node_p * parent, char *arg) {
	node_p * current = parent;
	
	while (strcmp(current->element[0], arg) != 0) {
		current = current->next;
	}
	
	printf("id: %d\telement: %s\tnext: %p\n", current->itemid, current->element[0], current->next);
}

void add_parent_node(node_p * parent, int id, char *element) {
	node_p * current = parent;
	while (current->next != NULL) {
		current = current->next;
	}
	
	current->next = malloc(sizeof(node_p));
	current = current->next;
	current->itemid = id;
	current->element[0] = element;
}

int check_parents(node_p * parent, int *arg[]) {
	
}
