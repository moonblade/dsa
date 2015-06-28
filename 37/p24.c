/*
Exp no.24
Program to implement quick sort
S4-R-037 mohammed jasim e
30-03-2015
*/

#include<stdio.h>
#define MAX 100
void quickSort1(int[],int,int);
void quickSort2(int[],int);
int l;
int main(){


	int i,n,a[MAX],c;
	printf("\nEnter no. of values : ");
	scanf("%d",&n);
	printf("\nEnter values : ");
	for(i=0;i<n;i++) scanf("%d",a+i);
	l=n;
	printf("1. Recursive\n2. Non Recursive\nEnter choice : ");
	scanf("%d",&c);
	for(i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
	if(c==1)
		quickSort1(a,0,n-1);
	else
		quickSort2(a,n-1);
	printf("\nSorted List : ");
	for(i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}

void quickSort1(int a[],int start,int end){

	int i=start,j=end,p=start,t;

	if(start>=end)
		return;

	while(i<j){
		while(a[i]<a[p]&&i<=end) i++;
		while(a[j]>a[p]&&j>=0) j--;
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;

		}
		for(t=0;t<l;t++) printf("%d ",a[t]);
		printf("\n");
	}
	if(i!=j){
		t=a[j];
		a[j]=a[p];
		a[p]=t;
	}
	for(t=0;t<l;t++) printf("%d ",a[t]);
	printf("\n");
	
	quickSort1(a,start,j-1);
	quickSort1(a,j+1,end);

}


void quickSort2(int a[],int n){

	int i,j,s,e,t;
	int stack[MAX];
	int top=-1;
	stack[++top]=n;
	stack[++top]=0;

	while(top>=0){
		s=stack[top--];
		e=stack[top--];
		i=s;j=e;
		while(i<j){
			while(a[i]<a[s]&&i<=e) i++;
			while(a[j]>a[s]&&j>=0) j--;
			if(i<j){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
			for(t=0;t<l;t++) printf("%d ",a[t]); printf("\n");
		}

		t=a[j];
		a[j]=a[s];
		a[s]=t;

		for(t=0;t<l;t++) printf("%d ",a[t]); printf("\n");

		if(e>j+1){
			stack[++top]=e;
			stack[++top]=j+1;
		}
		if(s<j-1){
			stack[++top]=j-1;
			stack[++top]=s;
		}
	}

}
/****************output**********************
Enter no. of values : 5

Enter values : 23 36 47 21 32  
1. Recursive
2. Non Recursive
Enter choice : 1
23 36 47 21 32 
21 36 47 23 32 
21 36 47 23 32 
21 36 47 23 32 
21 32 47 23 36 
21 23 47 32 36 
21 23 47 32 36 
21 23 47 32 36 
21 23 36 32 47 
21 23 32 36 47 
21 23 32 36 47 
21 23 32 36 47 
21 23 32 36 47 
21 23 32 36 47 

Sorted List : 21 23 32 36 47 


Enter no. of values : 5

Enter values : 23 36 47 21 32
1. Recursive
2. Non Recursive
Enter choice : 2
23 36 47 21 32 
21 36 47 23 32 
21 36 47 23 32 
21 36 47 23 32 
21 32 47 23 36 
21 23 47 32 36 
21 23 47 32 36 
21 23 47 32 36 
21 23 36 32 47 
21 23 32 36 47 
21 23 32 36 47 
21 23 32 36 47 
21 23 32 36 47 
21 23 32 36 47
***************************************/

