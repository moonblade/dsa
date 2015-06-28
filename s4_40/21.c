/*
BINU S
ROLL NO.: 64
EXPERIMENT NO.: 21
DATE: 19-03-2015
IMPLEMENTATION OF BINARY TREE USING LINKEDLIST
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct node
 {
	int val;
	struct node *lc;
	struct node *rc;
 };

typedef struct node node;

void insert(node* root, int nw);
int  delete(node* root, int key);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);
node* new_node();

int main()
 {
	node* root;

        printf( "  MENU  "
                "\n^^^^^^^^"
		"\n1. INSERT"
                "\n2. DELETE"
		"\n3. INORDER"
		"\n4. PREORDER"
		"\n5. POSTORDER"
		"\n6. EXIT");

	int key, op, val;

       	do
         {
		printf("\nENTER YOUR OPTION: ");
                scanf("%d", &op);

                switch(op)
                 {
                        case 1: printf("ENTER THE NEW VALUE: ");
                                scanf("%d", &new);
                                insert(root, new);
                                break;
                        case 2: printf("ENTER THE KEY: ");
                                scanf("%d", &key);

				if(!delete(root, key))
                                        printf("ELEMENT NOT FOUND!!!\n");
                                else
				 {
                                        printf("KEY REMOVED SUCCESSFULLY..\n");
				 }
                                break;
                        case 3: inorder(root);
				break;
                        case 4: preoder(root);
                                break;
                        case 4: postorder(root);
                                break;
                        case 5: exit(0);
                        default:printf("WRONG INPUT.....\n");
	 	 }
	 }while(1);

 }

node* new_node()
 {
	node *ptr= (node*) malloc(sizeof(node));

	if(ptr==NULL)
	 {
		printf("MEMORY NOT AVAILABLE...\n");
		exit(1);
	 }

	else
	 {
		ptr->lc = ptr->rc = NULL;
		return ptr;
	 }
 }

