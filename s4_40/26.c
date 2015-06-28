/*
BINU S
ROLL NO.: 64
EXPERIMENT NO.: 26
DATE: 26-03-2015
HEAP SORT
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

void heapsort(int arr[], int n);
void maxheapify(int arr[], int n, int i);
void buildheap(int arr[], int n);

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

	heapsort(arr, n);

	printf("THE SORTED LIST IS: ");
	for(i=0; i!=n; ++i)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
 }

void heapsort(int arr[], int n)
 {
	buildheap(arr, n);
	int temp;
	int sz=n-1;

	temp=arr[n-1];
	arr[n-1]=arr[0];
	arr[0]=temp;

	while(sz!=1)
	 {
		maxheapify(arr, sz, 0);
		temp=arr[sz-1];
		arr[sz-1]=arr[0];
		arr[0]=temp;

		sz--;
	 }
 }

void maxheapify(int arr[], int n, int i)
 {
	int maxpos=i;
	int lc= 2*i+1;
	int rc= 2*i+2;

	if(lc<n)
		if(arr[lc]>arr[maxpos])
			maxpos=lc;
	if(rc<n)
		if(arr[rc]>arr[maxpos])
			maxpos=rc;

	if(maxpos!=i)
	 {
		int temp=arr[maxpos];
		arr[maxpos]=arr[i];
		arr[i]=temp;

		maxheapify(arr, n, maxpos);
	 }
 }

void buildheap(int arr[], int n)
 {
	int i, j;

	for(i= n/2 -1; i!=-1; --i)
		maxheapify(arr, n, i);
 }
