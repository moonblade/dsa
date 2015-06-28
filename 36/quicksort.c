/*
	Ex No.24
	Implementation of quicksort recursively and non-recursively
	S4R 036 Mohamed Insaf K
	31/03/2015
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void quickSort(int A[], int start, int end);
void quickSortIterative(int A[], int start, int end);
int partition(int [], int, int);
void swap(int *, int *);
void display(int [], int);
void read(int [], int *);
int tsize;
int main(void)
{
	int A[MAX];
	int choice, size;
	while(1)
	{
		printf("Quicksort:\n\t1. Recursive \n\t2. Non-Recurise\n\t3. Exit\n\tPlease Choose: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter size of the list: ");
				read(A, &size);
				tsize = size;
				printf("Intermediate Steps: \n");
				quickSort(A, 0, size-1);
				printf("Sorted List is: ");
				display(A, size);
				break;
			case 2:
				printf("Enter size of the list: ");
				read(A, &size);
				tsize = size;
				printf("Intermediate Steps: \n");
				quickSortIterative(A, 0, size-1);
				printf("Sorted List is: ");
				display(A, size);
				break;
			case 3:
				return 0;
				break;
			default:
				printf("Wrong option please try again\n");
				break;
		}
	}
	return 0;
}

void quickSort(int A[], int start, int end)
{
	int pIndex;
	if( start < end)
	{
		pIndex = partition(A, start, end);
		display(A, tsize);
		quickSort(A, start, pIndex - 1);
		quickSort(A, pIndex + 1, end);
	}
}

int partition(int A[], int start, int end)
{
	//Last element is taken as the pivot
	int i, pivot, pIndex = 0;
	pivot = A[end];
	for(i=0; i < end; i++)
	{
		if(A[i] <= pivot)
		{
			swap( &A[i], &A[pIndex]);
			pIndex++;
		}
	}
	swap( &A[pIndex], &A[end]);
	return pIndex;
}

void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void quickSortIterative(int A[], int start, int end)
{
	int pIndex, top = -1;
	int *stack;
	stack = (int *)malloc( sizeof(int)*(end-start+1) );
	stack[++top] = start;
	stack[++top] = end;
	while(top>=0)
	{
		end = stack[top--];
		start = stack[top--];

		pIndex = partition(A, start, end);
		display(A, tsize);
		if(pIndex - 1> start)
		{
			stack[++top] = start;
			stack[++top] = pIndex - 1;
		}
		if(pIndex + 1 < end)
		{
			stack[++top] = pIndex + 1;
			stack[++top] = end;
		}
	}
}

void read(int A[], int *size)
{
	int i;
	printf("Enter size: ");
	scanf("%d", size);
	printf("Enter elements one by one\n");
	for(i=0; i < *size; ++i)
		scanf("%d", &A[i]);
}

void display(int A[], int size)
{
	int i;
	for(i=0; i < size; ++i)
		printf("%d, ", A[i]);
	printf("\n");
}

/*		SAMPLE OUTPUT

Quicksort:
	1. Recursive 
	2. Non-Recurise
	3. Exit
	Please Choose: 1
Enter size of the list: Enter size: 7
Enter elements one by one
6 1 9 2 3 4 7 
Intermediate Steps: 
6, 1, 2, 3, 4, 7, 9, 
1, 2, 3, 4, 6, 7, 9, 
1, 2, 3, 4, 6, 7, 9, 
1, 2, 3, 4, 6, 7, 9, 
Sorted List is: 1, 2, 3, 4, 6, 7, 9, 
Quicksort:
	1. Recursive 
	2. Non-Recurise
	3. Exit
	Please Choose: 2
Enter size of the list: Enter size: 7
Enter elements one by one
6 1 9 2 3 4 7 
Intermediate Steps: 
6, 1, 2, 3, 4, 7, 9, 
1, 2, 3, 4, 6, 7, 9, 
1, 2, 3, 4, 6, 7, 9, 
1, 2, 3, 4, 6, 7, 9, 
Sorted List is: 1, 2, 3, 4, 6, 7, 9, 
Quicksort:
	1. Recursive 
	2. Non-Recurise
	3. Exit
	Please Choose: 3

*/
