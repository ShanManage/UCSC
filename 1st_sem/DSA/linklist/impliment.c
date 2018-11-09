#include <stdio.h>
#include <stdlib.h>

int countnnode;

struct node
{
	int data;
	struct node * next;
	struct node * previous;
};

struct node * start = NULL;

struct node * creatnode(int data){
	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	newnode->previous = NULL;

	return newnode;
}

void insertbegining(int val){
	struct node * new;
	new = creatnode(val);

	if (start == NULL){
		start = new;
	}else{
		new->next = start;
		start->previous = new;
		start = new;
	}
}

void insertend(int val){
	struct node * ptr = start;
	struct node * new;
	new = creatnode(val);

	while (ptr->next != NULL){
		ptr = ptr->next;
	}

	ptr->next = new;
	new->previous = ptr;
	
}

void insertAfter(int val, int key){
	struct node * ptr = start;
	struct node * new;
	new = creatnode(val);

	while (ptr->data != key)
		ptr = ptr->next;

	new->next = ptr->next;
	new->previous = ptr;
	ptr->next->previous = new;
	ptr->next = new;
}

void insertBefor (int val, int key){
	struct node * ptr = start;
	struct node * new;
	new = creatnode(val);

	while (ptr->data != key)
		ptr = ptr->next;

	new->next = ptr;
	new->previous = ptr->previous;
	ptr->previous->next = new;
	ptr->previous = new;
}

void deletestart(){
	struct node * temp = start;
	start = start->next;
	start->previous = NULL;
	free(temp);
}

void deletelast(){
	struct node * ptr = start; 
	while(ptr->next != NULL)
		ptr = ptr->next;

	ptr->previous->next = NULL;
	free(ptr);
}

void deletenode(int key){
	struct node* ptr = start;
	while (ptr->data != key)
		ptr = ptr->next;

	struct node * temp = ptr;
	ptr->previous->next = ptr->next;
	ptr->next->previous = ptr->previous;
	free(temp);
}

void deleteAfter(int key){
	struct node * ptr = start;
	while (ptr->data != key)
		ptr = ptr->next;

	if (ptr->next->next == NULL){
		deletelast();
	} else {
		struct node * temp = ptr->next;
		ptr->next->next->previous = ptr;
		ptr->next = ptr->next->next;
		free(temp);
	}
}

void delteBefore(int key){
	struct node * ptr = start;
	while (ptr->data != key)
		ptr = ptr->next;

	if(ptr->previous == start){
		deletestart();
	} else{
		struct node * temp = ptr->previous;
		ptr->previous->previous->next = ptr;
		ptr->previous = ptr->previous->previous;
		free(temp);
	}
}

void traverse(){
	struct node * ptr = start;
	while (ptr != NULL){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int main (){

	insertbegining(20);
	insertbegining(10);
	traverse();
	insertend(30);
	insertBefor(15,20);
	traverse();
	insertAfter(25,20);
	traverse();
	insertend(90);
	insertend(50);
	traverse();
	delteBefore(15);
	traverse();
	deleteAfter(90);
	traverse();

	return 0;
}