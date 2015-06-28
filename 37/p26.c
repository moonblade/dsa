/*
    EXPT NO.26
    QUICK SORT
    30-03-15
    S4R-37    mohammed jasim e
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
 printf("BEFORE SORTING\n");
 display(a,n);
 printf("AFTER SORTING\n");
 qsort(a,0,n-1);
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


void qsort(int a[max],int p,int q)     //sorts using quicksort
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


