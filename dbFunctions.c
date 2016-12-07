#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dbFunctions.h"
#include "main.h"

void print_parent(node_p * parent, node_c * child) {
	node_p * current = parent;
	node_c * child_current = child;

	while (current != NULL) {
		printf("id: %d\telement: %s\tnext: %p\n", current->itemid, current->element, current->next);
		while (child_current->next != NULL) {
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
	current->next->itemid = id;
	current->next->element = element;
	current->next->next = NULL;
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

char *input() {
	char *line = NULL, *tmp = NULL;
	size_t size = 0, index = 0;
	int ch = EOF;
	
	while (ch) {
		ch = getc(stdin);
		/* Check if we need to stop. */
		if (ch == EOF || ch == '\n')
			ch = 0;
		/* Check if we need to expand. */
		if (size <= index) {
			size += 1;
			tmp = realloc(line, size);
			if (!tmp) {
				free(line);
				line = NULL;
				break;
			}
			line = tmp;
		}
		/* Actually store the thing. */
		line[index++] = ch;
	}
	return line;
}

void init(node_p * parent, node_c * child) {
	while (commands(input(), parent, child) != 1) {
		commands(input(), parent, child);
	}
}

int commands(char *cmd, node_p * parent, node_c * child) {
	if (strcmp(cmd, "parent") == 0) {
		cmdParent(parent);
		return 0;
	} else if (strcmp(cmd, "child") == 0) {
		cmdChild(child);
		return 0;
	} else if (strcmp(cmd, "output") == 0) {
		print_parent(parent, child);
		return 0;
	} else if (strcmp(cmd, "exit") == 0) {
		return 1;
	}
}


void cmdParent(node_p * parent) {
	node_p * ptemp = parent;
	ptemp = malloc(sizeof(node_p));
	
	printf("Id: ");
	scanf("%d", &ptemp->itemid);
	printf("\nElement: ");
	ptemp->element = input();
	getchar();
	
	add_parent_node(parent, ptemp->itemid, ptemp->element);
	
	free(ptemp);
}

void cmdChild(node_c * child) {
	node_c * ctemp = child;
	ctemp = malloc(sizeof(node_c));
	
	printf("Var: ");
	scanf("%d", &ctemp->var);
	printf("\nElement: ");
	ctemp->element = input();
	getchar();
	printf("\nID: ");
	scanf("%d", &ctemp->itemid);
	printf("\nParent ID: ");
	scanf("%d", &ctemp->parentid);
	
	add_child(child, ctemp->var, ctemp->element, ctemp->itemid, ctemp->parentid);
	
	free(ctemp);
}