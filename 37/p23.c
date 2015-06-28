/*
    EXPT NO.23
    BINARY SEARCH TREE
    27-03-15
    S4R-37 mohammed jasim e
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
struct node* findmin(struct node* T);
struct node* findmax(struct node* T);
void inorder(struct node* T);
int numnode(struct node* T);
int singlechild(struct node* T);
int leafnode(struct node* T);
int f;
int main()
{
 int c,b;
 root = NULL;
 printf("BST OPERATIONS \n 1.INSERT \n 2.DELETE \n 3.INORDER \n 4.FIND MAX \n 5.FIND MIN \n 6.NUMBER OF NODES \n 7.NUMBER OF LEAF NODES\n 8.NODES HAVING ONLY SINGLE CHILD \n 9.EXIT\n");
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
              printf("\nBST EMPTY");
             else
             {
             t=findmax(root);
             printf("MAXIMUM VALUE : %d ",t->val);
             }
              break;
     case 5: if(root==NULL)
              printf("\nBST EMPTY");
             else
             {
             t=findmin(root);
             printf("MINIMUM VALUE : %d ",t->val);
             }
              break;
     case 6:
              b=numnode(root);
              printf("NUMBER OF NODES : %d ",b);
             break;
     case 7:
             b=leafnode(root);
             printf("NUMBER OF LEAF NODES : %d ",b);
             break;
     case 8:
             b=singlechild(root);
             printf("NUMBER OF NODES WITH SINGLE CHILD : %d ",b);
             break;
     case 9: return;
      default: printf("Invalid entry\n");
               break;
     }
    }while(1);
  return 0;
}


struct node* insert(int a,struct node* T)            //insert a new node into the BST
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


struct node* delete(int a, struct node* T)               //delete a node from the BST
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


struct node* findmin(struct node* T)                    //finds minimum value in BST
{
   if(T!=NULL)
      while(T->left!=NULL)
       T=T->left;
   return T;
}


struct node* findmax(struct node* T)                    //finds maximum value in BST
{
   if(T!=NULL)
      while(T->right!=NULL)
       T=T->right;
   return T;
}


int numnode(struct node* T)                            //finds number of nodes in BST
{
 if(T==NULL)
  return 0;
 else
 return(1+numnode(T->right)+numnode(T->left));
}


int leafnode(struct node* T)                           //finds number of leafnodes in BST
{
 if(T==NULL)
  return 0;
 else if(T->left == NULL && T->right==NULL)
  return 1;
 else
 return(leafnode(T->right)+leafnode(T->left));
}


int singlechild(struct node* T)                           //finds nodes with a single child in BST
{
 if(T==NULL)
  return 0;
 int a,b,c;
 a=0;
 b=0;
 if(T->left!=NULL)
   a=1;
 if(T->right!=NULL)
   b=1;
  c=(a+b)%2;
  return(c+singlechild(T->right) + singlechild(T->left));

}


void inorder(struct node* T)                           //inorder traversal in BST
{
 if(T!=NULL)
 {
  inorder(T->left);
  printf("%d ",T->val);
  inorder(T->right);
 }
}





/*

====================OUTPUT=====================

BST OPERATIONS 
 1.INSERT 
 2.DELETE 
 3.INORDER 
 4.FIND MAX 
 5.FIND MIN 
 6.NUMBER OF NODES 
 7.NUMBER OF LEAF NODES
 8.NODES HAVING ONLY SINGLE CHILD 
 9.EXIT

 Enter your choice : 1
Enter the value to be added : 1

 Enter your choice : 1
Enter the value to be added : 3

 Enter your choice : 1
Enter the value to be added : 5

 Enter your choice : 1
Enter the value to be added : 6

 Enter your choice : 1
Enter the value to be added : 9

 Enter your choice : 3
INORDER TRAVERSAL IS :  1 3 5 6 9 
 Enter your choice : 4
MAXIMUM VALUE : 9 
 Enter your choice : 5
MINIMUM VALUE : 1 
 Enter your choice : 6
NUMBER OF NODES : 5 
 Enter your choice : 7
NUMBER OF LEAF NODES : 1 
 Enter your choice : 8
NUMBER OF NODES WITH SINGLE CHILD : 4 
 Enter your choice : 2
Enter the element to be deleted 1

 Enter your choice : 3
INORDER TRAVERSAL IS :  3 5 6 9 
 Enter your choice : 4
MAXIMUM VALUE : 9 
 Enter your choice : 5
MINIMUM VALUE : 3 
 Enter your choice : 6
NUMBER OF NODES : 4 
 Enter your choice : 7
NUMBER OF LEAF NODES : 1 
 Enter your choice : 8
NUMBER OF NODES WITH SINGLE CHILD : 3 
 Enter your choice : 9



BST OPERATIONS 
 1.INSERT 
 2.DELETE 
 3.INORDER 
 4.FIND MAX 
 5.FIND MIN 
 6.NUMBER OF NODES 
 7.NUMBER OF LEAF NODES
 8.NODES HAVING ONLY SINGLE CHILD 
 9.EXIT

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
MAXIMUM VALUE : 23 
 Enter your choice : 5
MINIMUM VALUE : 1 
 Enter your choice : 6
NUMBER OF NODES : 10 
 Enter your choice : 7
NUMBER OF LEAF NODES : 5 
 Enter your choice : 8
NUMBER OF NODES WITH SINGLE CHILD : 1 
 Enter your choice : 9

*/

