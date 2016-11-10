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
	int parentid;
	int itemid;
	struct parent * parent;
	struct child * next;
	char *element[];
} node_c;

//void exit();
void print_parent(node_p * parent, node_c * child, int id);
void add_parent_node(node_p * parent, int id, char *element[]);
//void add_child(node_c * child, node_p * parent, int var, char *arg, int itemid, int parentid);

//void add_child_to_parent(node_p * parent, node_c * child);

/*int check_parents(node_p * parent, char *arg[]);*/

#endif
