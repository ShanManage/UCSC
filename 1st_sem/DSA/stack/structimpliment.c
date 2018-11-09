#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct structstack{
	int stack[MAX];
	int top ; 
};typedef struct structstack stack;

stack * createstack (){
	stack * new = malloc(sizeof(stack));
	new->top = -1;
	return new;
}

void push(int val, stack * q){
	if(q->top == MAX-1){
		printf("Stack is overflow");
	}else
		q->stack[++q->top] = val;
}

int pop (stack * q){
	if(q->top == -1){
		printf("Stack is Underflow.!");
		return 0;
	}else 
		return q->stack[q->top--];
}

int main (){
	stack * s1 = createstack();
	stack * s2 = createstack();

	push(10,s1);
	push(15,s2);
}


