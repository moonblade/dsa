/*
    EXPT NO.18
    POLYNOMIAL ADDITION USING  LINKEDLIST
    26-03-15
    S4R-37   mohammed jasim e
*/
#include<stdlib.h>
#include<stdio.h>
#define max 20
struct node{
   int coeff;
   int pow;
   struct node *next;
 }*h1,*h2,*h3,*new,*temp,*temp2,*temp3,*t1,*t;
struct node* read(struct node* h);
void display(struct node* h);
struct node* add(struct node* h1,struct node* h2);
struct node* priority(struct node* h1,struct node* temp2);
int main()
{
h1=NULL;
h2=NULL;
h3=NULL;
h1=read(h1);
h2=read(h2);
printf("POLYNOMIAL 1 IS :  ");
display(h1);
printf("POLYNOMIAL 2 IS :  ");
display(h2);
h3=add(h1,h2);
printf("ADDITION POLYNOMIAL IS : ");
display(h3);
return 0;
}


struct node* read(struct node* h)          //reads a polynomial
{
 int i,n;
 printf("Enter the number of terms in the polynomial ");
 scanf("%d",&n);
 printf("Enter the coefficients and powers of polynomial ");
  new = (struct node*)malloc(sizeof(struct node));
  scanf("%d",&(new->coeff));
  scanf("%d",&(new->pow));
  new->next=NULL;
  h=new;
  temp=h;
 for(i=1;i<n;i++)
  {
  new = (struct node*)malloc(sizeof(struct node));
  scanf("%d",&(new->coeff));
  scanf("%d",&(new->pow));
  new->next=NULL;
  temp->next=new;
  temp=new;
  }
return h;
}



void display(struct node* h)          //displays the polynomial
{
for(temp=h;temp->next!=NULL;temp=temp->next)
 {
  if(temp->coeff==0)
    continue;
  if(temp->coeff!=1)
    printf("%d",temp->coeff);
  if(temp->pow==1)
    printf("X");
  else if(temp->pow!=0)
    printf("X^%d",temp->pow);
  if((temp->next->coeff)>0)
    printf(" + ");
 }
 printf("%d",temp->coeff);
  if(temp->pow==1)
    printf("X");
   else if(temp->pow!=0)
  printf("X^%d",temp->pow);
printf("\n");
}



struct node* priority(struct node* h1,struct node* temp2)        //checks the priority
{
 int c;
 t1=h1;
 new = (struct node*) malloc(sizeof(struct node));
 new->coeff=temp2->coeff;
 new->pow=temp2->pow;
 c=temp2->pow;
   if(c>t1->pow)
    {
     new->next=h1;
     h1=new;
     return h1;
    }
    else
     {
      t=h1;
      while(c<t->pow && t->next!= NULL && c<t->next->pow)
        t=t->next;
      if(t->next==NULL)
      {
       t->next=new;
       new->next = NULL;
       return h1;
       }
      new->next=t->next;
      t->next=new;
     }
     return h1;
  }


struct node* add(struct node* h1,struct node* h2)        //adds two polynomial
{
 temp=h1;
 temp2=h2;
 while(temp2!=NULL)
  {
   int f;
   f=0;
   temp=h1;
   while(temp!=NULL)
   {
    if(temp->pow==temp2->pow)
    {
      temp->coeff=temp->coeff + temp2->coeff;
      f=1;
      break;
    }
   temp=temp->next;
   }
   if(f==0)
   h1=priority(h1,temp2);
   temp2=temp2->next;
  }
 return h1;
}


/*
 ======================OUTPUT========================

Enter the number of terms in the polynomial 3
Enter the coefficients and powers of polynomial 
3 3 
2 2
5 0
Enter the number of terms in the polynomial 3
Enter the coefficients and powers of polynomial 
6 4
5 2
3 1
POLYNOMIAL 1 IS :  3X^3 + 2X^2 + 5
POLYNOMIAL 2 IS :  6X^4 + 5X^2 + 3X
ADDITION POLYNOMIAL IS : 6X^4 + 3X^3 + 7X^2 + 3X + 5


Enter the number of terms in the polynomial 3
Enter the coefficients and powers of polynomial 
4 3 
5 1
9 0
Enter the number of terms in the polynomial 
2
Enter the coefficients and powers of polynomial 
5 8
4 1
POLYNOMIAL 1 IS :  4X^3 + 5X + 9
POLYNOMIAL 2 IS :  5X^8 + 4X
ADDITION POLYNOMIAL IS : 5X^8 + 4X^3 + 9X + 9

*/

