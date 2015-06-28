/*
    EXPT NO.20
    POLYNOMIAL MULTIPLICATION USING  LINKEDLIST
    20-03-15
    S4R-37   mohammed jasim e
*/
#include<stdlib.h>
#include<stdio.h>
#define max 20
struct node{
   int coeff;
   int pow;
   struct node *next;
 }*h1,*h2,*h3,*new,*temp,*temp2,*temp3,*t;
struct node* read(struct node* h);
void display(struct node* h);
struct node* mult(struct node* h1,struct node* h2);
int main()
{
h1=NULL;
h2=NULL;
h3=NULL;
h1=read(h1);
h2=read(h2);
h3=mult(h1,h2);
printf("POLYNOMIAL 1 IS :  ");
display(h1);
printf("POLYNOMIAL 2 IS :  ");
display(h2);
printf("MULTIPLIED POLYNOMIAL IS : ");
display(h3);
return 0;
}


struct node* read(struct node* h)                 //read a polynomial
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


void display(struct node* h)            //display a polynomial
{
for(temp=h;temp->next!=NULL;temp=temp->next)
 {
  if(temp->coeff==0)
    continue;
   printf("%d",temp->coeff);
   if(temp->pow==1)
    printf("X");
   else if(temp->pow!=0)
    printf("X^%d ",temp->pow);
   if((temp->next->coeff)>0)
    printf(" + ");
 }
 printf("%d",temp->coeff);
  if(temp->pow!=0)
  printf("X^%d ",temp->pow);
printf("\n");
}


struct node* mult(struct node* h1,struct node* h2)      //multiply two polynomial
{
 temp=h1;
 temp2=h2;
 new = (struct node*)malloc(sizeof(struct node));
 new->coeff=temp->coeff * temp2->coeff;
 new->pow=temp->pow + temp2->pow;
 new->next=NULL;
 h3=new;
 temp3=h3;
 int flag;
 while(temp!=NULL)
 {  temp2=h2;
    while(temp2!=NULL)
    {
     flag=0;
     t=h3;
     while(t!=NULL)
     {
      if(t->pow == temp->pow + temp2->pow)
       {
        t->coeff = t->coeff + (temp->coeff * temp2->coeff);
        flag=1;
        break;
       }
      t=t->next;
     }
      if(flag==0)
       {
        new = (struct node*)malloc(sizeof(struct node));
        new->coeff=temp->coeff * temp2->coeff;
        new->pow=temp->pow + temp2->pow;
        new->next=NULL;
        temp3->next=new;
        temp3=new;
       }
       temp2=temp2->next;
     }
    temp=temp->next;
  }
  h3->coeff=(h3->coeff/2);
 return h3;
 }

/*

==================OUTPUT========================

Enter the number of elements in polynominal 3
Enter coefficients and powers of polynominal
3 2
2 1
4 0
Enter the number of elements in polynominal 2
Enter coefficients and powers of polynominal
4 2
5 1
POLYNOMIAL 1:  3X^2  + 2X + 4
POLYNOMIAL 2:  4X^2  + 5X^1 
MULTIPLIED POLYNOMIAL IS:  12X^4  + 23X^3  + 26X^2  + 20X^1 



Enter the number of elements in polynominal 2
Enter coefficients and powers of polynominal 
2 1 
-2 0
Enter the number of elements in polynominal 2
Enter coefficients and powers of polynominal
2 1
2 0
POLYNOMIAL 1:  2X-2
POLYNOMIAL 2:  2X + 2
MULTIPLIED POLYNOMIAL IS:  4X^2 -4

*/

