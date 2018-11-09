#include <stdio.h>

#define MAX 20

int stack[MAX], top = -1;

void push(int val){
	if(top == MAX-1){
		printf("stack is overflow");
		return 0;
	}else
		stack[++top] = val;
}

void pop(){
	if(top == -1){
		printf("stack is underflow");
		return 0;
	}else
		return stack[top--];
}

void peek(){
	if (top == -1){
		printf("stack is empty");
		return 0;
	}else
		return stack[top];
}

int main () {

	return 0;

}
