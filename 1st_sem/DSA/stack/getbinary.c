#include <stdio.h>
#include <string.h>

#define MAX 20

int top = -1;
int stack[MAX];

void push(int val){
	if(top == MAX-1)
		printf("stack is overflow.!");
	else 
		stack[++top] = val;
}

int pop(){
	if(top == -1)
		printf("stack is underflow.!");
	else 
		return stack[top--];
}

int main(){
	int num,digit;
	printf("Enter the number:");
	scanf("%d",&num);

	while (num>0){
		digit = num % 2;
		push(digit);
		num = num/2;
	}

	while (top != -1){
		printf("%d",pop());
}
