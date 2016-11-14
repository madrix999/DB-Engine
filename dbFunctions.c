#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include <fcgi_stdio.h>
#include "dbFunctions.h"
#include "main.h"

/*void exit() {
	// Write database structure to file
}*/

int print_parent(node_p * parent, node_c * child/*, char *element*/) {
	node_p * current = parent;
	node_c * child_current = child;
	
	/*while (strcmp(element, current->element) != 0) {
		current = current->next;
	}
	
	printf("id: %d\telement: %s\tnext: %p\n", current->itemid, current->element, current->next);
	
	while (child_current != NULL) {
		if (child_current->parentid == current->itemid) {
			printf("->id: %d\tparent id:%d\telement: %s\tvar: %d\tnext: %p\tparent:%p\n", child_current->itemid, child_current->parentid, child_current->element, child_current->var, child_current->next, current);
		}
		child_current = child_current->next;
	}
	
	return 0;*/
	
	while (current->next != NULL) {
		printf("id: %d\telement: %s\tnext: %p\n", current->itemid, current->element, current->next);
		while (child_current != NULL) {
			if (child_current->parentid == current->itemid) {
				printf("->id: %d\tparent id:%d\telement: %s\tvar: %d\tnext: %p\tparent:%p\n", child_current->itemid, child_current->parentid, child_current->element, child_current->var, child_current->next, current);
			}
			child_current = child_current->next;
		}
		current = current->next;
		child_current = child;
	}
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

int check_parents(node_p * parent, char *arg) {
	node_p * current = parent;
	int x = 0;
	char *str[x];

	while (current->next != NULL) {
		str[x] = current->element;
		x++;
		current = current->next;
	}

	for (int i = 0; i < x; i++) {
		if (strcmp(str[i], arg) == 0) {
			return 1;
		}
	}

	return 0;
}

void add_child(node_c * child, int var, char *arg, int itemid, int parentid) {
	node_c * child_current = child;
	
	while (child_current->next != NULL) {
		child_current = child_current->next;
	}
	
	child_current->next = malloc(sizeof(node_c));
	child_current = child_current->next;
	child_current->itemid = itemid;
	child_current->parentid = parentid;
	child_current->var = var;
	child_current->element = arg;
	child_current->next = NULL;
}

int init(node_p * parent, node_c * child) {
	node_p *temp_parent = NULL;
	node_c *temp_child = NULL;
	int parent_added = 0;
	char input[0];
	int exit = 0;
	char *prparent;
	
	while (exit == 0) {
		printf("dbengine=> ");
		scanf("%c", &input[0]);
		getchar();
		
		if (input[0] == 'p') {
			temp_parent = malloc(sizeof(node_p));
			
			printf("\nid: ");
			scanf("%d", &temp_parent->itemid);
			
			printf("\nelement: ");
			scanf("%s", temp_parent->element);
			
			add_parent_node(parent, temp_parent->itemid, temp_parent->element);
			free(temp_parent);
			memset(input, 0, sizeof(char));
		} if (input[0] == 'c') {
			temp_child = malloc(sizeof(node_c));
			
			printf("var: ");
			scanf("%d", &temp_child->var);
			
			printf("itemid: ");
			scanf("%d", &temp_child->itemid);
			
			printf("element: ");
			scanf("%s", temp_child->element);
			
			printf("parent id: ");
			scanf("%d", &temp_child->parentid);
			
			add_child(child, temp_child->var, temp_child->element, temp_child->itemid, temp_child->parentid);
			free(temp_child);
			memset(input, 0, sizeof(char));
		} if (input[0] == 'o') {
			print_parent(parent, child);
			memset(input, 0, sizeof(char));
		} if (input[0] == 'e') {
			exit = 1;
			memset(input, 0, sizeof(char));
		} if (input[0] == 'h') {
			printf("h: help\n");
			printf("p: add parent node\n");
			printf("c: add child node\n");
			printf("o: output db\n");
			printf("e: output db to file and exit\n");
			memset(input, 0, sizeof(char));
		}
	}
	
	return 0;
}
/*
 *  else {
			printf("retry...\n\n");
		}
 */