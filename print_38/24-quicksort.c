/*
  Ex 24
  Quick sort
  30-03-15
  S4 R 38 Mohammed Nisham K
*/
#include<stdio.h>
#define max 20
int read(int a[]);
void qsort(int[],int p,int q);
void display(int a[],int n);
int n;

//partition the array
int partition(int a[max],int p,int q)
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
      return j;
    }
}

//iterative quicksort
void qsortnr(int a[],int p,int q)
{
  int stack[p+q-1];
  int s;
  int top=-1;
  stack[++top]=p;
  stack[++top]=q;
  while(top>-1)
    {
      display(a,n);
      q=stack[top--];
      p=stack[top--];
      s=partition(a,p,q);
      if(s>p)
	{
	  stack[++top]=p;
	  stack[++top]=s-1;
	}
      if(s<q)
	{
	  stack[++top]=s+1;
	  stack[++top]=q;
	}
    }
}



int main()
{
  int a[max];
  int opt;
  n=read(a);
  printf("1.Recursive \t2.Iterative : ");
  scanf("%d",&opt);
  if(opt==1)
    qsort(a,0,n-1);
  else
    qsortnr(a,0,n-1);
  printf("\nsorted array\n");
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
  printf("\n");
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
	display(a,n);
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
  qsort(a,j+1,q);
  qsort(a,p,j-1);

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

