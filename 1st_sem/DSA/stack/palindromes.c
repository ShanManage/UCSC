#include <stdio.h>
#include <string.h>

#define MAX 20

int top = -1;
char stack[MAX];

void push(char val){
	if (top == MAX-1)
		printf("stack is overflow.!");
	else 
		stack[++top] = val;
}

char pop(){
	if(top == -1)
		printf("stack is underflow..!");
	else
		return stack[top--];
}

int main(){
	char arr[50];
	printf("Enter the string:");
	gets(arr);

	for (int i = 0; i < strlen(arr); i++)
		push(arr[i]);

	int j = 0;
	for (int i = 0; i < strlen(arr); i++){
		j = j + 1;
		if(arr[i] != pop()){
			printf("its not palindrome.!");
			break;
		}else{
			if(j == strlen(arr))
				printf("its palindrome.!");
		}
	}
}
		