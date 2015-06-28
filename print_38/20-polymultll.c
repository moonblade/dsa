/*
    Ex 20
    Polynomial Multiplcation with linked list
    20-03-15
    S4 R 38 Mohammed Nisham K
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
printf("Polynomial 1 :  ");
display(h1);
printf("Polynomial 2 :  ");
display(h2);
printf("Result is : ");
display(h3);
return 0;
}

//read polynomial
struct node* read(struct node* h)
{
 int i,n;
 printf("Enter the number of terms : ");
 scanf("%d",&n);
 printf("Enter polynomial\n");
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

//display polynomial
void display(struct node* h)
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

//multiply polynomials
struct node* mult(struct node* h1,struct node* h2)
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
OUTPUT

Enter the number of terms :  3
Enter polynomial
3 2
2 1
4 0
Enter the number of terms : 2
Enter polynomial
4 2
5 1
Polynomial 1 :  3X^2  + 2X + 4
Polynomial 2 :  4X^2  + 5X^1 
Result is:  12X^4  + 23X^3  + 26X^2  + 20X^1 



Enter the number of terms : 2
Enter polynomial
2 1 
-2 0
Enter the number of terms : 2
Enter polynomial
2 1
2 0
Polynomial 1:  2X-2
Polynomial 2:  2X + 2
Result is:  4X^2 -4

*/
