#ifndef DBENGINE_FUNCTIONS_H
#define DBENGINE_FUNCTIONS_H

// Parent node, contains itemid, element(children) and pointer to next parent node
typedef struct parent {
	int itemid;
	struct parent * next;
	struct child * children;
	char *element;
} node_p;

// Children node, contains data and pointer to parent node
typedef struct child {
	int var;
	int itemid;
	int parentid;
	struct child * next;
	char *element;
} node_c;

int init();
char *input();

#endif
