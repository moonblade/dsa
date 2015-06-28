/*
  Ex 26
  Merge sort
  30-03-2015
  S4 R 38 Mohammed Nisham k
*/

#include<stdio.h>
#define MAX 100
void msortRecursive(int[],int,int);
void msortIterative(int[],int);
void merge(int[],int,int,int);
int len;
int main(){
  int i,n,a[MAX],c;
  printf("\nEnter no. of Elements : ");
  scanf("%d",&n);
  printf("\nEnter elements \n");
  for(i=0;i<n;i++) scanf("%d",a+i);
  len=n;
  printf("1. Recursive\n2. Non Recursive\nEnter choice : ");
  scanf("%d",&c);
  for(i=0;i<n;i++) printf("%d ",a[i]);
  printf("\n");
  if(c==1)
    msortRecursive(a,0,n-1);
  else
    msortIterative(a,n-1);
  printf("\nSorted List : ");
  for(i=0;i<n;i++) 
    printf("%d ",a[i]);
  printf("\n");
  return 0;
}

void msortRecursive(int a[],int s,int e){
  int m,i,j;
  if(s==e)
    return;
  m = (s+e)/2;
  msortRecursive(a,s,m);
  msortRecursive(a,m+1,e);
  merge(a,s,(s+e)/2,e);
}

void msortIterative(int a[],int n){
  int i,s=2,t;
  if(n<2) 
    return;
  while(s<n)
    {
      i=0;
      while(i+s<n)
	{
	  merge(a,i,(i+i+s-1)/2,i+s-1);
	  i+=s;
	}
      if(i<n) 
	merge(a,i,(i+n)/2,n);
      s*=2;
    }
  merge(a,0,i-1,n);
}

void merge(int a[],int s, int m,int e){
  int i,j,k=0,l=0;
  int T[MAX];
  for(i=s,j=m+1;i<=m&&j<=e;)
    {
      if(a[i]<a[j])
	T[k++]=a[i++];
      else 
	T[k++]=a[j++];
    }
  while(i<=m) 
    T[k++]=a[i++];
  while(j<=e) 
    T[k++]=a[j++];
  i=s;
  while(l<k) 
    a[i++]=T[l++];
  for(i=0;i<len;i++) 
    printf("%d ",a[i]);
  printf("\n");
  
}


/* OUTPUT


Enter no. of Elements : 5
Enter elements 
6 5 4 2 1
1. Recursive
2. Non Recursive
Enter choice : 6 5 4 2 1 
5 6 4 2 1 
4 5 6 2 1 
4 5 6 1 2 
1 2 4 5 6 

Sorted List : 1 2 4 5 6 

Enter no. of Elements : 5
Enter elements 
5 6 4 2 1
1. Recursive
2. Non Recursive
Enter choice : 5 6 4 2 1 
5 6 4 2 1 
5 6 1 4 2 
1 4 2 5 6 

Sorted List : 1 4 2 5 6 
*/
