#ifndef NODE_H 
#define NODE_H



#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


//node structure for Linear Linked List////////////////// 

typedef struct 
{
	int value ;
	struct node * nextnode ;
}node;




node * construct_node(void);
node * construct_node_by_val(int val);
void set_node_value(node * node_to_set,int value);
int get_node_value(node * current_node);
void set_next_node(node * node_from,node * node_to);
node * get_next_node(node * node);


//////////////////////////////////////////////////////////





#endif