/*
PROGRAM 13
ADDITION OF TWO SPARSE MATRICES USING LINKED LIST
26/03/2015
S4-R-64
BINU S
*/


#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct node
 {
        int row;
        int col;
        int val;
        struct node* link;
 };

typedef struct node node;


void displaysp(node*);
void display(node*);
void convert(int[][MAX], node*, int, int);
void add(node*, node*, node*);


int main()
 {
        int r1, c1, r2, c2;
        int i, j;
        int norm[MAX][MAX];
        node *a, *b, *c;

        printf("\n Enter the No. of Rows & Columns of Matrix A: ");
        scanf("%d %d",&r1, &c1);

        printf("\n Enter the No. of Rows & Columns of Matrix B: ");
        scanf("%d %d",&r2, &c2);

        if(r1==r2 && c1==c2)
         {
                a=(node*) malloc(sizeof(node));
                b=(node*) malloc(sizeof(node));
                c=(node*) malloc(sizeof(node));

                if(a==NULL || b==NULL || c==NULL)
                 {
                        printf("\n MEMORY NOT AVAILABLE...\n");
                        exit(1);
                 }

                a->link=b->link=c->link=NULL;

                printf("\n Enter the Matrix A :\n");
                for(i=0; i<r1; ++i)
                        for(j=0; j<c1; ++j)
                                scanf("%d", &norm[i][j]);
                convert(norm, a, r1, c1);

                printf("\n Enter the Matrix B :\n");
                for(i=0; i<r1; ++i)
                        for(j=0; j<c1; ++j)
                                scanf("%d", &norm[i][j]);
                convert(norm, b, r1, c1);

                add(a, b, c);

                printf("\n Sparse Matrix, A:\n");
                displaysp(a);

                printf("\n Sparse Matrix, B:\n");
                displaysp(b);

                printf("\n Sparse Matrix, A+B :\n\n");
                displaysp(c);

                printf("\n[A+B]: \n");
                display(c);
         }

        else
                printf("Order must be same for Addition !!\n");

        return 0;
 }


void displaysp(node *header)
 {
        node *ptr=header;

        while(ptr!=NULL)
         {
                printf("%d  %d  %d\n", ptr->row, ptr->col, ptr->val);
                ptr=ptr->link;
         }

 }


void display(node* sp_head)
 {
        int i, j;
        node* ptr=sp_head->link;

        for(i=0; i!=sp_head->row; ++i)
         {
                for(j=0; j!=sp_head->col;++j)
                 {
                        if(ptr==NULL || ptr->row!=i || ptr->col!=j)
                                printf("0  ");
                        else
                         {
                                printf("%d  ", ptr->val);
                                ptr=ptr->link;
                         }
                 }

                printf("\n");
         }
 }

void convert(int norm[MAX][MAX], node *sp_head, int r, int c)
 {
        int count=0;
        int i, j;

        sp_head->row=r;
        sp_head->col=c;

        node* ptr=sp_head;

        for(i=0; i<r; ++i)
         for(j=0; j<c; ++j)
                if(norm[i][j]!=0)
                 {
                        count++;

                        ptr->link=(node*)malloc(sizeof(node));

                        if(ptr->link==NULL)
                         {
                                printf("MEMORY NOT AVAILABLE...\n");
                                exit(1);
                         }

                        ptr=ptr->link;

                        ptr->link=NULL;
                        ptr->row=i;
                        ptr->col=j;
                        ptr->val=norm[i][j];
                 }

        sp_head->val=count;

        printf("\n");

 }

void add(node* a, node* b, node* c)
 {
        node *aptr, *bptr, *cptr, *temp;
        int count=0;

        c->row=a->row;
        c->col=a->col;

        aptr=a->link;
        bptr=b->link;
        cptr=c;

        while(aptr !=NULL && bptr!=NULL)
         {
                count++;

                temp=(node*)malloc(sizeof(node));

                if(temp==NULL)
                 {
                        printf("MEMORY NOT AVAILABLE...\n");
                        exit(1);
                 }

                temp->link=NULL;

                if(aptr->row < bptr->row)
                 {
                        temp->row=aptr->row;
                        temp->col=aptr->col;
                        temp->val=aptr->val;

                        aptr=aptr->link;
                        cptr->link=temp;
                        cptr=temp;
                 }

                else if(aptr->row > bptr->row)
                 {
                        temp->row=bptr->row;
                        temp->col=bptr->col;
                        temp->val=bptr->val;

                        bptr=bptr->link;
                        cptr->link=temp;
                        cptr=temp;
                 }

                else
                 {
                        if(aptr->col < bptr->col)
                         {
                                temp->row=aptr->row;
                                temp->col=aptr->col;
                                temp->val=aptr->val;

                                aptr=aptr->link;
                                cptr->link=temp;
                                cptr=temp;
                         }
                        else if(aptr->col > bptr->col)
                         {
                                temp->row=bptr->row;
                                temp->col=bptr->col;
                                temp->val=bptr->val;

                                bptr=bptr->link;
                                cptr->link=temp;
                                cptr=temp;
                         }
                        else
                         {
                                temp->row=aptr->row;
                                temp->col=aptr->col;
                                temp->val=aptr->val + bptr->val;

                                aptr=aptr->link;
                                bptr=bptr->link;

                                if(temp->val!=0)
                                 {
                                        cptr->link=temp;
                                        cptr=temp;
                                 }

                                else
                                 {
                                        free(temp);
                                        count--;
                                 }
                         }

                 }
         }

        while(aptr != NULL)
         {
                count++;

                cptr->link=(node*)malloc(sizeof(node));

                if(cptr->link==NULL)
                 {
                        printf("MEMORY NOT AVAILABLE...\n");
                        exit(1);
                 }
                cptr=cptr->link;

                cptr->link=NULL;

                cptr->row=aptr->row;
                cptr->col=aptr->col;
                cptr->val=aptr->val;

                aptr=aptr->link;
         }

        while(bptr != NULL)
         {
                count++;

                cptr->link=(node*)malloc(sizeof(node));

                if(cptr->link==NULL)
                 {
                        printf("MEMORY NOT AVAILABLE...\n");
                        exit(1);
                 }
                cptr=cptr->link;

                cptr->link=NULL;

                cptr->row=bptr->row;
                cptr->col=bptr->col;
                cptr->val=bptr->val;

                bptr=bptr->link;
         }

        c->val=count;
 }




