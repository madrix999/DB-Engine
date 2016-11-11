#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dbFunctions.h"

/*void exit() {
	// Write database structure to file
}*/

int print_parent(node_p * parent, char *element) {
	node_p * current = parent;

	while (strcmp(element, current->element) != 0) {
		current = current->next;
	}
	
	printf("id: %d\telement: %s\tnext: %p\n", current->itemid, current->element, current->next);

	/*
	while (child->next != NULL) {
		if (child_current->parentid == current->itemid) {
			printf("id: %d\tparent id:%d\telement: %s\tnext: %p\tparent:%p\n", child_current->itemid, child_current->parentid, child_current->element[0], child_current->next, *current);
		}
		child_current = child_current->next;
	}*/
}

void add_parent_node(node_p * parent, int id, char *element) {
	node_p * current = parent;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = malloc(sizeof(node_p));
	current = current->next;
	current->itemid = id;
	current->element = element;
	current->next = NULL;
}

int check_parents(node_p * parent, char *arg[]) {
	node_p * current = parent;
	int x = 0;
	char *str[x];

	while (current->next != NULL) {
		str[x] = current->element;
		x++;
		current = current->next;
	}

	for (int i = 0; i < x; i++) {
		if (strcmp(str[i], arg[1]) == 0) {
			return 1;
		}
	}

	return 0;
}



/*void add_child(node_c * child, node_p * parent, int var, char *arg, int itemid, int parentid) {
	node_c * child_current = child;
	node_p * parent_current = parent;
	while (child_current->next != NULL) {
		child_current = child_current->next;
	}
	while (parent_current->itemid != itemid) {
		parent_current = parent_current->next;
	}
	if (child_current == NULL) {
		child_current->next = malloc(sizeof(node_c));
		child_current = child_current->next;
		child_current->itemid = itemid;
		child_current->parent = parent_current;
		child_current->parentid = parentid;
		child_current->var = var;
		child_current->element[0] = arg[0];
	} else {
		child_current->next = NULL;
		child_current->itemid = itemid;
		child_current->parent = parent_current;
		child_current->parentid = parentid;
		child_current->var = var;
		child_current->element[0] = arg[0];
	}
}*/

/*void add_child_to_parent(node_p * parent, node_c * child) {

}*/
