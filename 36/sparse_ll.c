/*
        Ex No. 13 Addition of two sparse matrix using linked list
        S4R 036 Mohamed Insaf K
        24-02-2015
*/

#include <stdio.h>
#include <stdlib.h>

struct matrix{
        int row;
        int col;
        int val;
        struct matrix *next;
};

void read(struct matrix *);
void allocate(struct matrix **);
void display_sparse( struct matrix * );
int sum(struct matrix *, struct matrix *, struct matrix *);

void assign(struct matrix *, struct matrix *);
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
        scanf("%d%d", &s->row, &s->col);
        printf("Enter elements\n");
        for(i=0; i< s->row; i++)
                for(j=0; j< s->col; j++)
                {
                        scanf("%d", &in);
                        if( in != 0 )
                        {
                                k++;
                                allocate(&t);
                                t->row = i;
                                t->col = j;
                                t->val = in;
                                c->next = t;
                                c = t;
                                c->next = NULL;
                        }
                }
        s->val = k;
}
void display_sparse(struct matrix *s)
{
        int j;
        struct matrix *t;
        t = s;
        for(; t != NULL;t = t->next)
        {
                printf("%3d%3d%3d\n", t->row, t->col, t->val);
        }
}

int sum(struct matrix *a, struct matrix *b, struct matrix *c)
{
        int k, flag;
        struct matrix *t1 = c, *temp;
        if ( a->row ==  b->row && a->col == b->col )
        {
                c->row = a->row;
                c->col = a->col;
                for( a = a->next, b = b->next, k = 1;a != NULL && b != NULL; ++k)
                {
                        allocate(&temp);
                        flag = 1;
                        if(a->row == b->row)
                                if(a->col == b->col)
                                {
                                        if(a->val + b->val == 0)
                                                flag = 0;
                                        assign(temp, a);
                                        temp->val += b->val;
                                        a = a->next;
                                        b = b->next;
                                }
                                else if( a->col < b->col )
                                {
                                        assign(temp, a);
                                        a = a->next;
                                }
                                else
                                {
                                        assign(temp, b);
                                        b = b->next;
                                }
                        else if( a->row < b->row )
                        {
                                assign(temp, a);
                                a = a->next;
                        }
                        else
                        {
                                assign(temp, b);
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
                        assign(temp, a);
                        c->next = temp;
                        c = temp;
                        a = a->next;
                        ++k;
                }
                while( b != NULL )
                {
                        allocate(&temp);
                        assign(temp, b);
                        c->next = temp;
                        c = temp;
                        b = b->next;
                        ++k;
                }
                c->next = NULL;
                t1->val = k-1;
                return 1;
        }
        else
        {
                t1->val = -1;
                return 0;
        }
}

void assign(struct matrix *c, struct matrix *a)
{
        c->row = a->row;
        c->col = a->col;
        c->val = a->val;
}

void display(struct matrix *a )
{
        int i, j, k=1, count, remaining;
        struct matrix *t;

        for( i = count = 0, t = a->next; i < a->row; ++i)
        {
                for(j=0; j < a->col && t!=NULL; ++j, count++)
                        if( i == t->row && j == t->col )
                        {
                                printf("%3d", t->val);
                                t = t->next;
                        }
                        else
                                printf("%3d", 0);
                if(t==NULL)
                        break;
                printf("\n");
        }
        if( count % a->row-1 == 0)
                printf("\n");
        for(; count < a->row * a->col; count++)
        {
                printf("%3d", 0);
                if( (count+1) % a->col == 0)
                        printf("\n");
        }
        printf("\n");
}

/*        SAMPLE OUTPUT

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
