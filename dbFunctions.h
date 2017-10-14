#ifndef DBENGINE_FUNCTIONS_H
#define DBENGINE_FUNCTIONS_H

// Parent node, contains itemid, element(children) and pointer to next parent node
typedef struct node {
	char items[2]; 
	struct node * next;
} node_db;

int readFile(char *import[]);
void add_node(node_db * head, char *items[]);

#endif
