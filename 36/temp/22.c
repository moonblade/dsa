/*
  Ex 22
  Binary Search Tree
  30/3/15
  S4 R 36 Mohamed Insaf K
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct nodes node;
struct nodes
{
  int val;
  node *r,*l;
};
node *p,*root,*t;

int no=6;
int menu();
node* newnode(int);
node* insert(int,node*);
node* delete(int,node*);
void inorder(node*);
void preorder(node*);
void postorder(node*);
int flag=0,del;

void main()
{
  root=NULL;
  int val,opt;
  printf("Menu \n1.Insert \n2.Delete \n3.Inorder Traversal \n4.Preorder Traversal \n5.Postorder Traversal \n6.Exit");
  while(1)
    {
      opt=menu();
      switch(opt)
	{
	case 1:
	  printf("Enter value to insert : ");
	  scanf("%d",&val);
	  root=insert(val,root);
	  break;
	case 2:
	  printf("Enter element to delete : ");
	  scanf("%d",&val);
	  delete(val,root);
	  if(flag)
	    printf("%d Deleted\n",val);
	  else
	    printf("Not found\n");
	  break;
	case 3:
	  printf("Contents : ");
	  inorder(root);
	  break;
	case 4:
	  printf("Contents : ");
	  preorder(root);
	  break;
	case 5:
	  printf("Contents : ");
	  postorder(root);
	  break;
	case 6:
	  return;
	default:
	  printf("Invalid Option\n");
	  break;
	} 
    }
}

int menu()
{
  printf("\nEnter Option : ");
  int op;
  scanf("%d",&op);
  return op;
}

node* newnode(int k)
{
  t=(node*)malloc(sizeof(node));
  t->val=k;
  t->l=NULL;
  t->r=NULL;
  return t;
}

//delete a node from the bst
node* delete(int a,node* T)
{
  if(a< T->val)
    T->l=delete(a,T->l);
  else if(a> T->val)
    T->r=delete(a,T->r);
  else if(T->l && T->r)
    {
      t=T->r;
      while(t->l!=NULL)
	t=t->l;
      T->val=t->val;
      T->r=delete(T->val,T->r);
    }
  else
    {
      if(T==root)
	{
	  t=root;
	  if(t->l == NULL)
	    root=T->r;
	  else if(T->r ==NULL)
	    root= T->l;
	  free(t);
	}
      else
	{
	  t=T;
	  if(T->l == NULL)
       T=T->r;
	  else if(T->r ==NULL)
	    T= T->l;
	  free(t);
	  flag=1;
	}
    }
  return T;
}

//insert value into bst
node* insert(int val,node *t)
{
  if(t==NULL)
    {
      t=newnode(val);
      if(root==NULL)
	root=t;
    }
  else if(t->val>val)
    t->l=insert(val,t->l);
  else
    t->r=insert(val,t->r);
  return t;
}

//inorder traversal
void inorder(node *t)
{
  if(t==NULL)
    return;
  inorder(t->l);
  printf("%d ",t->val);
  inorder(t->r);
}


//preorder traversal
void preorder(node *t)
{
  if(t==NULL)
    return;
  printf("%d ",t->val);
  preorder(t->l);
  preorder(t->r);
}

//postorder traversal
void postorder(node *t)
{
  if(t==NULL)
    return;
  postorder(t->l);
  postorder(t->r);
  printf("%d ",t->val);
}
