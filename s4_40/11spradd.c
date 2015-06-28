/*
  Ex.No:11
  Addition of sparse matrix using array
  MUHAMMED THABJEEL
  S4 R 40
  Date:23-03-2015
*/
#include<stdio.h>
#define MAX 5
int input(int[][MAX],int[][3],int,int),sp[MAX*MAX][3],add(int [][3],int [][3],int,int);
void display(int[][3]);
void main()
{
  int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX],s1[MAX*MAX][3],s2[MAX*MAX][3],r1,r2,c1,c2,k,k1,k2;
  printf("Input the size of first sparse matrix\n");
  scanf("%d %d",&r1,&c1);
  printf("Input the size of second sparse matrix\n");
  scanf("%d %d",&r2,&c2);
if((r1!=r2)||(c1!=c2))
  printf("The matrices can't be added\n");
else
  {
    printf("Input the elements of the first sparse matrix rowwise\n");
    k1=input(a,s1,r1,c1);
    printf("Input the elements of the second sparse matrix rowwise\n");
    k2=input(b,s2,r2,c2);
    printf("Result of addition:\n");
    k=add(s1,s2,k1,k2);
    display(sp);
  }
}
int input(int x[][MAX],int s[][3],int r,int c)
{
  int i,j,k=1;
  s[0][0]=r;
  s[0][1]=c;
  s[0][2]=0;
  for(i=0;i<r;i++)
    for(j=0;j<c;j++)
      {
	scanf("%d",&x[i][j]);
	if(x[i][j]!=0)
	  {
	    s[0][2]++;
	    s[k][0]=i;
	    s[k][1]=j;
	    s[k][2]=x[i][j];
	    k++;
	  }
      }
  return k;
}
int add(int sp1[][3], int sp2[][3], int k1, int k2)
{
int i,j,k=1;
	sp[0][0]=sp1[0][0];
  	sp[0][1]=sp1[0][1];
	for(i=1,j=1;i<k1&&j<k2;)
	{
		if(sp1[i][0]==sp2[j][0]&&sp1[i][1]==sp2[j][1])
		{
			sp[k][0] = sp1[i][0];
			sp[k][1] = sp1[i][1];
			sp[k++][2] = sp1[i++][2]+sp2[j++][2];
		}
		else if((sp1[i][0]<sp2[j][0])||((sp1[i][0]==sp2[j][0])&&(sp1[i][1]<sp2[j][1])))
		{
			sp[k][0] = sp1[i][0];
			sp[k][1] = sp1[i][1];
			sp[k++][2] = sp1[i++][2];
		}
		else
		{
			sp[k][0] = sp2[j][0];
			sp[k][1] = sp2[j][1];
			sp[k++][2] = sp2[j++][2];
		}
	}

	while(i<k1)
	{
		sp[k][0] = sp1[i][0];
		sp[k][1] = sp1[i][1];
		sp[k++][2] = sp1[i++][2];
	}
	while(j<k2)
	{
		sp[k][0] = sp2[j][0];
		sp[k][1] = sp2[j][1];
		sp[k++][2] = sp2[j][2];
	}
	sp[0][2]=k-1;
	return k;
}
void display(int sp[][3])
{
        int i,j,k=1;
        for(i=0;i<sp[0][0];i++){
                for(j=0;j<sp[0][1];j++){
                        if(sp[k][0]==i&&sp[k][1]==j)
                                printf("%d\t",sp[k++][2]);
                        else
                                printf("0\t");
                }
                printf("\n\n");
        }
	for(i=0;i<sp[0][2]+1;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",sp[i][j]);
		printf("\n");
	}
}

