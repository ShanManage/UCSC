#include <stdio.h>

int arr[10],n;

int main (){

	printf("Enter the number of element in the array:");
	scanf("%d",&n);

	for (int i = 0; i < n; i++)
	{
		printf("Enter the element %d:", i+1);
		scanf("%d",&arr[i]);
	}

	printf("normal array:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ",arr[i]);
	}

	printf("\nreverse array:\n");
	for (int i = n-1; i >= 0; --i)
	{
		printf("%d ",arr[i]);
	}
}


