/*
  Ex 26
  Quick sort
  30-03-15
  S4 R 36 Mohamed Insaf K
*/
#include<stdio.h>
#define max 20
int read(int a[]);
void qsort(int[],int p,int q);
void display(int a[],int n);
int main()
{
  int a[max];
  int n;
  n=read(a);
  printf("sorted array\n");
  qsort(a,0,n-1);
  display(a,n);
  return 0;
}

//read numbers
int read(int a[max])
{
  int i,n;
  printf("Enter the number of elements : ");
  scanf("%d",&n);
  printf("Enter the numbers ");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
 return n;
}

//display 
void display(int a[max],int n)
{
  int i;
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
}

//quicksort
void qsort(int a[max],int p,int q)
{
  int i,j,pivot;
  int t;
  if(p<q)
    {
      i=p;
      j=q+1;
      pivot=a[p];
      do {
	do {
          i=i+1;
        }while(i<=q && a[i]<pivot);
	do {
          j=j-1;
        }while(j>=p && a[j]>pivot);
	if(i<j)
	  {
	    t=a[i];
	    a[i]=a[j];
	    a[j]=t;
	  }
      }while(i<j);
  t=a[p];
  a[p]=a[j];
  a[j]=t;
  qsort(a,p,j-1);
  qsort(a,j+1,q);
    }
}



/*

OUTPUT

Enter the number of elements : 5
Enter the numbers   
8 3 -1 4 -9
sorted array
-9 -1 3 4 8 


Enter the number of elements : 8
Enter the numbers 
64 22 45 -74 36 26 -79 56
sorted array
-79 -74 22 26 36 -79 45 64 

*/

