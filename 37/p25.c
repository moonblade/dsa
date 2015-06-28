/*
    EXPT NO.25
    MERGE SORT
    30-03-15
    S4R-37   mohammed jasim e
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
  printf("BEFORE SORTING\n");
  display(a,n);
  printf("AFTER SORTING\n");
  mergesort(a,0,n-1);
  display(a,n);
  return 0;
}


int read(int a[max])         //reads the numbers
{
 int i,n;
 printf("Enter the number of numbers ");
 scanf("%d",&n);
 printf("Enter the number ");
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 return n;
}


void display(int a[max],int n)     //displays the numbers
{
 int i;
 for(i=0;i<n;i++)
  printf("%d ",a[i]);
 printf("\n");
}


void mergesort(int a[max],int p,int q)     //sorts using mergesort
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


void merge(int a[max],int p ,int q ,int r)         //merges two arrays
{
 int i,j,k,m;
 int temp[max];
 i=p;
 j=p;
 m=r+1;
 while( j<= r && m<= q )
 {
   if(a[j] <= a[m])
    {
      temp[i]=a[j];
      j++;
    }
   else
    {
     temp[i]=a[m];
     m++;
     }
   i++;
 }
 while(j<m)
  {
     temp[i]=a[j];
     j++;
     i++;
  }
 while(m<=q)
  {
       temp[i]=a[m];
       m++;
       i++;
  }
  for(k=p;k<=q;k++)
  {
    a[k]=temp[k];
  }
}


/*

===========================OUTPUT=====================

Enter the number of numbers 5
Enter the number   
8 3 -1 4 -9
BEFORE SORTING
8 3 -1 4 -9 
AFTER SORTING
-9 -1 3 4 8 


Enter the number of numbers 
8
Enter the number 
64 22 45 -74 36 26 -79 56
BEFORE SORTING
64 22 45 -74 36 26 -79 56 
AFTER SORTING
-79 -74 22 26 36 -79 45 64 

*/

