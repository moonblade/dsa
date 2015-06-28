/*
  Ex 26
  Heap sort
  27-03-15
  S4 R 38 Mohammed Nisham K
*/
#include<stdlib.h>
#include<stdio.h>
#define max 20
int read(int a[]);
void hsort(int a[],int n);
void display(int a[],int n);
void heapmax(int a[],int i,int n);
int main()
{
  int a[max];
  int n;
  n=read(a);
  printf("sorted array\n");
  hsort(a,n);
  display(a,n);
  return 0;
}

//read
int read(int a[max])
{
  int i,n;
  printf("Enter the number of elements : ");
  scanf("%d",&n);
  printf("Enter the number ");
  for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
  return n;
}

//display
void display(int a[max],int n)
{
  int i;
  for(i=1;i<=n;i++)
    printf("%d ",a[i]);
  printf("\n");
}

//build max heap
void heapmax(int a[max],int i,int n) 
{
  int l,r,lar;
  int t;
  l=2*i;
  r=(2*i)+1;
  if(l<=n && a[l] > a[i])
    lar = l;
  else
    lar = i;
  if(r<=n && a[r]>a[lar])
    lar =r;
  if(lar != i)
    {
      t=a[lar];
      a[lar]=a[i];
      a[i]=t;
      heapmax(a,lar,n);
    }
}

//heapsort
void hsort(int a[max],int n)  
{
  int i,t;
  for(i=n/2;i>0;i--)
    heapmax(a,i,n);
  for(i=n;i>1;i--)
    {
      t=a[1];
      a[1]=a[i];
      a[i]=t;
      heapmax(a,1,i-1);
    }
}




/*OUTPUT

Enter the number of elements : 5
Enter the number   
8 3 -1 4 -9
sorted array
-9 -1 3 4 8 


Enter the number of elements : 8
Enter the number 
64 22 45 -74 36 26 -79 56
sorted array
-79 -74 22 26 36 -79 45 64 

*/

