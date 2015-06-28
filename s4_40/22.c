/*
BINU S
ROLL NO.: 64
EXPERIMENT NO.: 22
DATE: 20-03-2015
IMPLEMENTATION OF BINARY SEARCH TREE USING LINKEDLIST
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

void insert(node** root, int nw);
int delete(node** root, int key);
node** search(node** root, int key);
node** inSuc(node* root);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);
node* new_node();

int main()
 {
	node* root=NULL;

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
                                scanf("%d", &val);
                                insert(&root, val);
                                break;
                        case 2: printf("ENTER THE KEY: ");
                                scanf("%d", &key);

				if(!delete(&root, key))
                                        printf("ELEMENT NOT FOUND!!!\n");
                                else
				 {
                                        printf("KEY REMOVED SUCCESSFULLY..\n");
				 }
                                break;
                        case 3: printf("THE INORDER TRAVERSAL OF THE TREE: ");
				inorder(root);
				printf("\n");
				break;
                        case 4:	printf("THE PREORDER TRAVERSAL OF THE TREE: ");
				preorder(root);
				printf("\n");
                                break;
                        case 5: printf("THE POSTORDER TRAVERSAL OF THE TREE: ");
				postorder(root);
				printf("\n");
                                break;
                        case 6: exit(0);
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

void insert(node** root, int nw)
 {
	if(*root ==NULL)
	 {
		*root=new_node();
		(*root)->val=nw;
	 }
	else if(nw>(*root)->val)
	 {
		insert(&((*root)->rc), nw);
	 }
	else
	 {
		insert(&((*root)->lc), nw);
	 }
 }

int delete(node** root, int key)
 {
	node  **ptr;

	ptr=search(root, key);

	if(ptr==NULL)
		return 0;

	else if((*ptr)->lc==NULL &&(*ptr)->rc==NULL)
	 {
		free(*ptr);
		*ptr=NULL;
		return 1;
	 }

	else if((*ptr)->lc==NULL)
	 {
		node *temp= *ptr;
		*ptr= (*ptr)->rc;
		free (temp);

		return 1;
	 }

	else if((*ptr)->rc==NULL)
	 {
		node *temp= *ptr;
		*ptr= (*ptr)->lc;
		free (temp);

		return 1;
	 }

	else
	 {
		node **suc=inSuc(*ptr);

		(*ptr)->val=(*suc)->val;

		if((*suc)->lc==NULL &&(*suc)->rc==NULL)
		 {
			free(*suc);
			*suc=NULL;
			return 1;
		 }
		else if((*suc)->lc==NULL)
		 {
			node *temp= *suc;
			*suc= (*suc)->rc;
			free(temp);
			return 1;
		 }
		else if((*suc)->rc==NULL)
		 {
			node *temp= *suc;
			*suc= (*suc)->lc;
			free(temp);
			return 1;
		 }
	 }

 }

node** search(node** root, int key)
 {
	if(*root==NULL)
		return NULL;
	else if((*root)->val==key)
		return root;
	else if(key> (*root)->val)
		return search(&((*root)->rc), key);
	else
		return search(&((*root)->lc), key);
 }

node** inSuc(node* root)
 {
	if(root->rc->lc ==NULL)
		return &(root->rc);
	else
	 {
		while(root->lc->lc!=NULL)
			root=root->lc;

		return &(root->lc);
	 }
 }

void inorder(node* root)
 {
	if(root==NULL)
		return;
	else
	 {
		inorder(root->lc);
		printf("%d ", root->val);
		inorder(root->rc);
	 }
 }

void preorder(node* root)
 {
	if(root==NULL)
		return;
	else
	 {
		printf("%d ", root->val);
		preorder(root->lc);
		preorder(root->rc);
	 }
 }

void postorder(node* root)
 {
	if(root==NULL)
		return;
	else
	 {
		postorder(root->lc);
		postorder(root->rc);
		printf("%d ", root->val);
	 }
 }
