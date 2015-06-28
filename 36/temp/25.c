/*
  Ex 25
  Merge Sort
  30-03-15
  S4 R 36 Mohamed Insaf K
*/
#include<stdio.h>
#define max 20
int read(int a[]);
void mergesort(int[],int p,int q);
void merge(int [],int ,int ,int);
void display(int a[],int n);
int main()
{
  int a[max];
  int n;
  n=read(a);
  printf("sorted array\n");
  mergesort(a,0,n-1);
  display(a,n);
  return 0;
}

//read numbers
int read(int a[max])
{
  int i,n;
  printf("Enter the number of elements : ");
  scanf("%d",&n);
  printf("Enter numbers\n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  return n;
}

//display numbers
void display(int a[],int n)
{
  int i;
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
}

//mergesort
void mergesort(int a[],int p,int q)
{
  int r;
  if(p<q)
    {
      r=(p+q)/2;
      mergesort(a,p,r);
      mergesort(a,r+1,q);
      merge(a,p,q,r);
    }
}

//merge two arrays
void merge(int a[],int p ,int q ,int r)
{
  int i=p,j=p,k,m=r+1;
  int temp[max];
  while( j<=r && m<=q)
      if(a[j] <= a[m])
	  temp[i++]=a[j++];
      else
	  temp[i++]=a[m++];
  while(j<r+1)
      temp[i++]=a[j++];
  while(m<=q)
      temp[i++]=a[m++];
  for(k=p;k<=q;k++)
    a[k]=temp[k];
}


/*

OUTPUT

Enter the number of elements : 5
Enter numbers
8 3 -1 4 -9
sorted array
-9 -1 3 4 8 


Enter the number of elements : 8
Enter numbers
64 22 45 -74 36 26 -79 56
sorted array
-79 -74 22 26 36 -79 45 64 

*/

