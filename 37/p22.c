/*
    EXPT NO.22
    BINARY SEARCH TREE
    26-03-15
    S4R-37-  mohammed jasim e
*/
#include<stdlib.h>
#include<stdio.h>
struct node{
   int val;
   struct node *left,*right;
 }*root,*T,*t;
typedef struct node node;
struct node* insert(int a,struct node* T);
struct node* delete(int a, struct node* T);
void preorder(struct node* T);
void inorder(struct node* T);
void postorder(struct node* T);
struct node* findmin(struct node* T);
int f;
int main()
{
 int c,b;
 root = NULL;
 printf("BST OPERATIONS \n 1.INSERT \n 2.DELETE \n 3.INORDER \n 4.PREORDER \n 5.POSTORDER \n 6.EXIT\n");
   do
   {
   printf("\n Enter your choice : ");
   scanf("%d",&c);
   switch(c)
    {
     case 1: printf("Enter the value to be added : ");
             scanf("%d",&b);
             insert(b,root);
             break;

     case 2:
             if(root==NULL)
              printf(" BST EMPTY!!");
             else
             {
              f=0;
              printf("Enter the element to be deleted");
              scanf("%d",&b);
              t=delete(b,root);
              if(f==1)
               printf("Element deleted: %d\n",b);
             }
             break;

     case 3: if(root==NULL)
              printf("BST empty ");
             else
             {
             printf("INORDER TRAVERSAL IS :  ");
             inorder(root);
             }
             break;

     case 4: if(root==NULL)
              printf("BST empty");
             else
             {
              printf("PREORDER TRAVERSAL IS :  ");
              preorder(root);
             }
             break;
     case 5: if(root==NULL)
              printf("BST empty");
             else
             {
             printf("POSTORDER TRAVERSAL IS :  ");
             postorder(root);
             }
             break;
     case 6: return;
      default: printf("Invalid entry\n");
               break;
     }
    }while(1);
  return 0;
}


struct node* insert(int a,struct node* T)            //insert a new node into the bst
{  if(root==NULL)
   {
     root = (struct node*)malloc(sizeof(struct node));
     root->val=a;
     root->right=NULL;
     root->left=NULL;
   }
   if(T==NULL)
    {
     T = (struct node*)malloc(sizeof(struct node));
     T->val=a;
     T->right=NULL;
     T->left=NULL;

    }
   else if(T->val < a)
    T->right= insert(a,T->right);
   else
    T->left= insert(a,T->left);
   return T;
}


struct node* delete(int a, struct node* T)               //delete a node from the bst
{
    if(a< T->val)
     T->left=delete(a,T->left);
    else if(a> T->val)
     T->right=delete(a,T->right);
    else if(T->left && T->right)
     {
      t= findmin(T->right);
      T->val=t->val;
      T->right=delete(T->val,T->right);
     }
    else
    {
     if(T==root)
     {
     t=root;
     if(t->left == NULL)
       root=T->right;
     else if(T->right ==NULL)
      root= T->left;
     free(t);
     }
     else
     {
     t=T;
      if(T->left == NULL)
       T=T->right;
      else if(T->right ==NULL)
       T= T->left;
     free(t);
     f=1;
     }
    }
 return T;
 }


struct node* findmin(struct node* T)                    //finds minimum value in bst
{
   if(T!=NULL)
      while(T->left!=NULL)
       T=T->left;
   return T;
}


void inorder(struct node* T)                  //inorder traversal in bst
{
   if(T!=NULL)
   {
    inorder(T->left);
    printf("%d ",T->val);
    inorder(T->right);
   }
}


void preorder(struct node* T)                //preorder traversal in bst
{
   if(T!=NULL)
   {
    printf("%d ",T->val);
    preorder(T->left);
    preorder(T->right);
   }
}


void postorder(struct node* T)             //postorder traversal in bst
{
   if(T!=NULL)
   {
    postorder(T->left);
    postorder(T->right);
    printf("%d ",T->val);
   }
}



/*

==================OUTPUT====================

BST OPERATIONS 
 1.INSERT 
 2.DELETE 
 3.INORDER 
 4.PREORDER 
 5.POSTORDER 
 6.EXIT

 Enter your choice : 1
Enter the value to be added : 10

 Enter your choice : 1
Enter the value to be added : 5

 Enter your choice : 1
Enter the value to be added : 20

 Enter your choice : 1
Enter the value to be added : 3

 Enter your choice : 1
Enter the value to be added : 7

 Enter your choice : 1
Enter the value to be added : 14

 Enter your choice : 1
Enter the value to be added : 23

 Enter your choice : 1
Enter the value to be added : 1

 Enter your choice : 1
Enter the value to be added : 4

 Enter your choice : 1
Enter the value to be added : 6

 Enter your choice : 3
INORDER TRAVERSAL IS :  1 3 4 5 6 7 10 14 20 23 
 Enter your choice : 4
PREORDER TRAVERSAL IS :  10 5 3 1 4 7 6 20 14 23 
 Enter your choice : 5
POSTORDER TRAVERSAL IS :  1 4 3 6 7 5 14 23 20 10 
 Enter your choice : 2
Enter the element to be deleted 20
Element deleted: 20

 Enter your choice : 3
INORDER TRAVERSAL IS :  1 3 4 5 6 7 10 14 23 
 Enter your choice : 2
Enter the element to be deleted5
Element deleted: 5

 Enter your choice : 3
INORDER TRAVERSAL IS :  1 3 4 6 7 10 14 23 
 Enter your choice : 6




BST OPERATIONS 
 1.INSERT 
 2.DELETE 
 3.INORDER 
 4.PREORDER 
 5.POSTORDER 
 6.EXIT

 Enter your choice : 1
Enter the value to be added : 10

 Enter your choice : 1
Enter the value to be added : 5

 Enter your choice : 1
Enter the value to be added : 20

 Enter your choice : 1
Enter the value to be added : 3

 Enter your choice : 1
Enter the value to be added : 7

 Enter your choice : 1
Enter the value to be added : 14

 Enter your choice : 1
Enter the value to be added : 23

 Enter your choice : 1
Enter the value to be added : 1

 Enter your choice : 1
Enter the value to be added : 4

 Enter your choice : 1
Enter the value to be added : 6

 Enter your choice : 3
INORDER TRAVERSAL IS :  1 3 4 5 6 7 10 14 20 23 
 Enter your choice : 4
PREORDER TRAVERSAL IS :  10 5 3 1 4 7 6 20 14 23 
 Enter your choice : 5
POSTORDER TRAVERSAL IS :  1 4 3 6 7 5 14 23 20 10 
 Enter your choice : 2
Enter the element to be deleted 20
Element deleted: 20

 Enter your choice : 3
INORDER TRAVERSAL IS :  1 3 4 5 6 7 10 14 23 
 Enter your choice : 2
Enter the element to be deleted5
Element deleted: 5

 Enter your choice : 3
INORDER TRAVERSAL IS :  1 3 4 6 7 10 14 23 
 Enter your choice : 6

*/


