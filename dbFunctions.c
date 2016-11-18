#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dbFunctions.h"
#include "main.h"

/*void exit() {
	// Write database structure to file
}*/

int print_parent(node_p * parent, node_c * child) {
	node_p * current = parent;
	node_c * child_current = child;
	
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

	
void init(node_p * parent, node_c * child) {
	node_p * ptemp = parent;
	node_c * ctemp = child;
	ptemp = NULL;
	ctemp = NULL;
	int exit = 0;
	char buffer[256] = {0};
	char *input;
	
	while (exit == 0) {
		scanf("%s", input);
		
		if (strcmp(input, "parent") == 0) {
			free(input);
			ptemp = malloc(sizeof(node_p));
			
			printf("Id: ");
			scanf("%d", &ptemp->itemid);
			printf("\nElement:");
			scanf("%s", ptemp->element);
			
			add_parent_node(parent, ptemp->itemid, ptemp->element);
			
			free(ptemp);
		} else if (input == "child") {
			free(input);
			ctemp = malloc(sizeof(node_c));
			
			scanf("%d", &ctemp->var);
			scanf("%s", ctemp->element);
			scanf("%d", &ctemp->itemid);
			scanf("%d", &ctemp->parentid);
			
			add_child(child, ctemp->var, ctemp->element, ctemp->itemid, ctemp->parentid);
			
			free(ctemp);
		} else if (input == "output") {
			free(input);
			print_parent(parent, child);
		} else if (input == "exit") {
			free(input);
			exit = 1;
		}
	}
}