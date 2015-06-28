/*
	Ex No. 25
	Implement mergesort recursively and non-recursively
	S4R 036 Mohamed Insaf K
	31/03/15
*/

#include <stdio.h>

#define MAX 100
void MergeSort(int [], int, int);
void Merge(int [], int, int, int);
void MergeSortIterative(int [], int , int );

int main()
{
        int A[MAX], size, i;
        printf("Enter number of elements: ");
        scanf("%d", &size);
        printf("Enter elements: ");
        for(i=0; i<size; ++i)
                scanf("%d", &A[i]);
        MergeSort(A, 0, size - 1);
        printf("Sorted list is: ");
        for(i=0; i<size; ++i)
                printf("%d, ", A[i]);
	printf("\n");
        return 0;
}

void MergeSort(int A[], int l, int h)
{
	int m;
	if( l>=h )
		return;
	m = (l+h)/2;
	MergeSort(A, l, m);
	MergeSort(A, m+1, h);
	printf("\nCalling Merge(A, %d, %d, %d)", l, m, h);
	Merge(A, l, m, h);
}

void Merge(int A[], int l, int m, int h)
{
	int i, j, k, C[100];
	for( i=l, k=0, j=m+1; i<=m && j<=h; k++)
		if(A[i] <= A[j])
			C[k] = A[i++];
		else
			C[k] = A[j++];
	while(i<=m)
		C[k++] = A[i++];
	while(j<=h)
		C[k++] = A[j++];
	for(i=l, k=0; i<=h; ++i, ++k)
		A[i] = C[k];
}

void MergeSortIterative(int A[], int l, int h)
{
	int i;
	for(i = h; i <= h; ++i)
		Merge(A, i, i, i+1);
}
