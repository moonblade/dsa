/*
    EXPT NO.19
    POLYNOMINAL MULTIPLICATION USING ARRAY
    20-03-15
    S4R-37   mohammed jasim e
*/
#include<stdio.h>
#define max 20
int read(int a[][2]);
void display(int a[][2],int x);
void mult(int a[][2],int b[][2],int c[][2]);
void sort(int a[][2],int x);
int m,n,o;
int main()
{
 int a[max][2],b[max][2],c[max][2];
 m=read(a);
 n=read(b);
 sort(a,m);
 sort(b,n);
 mult(a,b,c);
 printf("POLYNOMIAL 1:  ");
 display(a,m);
 printf("POLYNOMIAL 2:  ");
 display(b,n);
 printf("MULTIPLIED POLYNOMIAL IS:  ");
 display(c,o);
 return 0;
}


int read(int a[][2])                    //reads a polynomial
{
 int i;
 printf("Enter the number of elements in polynominal");
 scanf("%d",&n);
 printf("Enter coefficients and powers of polynominal");
 for(i=0;i<n;i++)
   scanf("%d%d",&a[i][0],&a[i][1]);
 return n;
}


void display(int a[max][2],int x)           //dispalys a polynomial
{
int i;
 for(i=0;i<x-1;i++)
 {
   if(a[i][0]==0)
    continue;
   printf("%d",a[i][0]);
   if(a[i][1]==1)
    printf("X");
   else if(a[i][1]!=0)
    printf("X^%d ",a[i][1]);
   if(a[i+1][0]>0)
    printf(" + ");
 }
 printf("%d",a[i][0]);
  if(a[i][1]!=0)
  printf("X^%d ",a[i][1]);
printf("\n");
}


void mult(int a[max][2],int b[max][2],int c[max][2])         //multiplies two polynomials
{
 int l,flag,i,j,k;
 l=0;
 for(i=0;i<m;i++)
 {
  for (j=0;j<n;j++)
  {
  flag=0;
  for(k=0;k<o;k++)
   if(a[i][1]+b[j][1]==c[k][1])
   {
     c[k][0]=a[i][0]*b[j][0]+c[k][0];
     flag=1;
     break;
    }
  if(flag==0)
   {
     c[l][0]=a[i][0]*b[j][0];
     c[l][1]=a[i][1]+b[j][1];
     o++;
     l++;
   }
  }
 }
}


void sort(int a[max][2],int x)             //sorts a polynomial
{
int i,j,y,z;
for(i=0;i<x-1;i++)
  for(j=i+1;j<x;j++)
   if(a[i][1]<a[j][1])
     {
       y=a[j][0];
       z=a[j][1];
       a[j][0]=a[i][0];
       a[j][1]=a[i][1];
       a[i][0]=y;
       a[i][1]=z;
     }
}


/*

==================OUTPUT========================

Enter the number of elements in polynominal 3
Enter coefficients and powers of polynominal
3 2
2 1
4 0
Enter the number of elements in polynominal 2
Enter coefficients and powers of polynominal
4 2
5 1
POLYNOMIAL 1:  3X^2  + 2X + 4
POLYNOMIAL 2:  4X^2  + 5X^1 
MULTIPLIED POLYNOMIAL IS:  12X^4  + 23X^3  + 26X^2  + 20X^1 



Enter the number of elements in polynominal 2
Enter coefficients and powers of polynominal 
2 1 
-2 0
Enter the number of elements in polynominal 2
Enter coefficients and powers of polynominal
2 1
2 0
POLYNOMIAL 1:  2X-2
POLYNOMIAL 2:  2X + 2
MULTIPLIED POLYNOMIAL IS:  4X^2 -4

*/


