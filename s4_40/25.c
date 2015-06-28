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

void mergesort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

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

	mergesort(arr, 0, n-1);

	printf("THE SORTED LIST IS: ");
	for(i=0; i!=n; ++i)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
 }

void mergesort(int arr[], int l, int r)
 {
	if(r<=l)	return;

	int mid = (l+r)/2;
	mergesort(arr, l, mid);
	mergesort(arr, mid+1, r);

	merge(arr, l, mid, r);
 }

void merge(int arr[], int l, int m, int r)
 {
	int temp[MAX];
	int i=l, j=m+1, k=0;

	while((i<=m)&&(j<=r))
	 {
		if(arr[i]<arr[j])
		 {
			temp[k]=arr[i];
			++i;
			++k;
		 }
		else
		 {
			temp[k]=arr[j];
			++j;
			++k;
		 }
	 }

	while(i<=m)
	 {
		temp[k]=arr[i];
		++i;
		++k;
	 }
	while(j<=r)
	 {
		temp[k]=arr[j];
		++j;
		++k;
	 }

	for(i=0; i!=k; ++i)
	 {
		arr[l+i]=temp[i];
	 }
 }
