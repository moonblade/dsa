/*
	Ex No. 13 Addition of two sparse matrix using linked list
	S4R 036 Mohamed Insaf K
	24-02-2015
*/

#include <stdio.h>
#include <stdlib.h>

struct matrix{
	int arr[3];
	struct matrix *next;
};

void read(struct matrix *);
void allocate(struct matrix **);
void display_sparse( struct matrix * );
int sum(struct matrix *, struct matrix *, struct matrix *);

void assign(int [], int []);
void display(struct matrix *);

int main()
{
	struct matrix *a, *b, *c;
	allocate(&a);
	allocate(&b);
	allocate(&c);
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
	else
		printf("Two matrices are not addition conformable\n");
	return 0;
}

void allocate(struct matrix **s)
{
	*s = (struct matrix *)malloc(sizeof(struct matrix));
}

void read(struct matrix *s)
{
	int i, j, k=0, in;
	struct matrix *t, *c;
	c = s;
	c->next = NULL;
	scanf("%d%d", &s->arr[0], &s->arr[1]);
	printf("Enter elements\n");
	for(i=0; i< s->arr[0]; i++)
		for(j=0; j< s->arr[1]; j++)
		{
			scanf("%d", &in);
			if( in != 0 )
			{
				k++;
				allocate(&t);
				t->arr[0] = i;
				t->arr[1] = j;
				t->arr[2] = in;
				c->next = t;
				c = t;
				c->next = NULL;
			}
		}
	s->arr[2] = k;
}
void display_sparse(struct matrix *s)
{
	int j;
	struct matrix *t;
	t = s;
	for(; t != NULL;t = t->next)
	{
		for(j=0; j<3; ++j)
			printf("%3d", t->arr[j]);
		printf("\n");
	}
}

int sum(struct matrix *a, struct matrix *b, struct matrix *c)
{
	int k, flag;
	struct matrix *t1 = c, *temp;
	if ( a->arr[0] ==  b->arr[0] && a->arr[1] == b->arr[1] )
	{
		c->arr[0] = a->arr[0];
		c->arr[1] = a->arr[1];
		for( a = a->next, b = b->next, k = 1;a != NULL && b != NULL; ++k)
		{
			allocate(&temp);
			flag = 1;
			if(a->arr[0] == b->arr[0])
				if(a->arr[1] == b->arr[1])
				{
					if(a->arr[2] + b->arr[2] == 0)
						flag = 0;
					assign(temp->arr, a->arr);
					temp->arr[2] += b->arr[2];
					a = a->next;
					b = b->next;
				}
				else if( a->arr[1] < b->arr[1] )
				{
					assign(temp->arr, a->arr);
					a = a->next;
				}
				else
				{
					assign(temp->arr, b->arr);
					b = b->next;
				}
			else if( a->arr[0] < b->arr[0] )
			{
				assign(temp->arr, a->arr);
				a = a->next;
			}
			else
			{
				assign(temp->arr, b->arr);
				b = b->next;
			}
			if( flag )
			{
				c->next = temp;
				c = temp;
			}
			else
				--k;
		}
		while( a != NULL )
		{
			allocate(&temp);
			assign(temp->arr, a->arr);
			c->next = temp;
			c = temp;
			a = a->next;
			++k;
		}
		while( b != NULL )
		{
			allocate(&temp);
			assign(temp->arr, b->arr);
			c->next = temp;
			c = temp;
			b = b->next;
			++k;
		}
		c->next = NULL;
		t1->arr[2] = k-1;
		return 1;
	}
	else
	{
		t1->arr[2] = -1;
		return 0;
	}
}

void assign(int c[], int a[])
{
	c[0] = a[0];
	c[1] = a[1];
	c[2] = a[2];
}

void display(struct matrix *a )
{
	int i, j, k=1, count, remaining;
	struct matrix *t;

	for( i = count = 0, t = a->next; i < a->arr[0]; ++i)
	{
                for(j=0; j < a->arr[1] && t!=NULL; ++j, count++)
                        if( i == t->arr[0] && j == t->arr[1] )
			{
                                printf("%3d", t->arr[2]);
				t = t->next;
			}
                        else
                                printf("%3d", 0);
		if(t==NULL)
			break;
                printf("\n");
	}
	if( count % a->arr[1] == 0)
		printf("\n");
	for(; count < a->arr[0]*a->arr[1]; count++)
	{
		printf("%3d", 0);
		if( (count+1) % a->arr[1] == 0)
			printf("\n");
	}
	printf("\n");
}

/*	SAMPLE OUTPUT

Enter the order of first matrix
4 3
Enter elements
1 0 0 
6 -5 4 
0 0 0
0 1 0
Enter the order of second matrix
4 3
Enter elements
7 0 6
0 5 0
0 0 0
0 0 0
FIRST MATRIX: 
	Sparse Matrix Form
  4  3  5
  0  0  1
  1  0  6
  1  1 -5
  1  2  4
  3  1  1
SECOND MATRIX: 
	Sparse Matrix Form
  4  3  3
  0  0  7
  0  2  6
  1  1  5
SUM MATRIX
	Sparse matrix form
  4  3  5
  0  0  8
  0  2  6
  1  0  6
  1  2  4
  3  1  1
	Matrix Form: 
  8  0  6
  6  0  4
  0  0  0
  0  1  0


*/
