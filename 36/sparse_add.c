/*
	Ex No. 11 Addition of two sparse matrix using array
	S4R 036 Mohamed Insaf K
	09-02-2015
*/

#include <stdio.h>

#define MAX 40

void read(int s[][3]);
void display_sparse(int [][3]);
int sum(int [][3], int [][3], int [][3]);
void assign(int [], int []);
void display(int [][3]);

int main()
{
	int a[MAX][3], b[MAX][3], c[MAX][3];
	int flag;
	printf("Enter the order of first matrix\n");
	read(a);
	printf("Enter the order of second matrix\n");
	read(b);
	printf("FIRST MATRIX: \n");
	printf("\tSparse Matrix Form\n");
	display_sparse(a);
	printf("SECOND MATRIX: \n");
	printf("\tSparse Matrix Form\n");
	display_sparse(b);
	flag = sum(a, b, c);
	if(flag)
	{
		printf("SUM MATRIX\n");
		printf("\tSparse matrix form\n");
		display_sparse(c);
		printf("\tMatrix Form: \n");
		display(c);
	}
	return 0;
}

void read(int s[][3])
{
	int i, j, k=0, in;
	scanf("%d%d", &s[0][0], &s[0][1]);
	printf("Enter elements\n");
	for(i=0; i<s[0][0]; i++)
		for(j=0; j<s[0][1]; j++)
		{
			scanf("%d", &in);
			if( in != 0 )
			{
				k++;
				s[k][0] = i;
				s[k][1] = j;
				s[k][2] = in;
			}
		}
	s[0][2] = k;
}

void display_sparse(int s[][3])
{
	int i, j;
	for( i=0; i < s[0][2] + 1; i++)
	{
		for(j=0; j<3; ++j)
			printf("%3d", s[i][j]);
		printf("\n");
	}
}
int sum(int a[][3], int b[][3], int c[][3])
{
	int i, j, k;
	if ( a[0][0] == b[0][0] && a[0][1] == b[0][1] )
	{
		c[0][0] = a[0][0];
		c[0][1] = a[0][1];
		for( i=j=k=1; (i < a[0][2] + 1) && (j < b[0][2] + 1); k++)
		{
			if(a[i][0] == b[j][0])
				if(a[i][1] == b[j][1])
				{
					assign(c[k], a[i++]);
					c[k][2] += b[j++][2];
					if( c[k][2] == 0)
						k--;
				}
				else if( a[i][1] < b[j][1] )
					assign(c[k], a[i++]);
				else
					assign(c[k], b[j++]);
			else if( a[i][0] < b[j][0] )
				assign(c[k], a[i++]);
			else
				assign(c[k], b[j++]);
		}
		while( i < a[0][2]+1 )
			assign(c[k++], a[i++]);
		while( j < b[0][2]+1 )
			assign(c[k++], b[j++]);
		c[0][2] = k-1;
		return 1;
	}
	else
	{
		printf("Two matrices are not addition conformable\n");
		c[0][2] = -1;
		return 0;
	}
}

void assign(int c[], int a[])
{
	c[0] = a[0];
	c[1] = a[1];
	c[2] = a[2];
}

void display(int a[][3])
{
	int i, j, k=1;
	for( i=j=0; i < a[0][0];++i)
	{
		for(j=0; j < a[0][1]; ++j)
			if( i == a[k][0] && j == a[k][1] )
				printf("%3d", a[k++][2]);
			else
				printf("%3d", 0);
		printf("\n");
	}
}

/*	SAMPLE OUTPUT
1)
	Enter the order of first matrix
	4 3
	Enter elements
	1 0 0
	0 5 0
	0 0 8
	9 0 0
	Enter the order of second matrix
	4 3
	Enter elements
	1 0 9
	0 -5 0
	9 0 7
	0 0 0
	FIRST MATRIX: 
		Sparse Matrix Form
	  4  3  4
	  0  0  1
	  1  1  5
	  2  2  8
	  3  0  9
	SECOND MATRIX: 
		Sparse Matrix Form
	  4  3  5
	  0  0  1
	  0  2  9
	  1  1 -5
	  2  0  9
	  2  2  7
	SUM MATRIX
		Sparse matrix form
	  4  3  5
	  0  0  2
	  0  2  9
	  2  0  9
	  2  2 15
	  3  0  9
		Matrix Form: 
	  2  0  9
	  0  0  0
	  9  0 15
	  9  0  0


2)
	Enter the order of first matrix
	2 3
	Enter elements
	1 0 0 
	0 0 1
	Enter the order of second matrix
	3 2
	Enter elements
	1 0
	0 5
	1 0
	FIRST MATRIX: 
		Sparse Matrix Form
	  2  3  2
	  0  0  1
	  1  2  1
	SECOND MATRIX: 
		Sparse Matrix Form
	  3  2  3
	  0  0  1
	  1  1  5
	  2  0  1
	Two matrices are not addition conformable

*/
