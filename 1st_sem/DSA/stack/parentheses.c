#include <stdio.h>
#include <string.h>
#define MAX 20

char stack[MAX];
int top = -1;

void push(char val){
	if(top == MAX-1){
		printf("stack is overflow");
	}else
		stack[++top] = val;
}

char pop(){
	if(top == -1){
		printf("stack is underflow");
		return 0;
	}else
		return stack[top--];
}


int main () {
	char str[MAX];

	printf("Eneter the expresion:");
	gets(str);
	
	int n = strlen(str);
	int i;
	for (i = 0; i < n; i++){
		if (str[i]=='(' || str[i]=='[' || str[i]=='{')
			push(str[i]);
		else if (str[i] == ')'){
			if ('(' == pop())
				continue;
			else{
				printf("not parentheses.!");
				break;
			}

		}else if (str[i] == ']'){
			if ('[' == pop())
				continue;
			else{
				printf("not parentheses.!");
				break;
			}
		}else if (str[i] == '}'){
			if('{' == pop())
				continue;
			else{
				printf("not parentheses.!");
				break;
			}
		}else 
			continue;
	}

	if (i == n)
		printf("parentheses.!");
	


	return 0;

}
