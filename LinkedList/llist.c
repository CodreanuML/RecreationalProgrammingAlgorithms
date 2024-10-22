
#include "llist.h"
#define max_limit 32000
#define max(a,b) (((a) >= (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
//functions for Linear Linked List//////////////////////// 



//construct a linear linkedlist
linearlinkedlist * construct_linearlinkedlist(int max_size){
	linearlinkedlist * new_list = malloc(sizeof(linearlinkedlist));
	if (max_size<=-1){
	new_list->head=NULL;	
	new_list->max_size=max_limit;
	new_list->current_size=0 ;
	printf("Undefined behavior -> max limit set %d \n",max_limit);
	}
	else{
	new_list->head=NULL;
	new_list->max_size=max_size;
	new_list->current_size=0 ;

	}

	return new_list;
}


//append new node to a linear linked list
void append_node(linearlinkedlist * ll ,node * node_to_add){
	node * head=ll->head;

	if (head == NULL){
		ll->head=node_to_add;
		ll->current_size++;
		return ;
	}

	else {

		while (get_next_node(head)!=NULL){
			head=get_next_node(head);

		}
		set_next_node(head,node_to_add);
		ll->current_size++;
	}
	
	return;
}


//traverse and print all nodes of a linear linked list
void traverse_linked_list(linearlinkedlist * ll){
	node * to_traverse =ll->head;
	if (to_traverse==NULL){

		printf("Empty List\n");

	}
	else{
		while(to_traverse!=NULL){
			printf("%d\n",to_traverse->value);
			to_traverse=get_next_node(to_traverse);
		}
	}

}

//insert new node in a desired position
void insert_node(linearlinkedlist * ll , node * node_to_insert, int position){
	node *  current_node =ll->head;
	node * next_node = NULL ;
	int actual_position = 0 ;
	if (position==0 &&current_node==NULL){
			
				ll->head=node_to_insert;
				ll->current_size++;
				return;


			

	}
	
	else if (position==0 && current_node!=NULL){
		set_next_node(node_to_insert,ll->head);
		ll->head=node_to_insert;
		ll->current_size++;
		return;


	}

	else {

		while(current_node!=NULL){
			next_node=get_next_node(current_node);
			actual_position++;
			if (actual_position==position)
			{
				if (next_node==NULL){
						current_node->nextnode=node_to_insert;
						ll->current_size++;
						return;
				}
				else{
					node_to_insert->nextnode=next_node;
					current_node->nextnode=node_to_insert;
					ll->current_size++;
					return;

				}



			}
		current_node=get_next_node(current_node);
	}

	if (actual_position<position){
		printf ("Position not found");
	}


}
}

//delete last element from  a linked list 

void pop_node(linearlinkedlist * ll){
	node * current_node = ll->head;
	if (current_node==NULL){

		printf("List is empty!\n");
	}
	else if (current_node!=NULL && get_next_node(current_node)==NULL){
		free(ll->head);
		printf("Now list is empty!\n");
		ll->current_size-=1 ;
	}
	else{
		while(get_next_node(get_next_node(current_node))!=NULL){
			current_node=get_next_node(current_node);
		}
		free(get_next_node(current_node));
		current_node->nextnode=NULL;
		ll->current_size-=1;
		


	}

}


//delete node by value

void delete_node_by_value(linearlinkedlist * ll , int value){
		node * current_node = ll->head;
		node * temp=NULL;
		if (value==current_node->value){
			printf("Node deleted - > HEAD\n");
			ll->head=get_next_node(ll->head);
			free(current_node);
			ll->current_size-=1;
			return ;
		}
		else{
			while(get_next_node(current_node)!=NULL){
					if (get_next_node(current_node)->value==value){
						temp=get_next_node(current_node);
						set_next_node(current_node,get_next_node(get_next_node(current_node)));
						free(temp);
						printf("Node deleted\n");
						ll->current_size-=1;
						return ;
 
					}
					current_node=get_next_node(current_node);

			}
		printf("Node not found !");

		}
 
}

//delete node by position

void delete_node_by_position(linearlinkedlist *ll ,int position){
	node * current_node = ll->head;
	int current_position=0;
	node * temp=NULL;
	if (position==0){
		printf("Node deleted -> HEAD \n");
		ll->head=get_next_node(ll->head);
		free(current_node);
		return;

	}
	else{
		while(get_next_node(current_node)!=NULL){

					if (current_position+1==position){
						temp=get_next_node(current_node);
						set_next_node(current_node,get_next_node(get_next_node(current_node)));
						free(temp);
						printf("Node deleted\n");
						ll->current_size-=1;
						return ;
 
					}
					current_node=get_next_node(current_node);
					current_position++;

			}
		printf("Node not found !");		

	}


}



//remove node by position

void remove_node_by_position(linearlinkedlist *ll ,int position){
	node * current_node = ll->head;
	int current_position=0;
	node * temp=NULL;
	if (position==0){
		printf("Node deleted -> HEAD \n");
		ll->head=get_next_node(ll->head);
		//free(current_node);
		return;

	}
	else{
		while(get_next_node(current_node)!=NULL){

					if (current_position+1==position){
						temp=get_next_node(current_node);
						set_next_node(current_node,get_next_node(get_next_node(current_node)));
						//free(temp);
						printf("Node deleted\n");
						ll->current_size-=1;
						return ;
 
					}
					current_node=get_next_node(current_node);
					current_position++;

			}
		printf("Node not found !");		

	}


}




//function used to find a node 
int find_node(linearlinkedlist *ll , node * node_to_find){
		node * current_node = ll->head;
		int current_position = 0;
		while(current_node!=NULL){
				if(current_node->value==node_to_find->value)
				{
					printf("Node found on position %d " ,current_position);

					return  current_position ;
				}


				current_node=get_next_node(current_node);
				current_position++;

			}
		printf("Node not found !");		

		return -1;
}

//function to sort a linked list keeping all nodes alive 

void sort_list(linearlinkedlist *ll ){
 node * smallest_node = NULL ;
 node * new_head=NULL;
 node *temp_head=NULL;
 int size = 0;

node * current_node= ll->head;


while(current_node!=NULL){
smallest_node=current_node;

 while(current_node!=NULL){
 	
 	if (current_node->value<smallest_node->value){
 		smallest_node=current_node;

 	}
 	current_node=get_next_node(current_node);


 }
 node* created=construct_node_by_val(smallest_node->value);
 if (new_head == NULL){
	new_head=created;
	printf("second");
	delete_node_by_value(ll,smallest_node->value);

	}

	else {
		temp_head=new_head;
		while (get_next_node(temp_head)!=NULL){
			temp_head=get_next_node(temp_head);

		}
		
		set_next_node(temp_head,created);
		size++;
		delete_node_by_value(ll,smallest_node->value);
	}
	



current_node=ll->head;
}

ll->head=new_head;
ll->current_size=size;
}



//function to sort a linked list keeping all nodes alive 

int get_linked_list_size(linearlinkedlist *ll){

	return(ll->current_size);
}


//function to swap a linked list keeping all nodes alive 
void swap_nodes(linearlinkedlist *ll ,int position_1,int position_2){

	if(max(position_1,position_2)>ll->current_size){
		printf("Cannot swap these two nodes because the position selected exceed ll size");

	}
	else{
		node * current_node=ll->head;
		
		int position_min =min(position_1,position_2);
		int position_max =max(position_1,position_2);

		node * node_position_min;
		node * node_position_max;

		int current_position=0;
		//get min / max node
		while(current_position<position_max){

			if(current_position==position_min){
				node_position_min=current_node;


			}
			current_node=get_next_node(current_node);
			current_position++;

		}

		node_position_max = current_node ;


		remove_node_by_position(ll,position_min);
		remove_node_by_position(ll,position_max-1);

		printf("%d caca",node_position_max->value);
		insert_node(ll,node_position_min,position_max-1);
		insert_node(ll,node_position_max,position_min);



	}

}

//function used to detect loop in linked list 
//Floyd's Cycle-Finding Algorithm
int detect_loop(linearlinkedlist * ll){

	node * slow_pointer = ll->head;
	node * faster_pointer=ll->head;

	while(slow_pointer!=NULL && faster_pointer!=NULL && get_next_node(faster_pointer)){
		slow_pointer=get_next_node(slow_pointer);
		faster_pointer=get_next_node(get_next_node(faster_pointer));


		if (slow_pointer==faster_pointer){

			return 1 ;
	}
		



	}

	return 0 ;



}

//function used to detect if a linked list is palindrome 
//using stack
int check_palindrome(linearlinkedlist * ll){
	node *current_pointer = ll->head;


	node * free_pointer ;
	
	node * stack_head;

	stack_head=NULL;

	while(current_pointer!=NULL){
		node * temp=malloc(sizeof(node));
		temp->value=current_pointer->value;

		if(stack_head==NULL){
			stack_head=temp;

		}


		else{
			
			
			
			set_next_node(temp,stack_head);
			stack_head=temp;


		}

		
		current_pointer=get_next_node(current_pointer);
		
	}




	node * current_stack=stack_head;
	node * current_linked=ll->head;


	while(current_stack && current_linked){

		if (current_stack->value!=current_linked->value)
		{
			return 0 ;
		}
	

		
		current_stack=get_next_node(current_stack);
		current_linked=get_next_node(current_linked);
	}
	return 1;



}

//////////////////////////////////////////////////////////


//tests for Linear Linked List//////////////////////// 

//function used to generate a dummy_linked list
//size parameter is the size of current nodes in linked list
//the size will be maxsize 
linearlinkedlist * dummy_linkedlist(int size){
	linearlinkedlist * dummy =construct_linearlinkedlist(-1);
	for (int i=0;i<size;i++){
		node * temp =construct_node_by_val(i) ;
		append_node(dummy,temp);

	}

	return dummy;

}




//function used to test construction of a linearlinkedlist
void test_construct_linearlinkedlist(){
	printf("Test construct_linearlinkedlist started ! \n ");
	printf("Test case 1 - defined behavior size 20 started! \n");
	linearlinkedlist * ll=construct_linearlinkedlist(20);
	if (ll->max_size==20 && ll->current_size==0){
		printf("Test Step Passed \n");
	}
	else {
		printf("Test Step Failed !\n");
	}


	printf("Test case 2 - undefined behavior size negative -20 \n");
	ll=construct_linearlinkedlist(-20);
	if (ll->max_size==max_limit && ll->current_size==0){
		printf("Test Step Passed \n");
	}
	else{
		printf("Test Step Failed\n");

	}
	free(ll);
}

//function used to test append of a new node to linearlinkedlist
void test_append_node(){
	printf("Test test_test_append_node started \n");

	printf("Test case 1 - head is null \n");
	linearlinkedlist * ll =construct_linearlinkedlist(20);
	node * node1 =construct_node_by_val(10);
	append_node(ll,node1);
	if (ll->head->value==node1->value){
		printf("Test step Passed \n");
	}
	else {
		printf("Test Step Failed \n");
	}
	

	printf("Test case 2 - head is not  null \n");

	for (int i=9;i>=0;i--){
		node1=construct_node_by_val(i);
		append_node(ll,node1);

	}

	int dummy=10 ;
	while(ll->head!=NULL){
		node * temp ;
		if (ll->head->value!=dummy){
			printf("Test step Failed \n");

			break;

		}

		temp=ll->head;
		ll->head=get_next_node(ll->head);
		free(temp);
		dummy--;
}

	printf("Test Step Passed \n");
}

//function used to test insertion of a new node in a linearlinkedlist
void test_insert_node(void){

	printf("Test test_insert_node! \n ");

	printf("-------------- Created new linked list \n");
	linearlinkedlist* test=dummy_linkedlist(0);


	printf("Test case 1 - defined behavior insert head - empty head \n");
	traverse_linked_list(test);
	node * inserted_node =construct_node_by_val(20);
	insert_node(test,inserted_node,0);
	printf("---------------Expected list \n");
	traverse_linked_list(test);

	printf("Test case 1 - defined behavior insert head -  head on  place \n");
	traverse_linked_list(test);
	inserted_node =construct_node_by_val(24);
	insert_node(test,inserted_node,0);
	printf("---------------Expected list \n");
	traverse_linked_list(test);



	printf("Test case 3- defined behavior insert node after head \n");
	traverse_linked_list(test);
    inserted_node = construct_node_by_val(21);
    insert_node(test,inserted_node,1);
	printf("---------------Expected list \n");
	traverse_linked_list(test);

	printf("Test case 4 - defined behavior insert node after head and before second node \n");
	traverse_linked_list(test);
    inserted_node = construct_node_by_val(22);
    insert_node(test,inserted_node,1);
	printf("---------------Expected list \n");
	traverse_linked_list(test);



	linearlinkedlist * test2=dummy_linkedlist(10);

	printf("Test case 5 - defined behavior insert node  pos 5 \n");
	traverse_linked_list(test2);
    inserted_node = construct_node_by_val(40);
    insert_node(test2,inserted_node,5);
	printf("---------------Expected list \n");
	traverse_linked_list(test2);


}

//function used to test deletion of a new node in a linearlinkedlist
void test_pop_node(void){
	printf("Test test_pop_node! \n ");

	printf("-------------- Created new linked list \n");
	linearlinkedlist* test=dummy_linkedlist(0);


	printf("Test case 1 - defined behavior delete head - empty head \n");
	traverse_linked_list(test);
	pop_node(test);

	linearlinkedlist * test2=dummy_linkedlist(1);
	printf("Test case 2 - defined behavior delete head - head present \n");
	traverse_linked_list(test2);
	pop_node(test2);


	linearlinkedlist * test3=dummy_linkedlist(10);
	printf("Test case 3 - defined behavior delete node - last node\n");
	traverse_linked_list(test3);
	pop_node(test3);
	traverse_linked_list(test3);
}


//function used to test deletion of a new node in a linearlinkedlist
void test_delete_node_by_value(void){
	int err = 0; 
	printf("Test test_delete_node_by_value! \n ");

	printf("-------------- Created new linked list \n");
	linearlinkedlist* test=dummy_linkedlist(10);

	printf("Test case 1 - defined behavior delete head  \n");
	traverse_linked_list(test);
	delete_node_by_value(test,0);
	if(test->head->value==0){
		printf("Test Step Failed\n");
	}
	else{
		printf("Test Step Passed\n");
	}


	printf("Test case 2 - defined behavior delete node  \n");
	traverse_linked_list(test);
	delete_node_by_value(test,5);
	node * dummy =test->head;
	while(dummy!=NULL){
		if (dummy->value==5){
			printf("Test Step Failed");
			err=1;
			return ;
		}
		dummy=get_next_node(dummy);
	}
	if (err==0){
		printf("Test Step Passed");
	}



}


//function used to test deletion of a new node in a linearlinkedlist
void test_delete_node_by_position(void){
	int err = 0; 
	printf("Test test_delete_node_by_position! \n ");

	printf("-------------- Created new linked list \n");
	linearlinkedlist* test=dummy_linkedlist(10);

	printf("Test case 1 - defined behavior delete head  \n");
	traverse_linked_list(test);
	delete_node_by_value(test,0);
	if(test->head->value==0){
		printf("Test Step Failed\n");
	}
	else{
		printf("Test Step Passed\n");
	}


	printf("Test case 2 - defined behavior delete node  \n");
	traverse_linked_list(test);
	delete_node_by_value(test,5);
	node * dummy =test->head;
	while(dummy!=NULL){
		if (dummy->value==5){
			printf("Test Step Failed");
			err=1;
			return ;
		}
		dummy=get_next_node(dummy);
	}
	if (err==0){
		printf("Test Step Passed\n");
	}
	traverse_linked_list(test);



}


//function used to test deletion of a new node in a linearlinkedlist
void test_find_node(void){
	int err = 0; 
	printf("Test test_find_node! \n ");
	node * dummy1 = construct_node_by_val(2);
	node * dummy2= construct_node_by_val(-12);
	printf("-------------- Created new linked list \n");
	linearlinkedlist* test=dummy_linkedlist(10);

	printf("Test case 1 - find valid node \n");
	traverse_linked_list(test);
	if(find_node(test,dummy1)==-1){
		printf("Test Step Failed\n");
	}
	else{
		printf("Test Step Passed\n");
	}


	printf("Test case 2 - find invalid node   \n");
	if(find_node(test,dummy2)==-1){
		printf("Test Step Failed\n");
	}
	else{
		printf("Test Step Passed\n");
	}



}




//function used to test linkedlist sorting
void test_sort_list(void){
	printf("Test test_sort_list! \n ");
	printf("-------------- Created new linked list \n");
	linearlinkedlist* test=malloc(sizeof(linearlinkedlist));
	node * node1=construct_node_by_val(10);
	node * node2=construct_node_by_val(5);
	node * node3=construct_node_by_val(22);
	node * node4=construct_node_by_val(3);
	node * node5=construct_node_by_val(2);
	node * node6=construct_node_by_val(11);
	node * node7=construct_node_by_val(4);
	node * node8=construct_node_by_val(100);
	node * node9=construct_node_by_val(8);
	node * node10=construct_node_by_val(121);


	
	append_node(test,node1);
	append_node(test,node2);
	append_node(test,node3);
	append_node(test,node4);
	append_node(test,node5);
	append_node(test,node6);
	append_node(test,node7);
	append_node(test,node8);
	append_node(test,node9);
	append_node(test,node10);

	printf("Unsorted \n");
	traverse_linked_list(test);

	sort_list(test);
	printf("Sorted\n");
	traverse_linked_list(test);


}

//function used to test size of linked list

void test_get_size_list(void){
	printf("Test test_get_size \n ");
	printf("-------------- Created new linked list \n");
	linearlinkedlist* test=malloc(sizeof(linearlinkedlist));
	node * node1=construct_node_by_val(10);
	node * node2=construct_node_by_val(5);
	node * node3=construct_node_by_val(22);
	node * node4=construct_node_by_val(3);
	node * node5=construct_node_by_val(8);


	
	append_node(test,node1);
	append_node(test,node2);
	append_node(test,node3);
	append_node(test,node4);
	insert_node(test,node5,0);
	int size =0;
	traverse_linked_list(test);
	size=get_linked_list_size(test);
	
	if (size==5){
		printf("Test Step Passed\n");
		printf("%d",size);

	}
	else{
		printf("Test Step Failed\n");
		printf("%d",size);
	}


}


//function used to test swapping of two nodes


void test_swap_nodes(void){

	printf("Test test_swap_nodes \n ");
	printf("-------------- Created new linked list \n");
	linearlinkedlist * test=dummy_linkedlist(10);
	traverse_linked_list(test);
	swap_nodes(test,0,22);
	printf("Nodes swaped!\n");
	traverse_linked_list(test);

}


//function used to detect loop

void test_find_loop(void){
	printf("Test test_swap_nodes \n ");
	printf("-------------- Created new linked list \n");
	
	node * node1=construct_node_by_val(10);
	node * node2=construct_node_by_val(5);
	node * node3=construct_node_by_val(22);
	node * node4=construct_node_by_val(3);
	node * node5=construct_node_by_val(8);

	linearlinkedlist * test = construct_linearlinkedlist(10);
	
	append_node(test,node1);
	append_node(test,node2);
	append_node(test,node3);
	append_node(test,node4);
	insert_node(test,node5,0);
	set_next_node(node4,node3);
	int size =0;
	//traverse_linked_list(test);

	printf("\n");
	int result =detect_loop(test);
	printf("result is %d \n" ,result);
}




//function used to check palindrome
void test_check_palindrome(void){
	printf("Test test_check_palindrome \n ");
	printf("-------------- Created a new palindrome linked list \n");
	

	node * node1=construct_node_by_val(1);
	node * node2=construct_node_by_val(2);
	node * node3=construct_node_by_val(2);
	node * node4=construct_node_by_val(2);
	node * node5=construct_node_by_val(1);

	linearlinkedlist * test = construct_linearlinkedlist(5);
	
	append_node(test,node1);
	append_node(test,node2);
	append_node(test,node3);
	append_node(test,node4);
	append_node(test,node5);

	printf("-------------- Traversarea listei  \n");

	traverse_linked_list(test);

	printf("-------------- Test Step Verificare Palindrome  \n");

	if(check_palindrome(test)){
		printf("Test step passed");
	}
	else {
		printf("Test step failled !");
	}




	printf("-------------- Created a new non palindrome linked list \n");
	

	node * node11=construct_node_by_val(1);
	node * node21=construct_node_by_val(3);
	node * node31=construct_node_by_val(2);
	node * node41=construct_node_by_val(2);
	node * node51=construct_node_by_val(1);

	linearlinkedlist * test1 = construct_linearlinkedlist(5);
	
	append_node(test1,node11);
	append_node(test1,node21);
	append_node(test1,node31);
	append_node(test1,node41);
	append_node(test1,node51);

	printf("-------------- Traversarea listei  \n");

	traverse_linked_list(test1);

	printf("-------------- Test Step Verificare Palindrome  \n");

	if(check_palindrome(test1)){
		printf("Test step passed");
	}
	else {
		printf("Test step failled !");
	}
	
}


//////////////////////////////////////////////////////////