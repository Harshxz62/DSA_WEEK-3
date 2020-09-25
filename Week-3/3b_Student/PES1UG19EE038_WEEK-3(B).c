/*
	
	NAME 	:- HARSH KUMAR
	SRN  	:- PES1UG19EE038
	PESU ID :- PES1201900555
*/


#include"dll.h"
int count_nodes(List* dll)
{
	//TODO
	int count = 0;
	Node* temp = dll->head;
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

void insert_front(List* dll, int data)
{
    //TODO
    Node* newNode = create_node(data);
    if(dll->head == NULL){
    	newNode->next = NULL;
    	dll->head = newNode;
    	dll->tail = newNode;
    }
    else{
    	newNode->next = dll->head;
    	newNode->next->prev = newNode;
    	dll->head = newNode;
    }
    dll->number_of_nodes++;
}


void dllist_delete_beginning(List* list)
{
    //TODO
    /*If List is already Empty.*/
    if(list->head == NULL){
    	return;
    }
    else{
    	Node* temp = list->head;
    	if(list->head == list->tail){
    		list->head = NULL;
    		list->tail = NULL;
    	}
    	else{
    		list->head = list->head->next;
    		list->head->prev = NULL;
    	}
    	free(temp);
    }
    list->number_of_nodes--;
}


void position_delete(List* dll, int pos)
{
    //TODO
    /*0 based indexing.*/
    if(dll->number_of_nodes == 0){
    	return;
    }
    else if(pos > dll->number_of_nodes-1){
    	return;
    }
    else{
    	Node* temp = NULL;
    	Node* trav = dll->head;
    	Node* prev = NULL;
    	int i=0;
    	while(i<pos){
    		prev = trav;
    		trav=trav->next;
    		i++;
    	}
    	if(prev == NULL){
    		dllist_delete_beginning(dll);
    	}
    	else{
	    	temp = trav;
	    	prev->next = trav->next;
	    	if(prev->next != NULL){
	    		trav->next->prev = prev;
	    	}
	    	free(temp);
	    	dll->number_of_nodes--;
	    }	
    }
}

int search_list(List* dll,int key)
{
    //TODO
    int i=0;
    Node* temp = dll->head;
    while(temp!=NULL && temp->data != key){
    	temp=temp->next;
    	i++;
    }
    if(temp==NULL){
    	return -1;
    }
    else{
    	return i;
    }
}


void reverse_list(List* dll)
{
    //TODO
	Node *temp = NULL;  
    Node *current = dll->head;  
      
    /* swap next and prev for all nodes of  
    doubly linked list */
    while (current != NULL)  
    {  
        temp = current->prev;  
        current->prev = current->next;  
        current->next = temp;              
        current = current->prev;  
    }  
      
    /* Before changing the head, check for the cases like empty  
        list and list with only one node */
    if(temp != NULL ) {
    	dll->tail = dll->head;
    	dll->head = temp->prev; 
    }  
}


