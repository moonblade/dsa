/*
   Ex No. 18
   Addition of two polynomials using linked list
   S4R 036 Mohamed Insaf
   06/04/2015
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
   int coeff;
   int exp;
   struct node *next;
};

void insert(int coeff, int exp, struct node** start);
void sum(struct node *A, struct node *B, struct node** S);
void display(struct node *start);
void read(struct node **A, int n);

int main()
{
   int n;
   struct node *A, *B, *SUM;
   A = B = SUM = NULL;
   printf("Enter number of terms: ");
   scanf("%d", &n);
   read(&A, n);
   printf("\nPolynomial is: ");
   display(A);
   printf("Enter number of terms: ");
   scanf("%d", &n);
   read(&B, n);
   printf("\nPolynomial is: ");
   display(B);
   sum(A, B, &SUM);
   printf("\n Sum is: ");
   display(SUM);
   return 0;
}

void insert(int coeff, int exp, struct node** start)
{
   struct node *n, *temp;
   n = (struct node *)malloc(sizeof(struct node));
   n->coeff = coeff;
   n->exp = exp;
   n->next = NULL;
   if(!*start)
      *start = n;
   else if( n->exp >= (*start)->exp)
   {
      if( n->exp == (*start)->exp )
      {
         (*start)->coeff += n->coeff;
         free(n);
      }
      else
      {
         n->next = *start;
         *start = n;
      }
   }
   else
   {
      for(temp = *start; temp->next != NULL && (temp->next)->exp > n->exp; temp = temp->next);
      if(temp->next != NULL && (temp->next)->exp == n->exp) //Same exponential, so add coeff
      {
         temp = temp->next;
         temp->coeff += n->coeff;
         free(n); // n is not inserted into the list, so freeing it
      }
      else
      {
         n->next = temp->next;
         temp->next = n;
      }
   }
}

void sum(struct node *A, struct node *B, struct node** S)
{
   while(A != NULL && B != NULL)
   {
      if(A->exp < B->exp)
      {
         insert(A->coeff, A->exp, S);
         A = A->next;
      }
      else if(A->exp > B->exp)
      {
         insert(B->coeff, B->exp, S);
         B = B->next;
      }
      else
      {
         insert(A->coeff + B->coeff, A->exp, S);
         A = A->next;
         B = B->next;
      }
   }
   while(A != NULL)
   {
      insert(A->coeff, A->exp, S);
      A = A->next;
   }
   while(B != NULL)
   {
      insert(B->coeff, B->exp, S);
      B = B->next;
   }
}

void display(struct node *start)
{
   struct node *temp = start;
   while( (temp->next) != NULL)
   {
      printf("%dx^%d + ", temp->coeff, temp->exp);
      temp = temp->next;
   }
   if(temp->exp == 0)
      printf("%d", temp->coeff);
   else
      printf("%dx^%d", temp->coeff, temp->exp);
   printf("\n");
}

void read(struct node **A, int n)
{
   int i, coeff, exp;
   for(i=0; i<n; ++i)
   {
      printf("Enter coeffecient and exponential: ");
      scanf("%d%d", &coeff, &exp);
      insert(coeff, exp, A);
   }
}

/*      SAMPLE OUTPUT

Enter number of terms: 3
Enter coeffecient and exponential: 7 5
Enter coeffecient and exponential: 5 2
Enter coeffecient and exponential: -3 0

Polynomial is: 7x^5 + 5x^2 + -3
Enter number of terms: 4
Enter coeffecient and exponential: 8 7
Enter coeffecient and exponential: -2 5
Enter coeffecient and exponential: 1 4
Enter coeffecient and exponential: 2 1

Polynomial is: 8x^7 + -2x^5 + 1x^4 + 2x^1

 Sum is: 8x^7 + 5x^5 + 1x^4 + 5x^2 + 2x^1 + -3
*/
