/*
	NAME    :- HARSH KUMAR
	SRN     :- PES1UG19EE038
	PESU ID :- PES1201900555
*/



#include "poly.h"
void insert_at_end(List *list, int data) 
{
	//TODO
	Node* newNode = (Node*)malloc(sizeof(Node));

	/*Memory not available on heap.*/
	if(newNode == NULL){
		return;
	}

	/*No. of nodes in list is 0.*/
	if(list->number_of_nodes == 0){
		newNode->data = data;
		newNode->link = NULL;
		list->head = newNode;
	}

	else{
		Node* temp = list->head;
		while(temp->link != NULL){
			temp = temp->link;
		}
		newNode->data = data;
		newNode->link = NULL;
		temp->link = newNode;
	}
	list->number_of_nodes++;
}

long long int evaluate(List *list, int x)
{
    //TODO
	Node* temp = list->head;
	int var = 1;
	long long int res = 0;
	while(temp!=NULL){
		res+=(temp->data*var);
		var*=x;
		temp=temp->link;
	}
	return res;
}
