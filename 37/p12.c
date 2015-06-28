/* program 12
transpose of sparse matrix
mohammed jasim e
31/3/15
 s1337   */


#include <stdio.h>

#define MAX 40

void read(int s[][3]);
void display_sparse(int [][3]);
void transpose(int [][3], int [][3]);
void display(int [][3]);

int main()
{
	int a[MAX][3], b[MAX][3];
	int flag;
	printf("Enter the order of the matrix\n");
	read(a);
	printf("\n\nORIGINAL MATRIX: \n");
	printf("Sparse Matrix Form\n");
	display_sparse(a);
	transpose(a,b);
	printf("\n\nTRANSPOSE OF THE MATRIX: \n");
	printf("\tSparse Matrix Form\n");
	display_sparse(b);
	printf("\tMatrix Form\n");
	display(b);
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
void transpose(int a[][3], int b[][3])
{
	int i, j, k=1;
	b[0][0] = a[0][1];
	b[0][1] = a[0][0];
	b[0][2] = a[0][2];
	for( i = 0; i < a[0][1]; ++i)
		for( j = 0; j <= a[0][2]; ++j)
		{
			if(a[j][1] == i)
			{
				b[k][1] = a[j][0];
				b[k][0] = i;
				b[k++][2] = a[j][2];
			}
		}
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



                 /* OUTPUT

Enter the order of the matrix
3 3
Enter elements
11  22  33
0   0   0
44  0   0


ORIGINAL MATRIX: 
Sparse Matrix Form
  3  3  4
  0  0 11
  0  1 22
  0  2 33
  2  0 44


TRANSPOSE OF THE MATRIX: 

	Sparse Matrix Form
  3  3  4
  0  0 11
  0  2 44
  1  0 22
  2  0 33
	Matrix Form
 11  0 44
 22  0  0
 33  0  0
*/



