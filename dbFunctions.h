#ifndef DBENGINE_FUNCTIONS_H
#define DBENGINE_FUNCTIONS_H

// Parent node, contains itemid, element(children) and pointer to next parent node
typedef struct parent {
	int itemid;
	struct parent * next;
	char *element[];
} node_p;

// Children node, contains data and pointer to parent node
typedef struct child {
	int var;
	int itemid;
	struct parent * parent;
	struct child * next;
} node_s;

//void exit();
void print_parent(node_p * parent, char *arg);
void add_parent_node(node_p * parent, int id, char *element);
int check_parents(node_p * parent, int *arg[]);

#endif
