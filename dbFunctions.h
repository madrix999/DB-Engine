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


void print_parent(node_p * parent, node_c * child);
void add_parent_node(node_p * parent, int id, char *element);
void add_child(node_c * child, int var, char *element, int itemid, int parentid);
void init(node_p * parent, node_c * child);
int commands(char *cmd, node_p * parent, node_c * child);
int check_parents(node_p * parent, char *arg);
char *input();

void cmdParent(node_p * parent);
void cmdChild(node_c * child);

#endif
