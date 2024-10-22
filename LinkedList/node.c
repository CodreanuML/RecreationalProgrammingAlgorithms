#include "node.h"

//node structure for Linear Linked List////////////// 

node * construct_node() {
	node * temp_node = (node*)malloc(sizeof(node));
	temp_node->value=0;
	temp_node->nextnode=NULL;
	
	return temp_node;

}



void set_node_value(node * node_to_set,int value){
	node_to_set->value=value ;
}

node *construct_node_by_val(int val){
	node * temp_node=construct_node();
	set_node_value(temp_node,val);
	return temp_node;

}


 int get_node_value(node * node){
 	return node->value;
 }

void set_next_node(node * node_from,node * node_to){
	node_from->nextnode=node_to;
}

node * get_next_node(node * node){
	return node->nextnode;
}
//////////////////////////////////////////////////////////