#include <stdio.h>
#include <stdint.h>
#ifndef LLIST_H 
#define LLIST_H

#include <stdlib.h>
#include "node.h"

//node structure for Linear Linked List////////////////// 

typedef struct 
{
	node * head;
	int current_size;
	int max_size;
}linearlinkedlist;


//easy 

linearlinkedlist * construct_linearlinkedlist(int max_size);
void append_node(linearlinkedlist * ll ,node * node_to_add);
void insert_node(linearlinkedlist * ll , node * node_to_insert, int position);
void pop_node(linearlinkedlist * ll );
void delete_node_by_value(linearlinkedlist * ll , int value);
void delete_node_by_position(linearlinkedlist *ll ,int position);
void traverse_linked_list(linearlinkedlist * ll);
int find_node(linearlinkedlist *ll , node * node_to_find);
void sort_list(linearlinkedlist *ll );
int get_linked_list_size(linearlinkedlist *ll);
void remove_node_by_position(linearlinkedlist *ll ,int position);
//medium

void swap_nodes(linearlinkedlist *ll ,int position_1,int position_2);
int detect_loop(linearlinkedlist * ll);
int check_palindrome(linearlinkedlist * ll);
//remove duplicate
//iterative reverse using 2 pointer
//union of 2 ll
//intersection of 2 ll 


//hard
//flattening ll
//delete nodes with grater value right side





//////////////////////////////////////////////////////////


//Tests for Linear Linked List/////////////////////////// 
linearlinkedlist * dummy_linkedlist(int size);
//easy
void test_construct_linearlinkedlist(void);
void test_append_node(void);
void test_insert_node(void);
void test_pop_node(void);
void test_delete_node_by_value(void);
void test_delete_node_by_position(void);
void test_traverse_linked_list(void);
void test_find_node(void);
void test_sort_list(void);
void test_get_linked_list_size(void);
//medium
void test_swap_nodes(void);
void test_find_loop(void);
void test_check_palindrome(void);
//////////////////////////////////////////////////////////

#endif