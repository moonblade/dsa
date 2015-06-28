/*
PROGRAM 12
TRANSPOSE OF SPARSE MATRIX
25/03/2015
S4-R-64
BINU S
*/

#include<stdio.h>
#include<stdlib.h>

void read(int[][3]);
void add(int[][3],int[][3],int[][3]);
void displaym(int[][3]);
void transpose(int a[][3],int b[][3]);
void display(int[][3]);

int main()
	{
int sp1[10][3],sp2[10][3],sp3[10][3];

printf("\n  [A] \n ___\n");
read(sp1);

transpose(sp1,sp2);

printf("\n Sparse Matrix, A:\n");
display(sp1);


printf("\n Sparse Matrix, Transpose(A):\n");
display(sp2);

printf("\n Transpose(A) : \n");
displaym(sp2); //display in standard matrix form
printf("\n");


return 0;
}



void read(int sp[10][3])
{

int t,i,j,k=1,r,c;
printf("\n Enter the Order: ");
scanf("%d%d",&r,&c);
printf("\n Enter the Matrix :\n");

for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	 {
		scanf("%d",&t);
		if(t!=0)
		 {
			sp[k][0]=i;
			sp[k][1]=j;
			sp[k][2]=t;
			k++;
		 }
	}


sp[0][0]=r;
sp[0][1]=c;
sp[0][2]=k-1;

}


void display(int sp[10][3])
{
int r,c,tot,i,j,k;
r=sp[0][0];
c=sp[0][1];
tot=sp[0][2];

for(i=0;i<=tot;i++)
{
	for(j=0;j<3;j++)
		printf(" %d",sp[i][j]);
	printf("\n");
    }

}


void displaym(int sp[10][3])
{
 int r,c,tot,i,j,k;
 r=sp[0][0];
 c=sp[0][1];
 tot=sp[0][2];
 for(i=0;i<r;i++)
	{
		printf("\n");
		for(j=0;j<c;j++)
		 {
			for(k=1;k!=tot+1;k++)
			 {
				if( (sp[k][0]==i) && (sp[k][1]==j) )
				break;
			 }
			if(k==tot+1)
			 printf(" 0");
			else
			 printf(" %d",sp[k][2]);
		}
	}

}


void transpose(int a[][3], int b[][3])
 {

	int i, j;


	b[0][0]=a[0][1];
	b[0][1]=a[0][0];
	b[0][2]=a[0][2];

	int q=1;

	for(i=0; i!=b[0][0]; ++i)
	  for(j=1; j!=b[0][2]+1; ++j)
		if(a[j][1]==i)
		 {
			b[q][0]=a[j][1];
			b[q][1]=a[j][0];
			b[q][2]=a[j][2];

			q+=1;
		 }
 }



