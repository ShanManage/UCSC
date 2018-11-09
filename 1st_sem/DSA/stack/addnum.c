#include <stdio.h>
#include <stdlib.h>

struct stack {
	int MAX;
	int *arr;
	int top;
};
typedef struct stack Stack;

Stack * createStack (int MAX){
	Stack *new = malloc(sizeof(Stack));
	new->MAX = MAX;
	new->arr = malloc(sizeof(int)*MAX);
	new->top = -1;

	return new;
}

void push (Stack* q, int val){
	if(q->top == q->MAX-1)
		printf("this stack is overflow..!");
	else
		q->arr[++q->top] = val;
}

int pop(Stack* q){
	if(q->top == -1)
		printf("this stack is underflow..!");
	else
		return q->arr[q->top--];
}

int main(){

	int cap1, cap2;
	printf("s%c s%c capasity :",'1','2');
	scanf("%d %d",&cap1,&cap2);

	Stack *s1 = createStack(cap1);
	Stack *s2 = createStack(cap2);

	Stack *s3 = createStack((cap1+cap2+1)/2);

	char num1[cap1];
	char num2[cap2];
	printf("Enter num1:\n");
	gets(num1);
	printf("Enter num2:");
	gets(num2);
	
	for (int i = 0; i<cap1; i++){
		push(s1,num1[i]);
	}

	for (int i = 0; i<cap2; i++){
		push(s2,num2[i]);
	}


	return 0;
}