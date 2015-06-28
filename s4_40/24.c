/*
BINU S
ROLL NO.: 64
EXPERIMENT NO.: 25
DATE: 26-03-2015
MERGE SORT
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

void quicksort(int arr[], int l, int r);

int main()
 {
	int arr[MAX];
	int n;
	int i;

	printf("ENTER THE NUMBER OF ELEMENTS: ");
	scanf("%d", &n);

	printf("ENTER THE ELEMENTS: ");
	for(i=0; i!=n; i++)
	 {
		scanf("%d", &arr[i]);
	 }

	quicksort(arr, 0, n-1);

	printf("THE SORTED LIST IS: ");
	for(i=0; i!=n; ++i)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
 }

void quicksort(int arr[], int l, int r)
 {
	int key=arr[l];
	int i=l, j=r+1;

	while(i
 }
