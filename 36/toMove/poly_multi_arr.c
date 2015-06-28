/*
   Ex No. 19
   Multiplication of two polynomials using array
   S4R 036 Mohamed Insaf K
   07/04/2015
*/

#include <stdio.h>

#define MAX 500
void read(int A[], int n);
void display(int A[]);
void multiply(int A[], int B[], int C[]);


int main(void)
{
   int A[MAX] = {0};
   int B[MAX] = {0};
   int C[MAX + MAX] = {0};
   int n1, n2;
   printf("Enter number of terms in the first polynomial: ");
   scanf("%d", &n1);
   read(A, n1);
   printf("The polynomial you have entered is: ");
   display(A);
   printf("Enter number of terms in the second polynomial: ");
   scanf("%d", &n2);
   read(B, n2);
   printf("The polynomial you have entered is: ");
   display(B);
   multiply(A, B, C);
   printf("\n\nProduct of the two polynomials is: ");
   display(C);
   return 0;
}


void read(int A[], int n)
{
   int i, coeff, exp;
   for(i = 0; i<n; ++i)
   {
      printf("Enter coeff and exp: ");
      scanf("%d%d", &coeff, &exp);
      A[exp] = coeff;
   }
}

void display(int A[])
{
   int i;
   for(i = MAX - 1; i > 0; --i)
      if(A[i] != 0)
         printf("%dx^%d + ", A[i], i);
   if(A[0] != 0)
      printf("%d", A[0]);
   printf("\n");
}

void multiply(int A[], int B[], int C[])
{
   int i,j;
   for(i = 0; i < MAX; ++i)
      if(A[i] != 0)
         for(j = 0; j< MAX; ++j)
            if(B[j] != 0)
               C[i+j] = A[i] * B[j];
}

/*      SAMPLE OUTPUT

Enter number of terms in the first polynomial: 3
Enter coeff and exp: 7 5
Enter coeff and exp: 5 2
Enter coeff and exp: -3 0
The polynomial you have entered is: 7x^5 + 5x^2 + -3
Enter number of terms in the second polynomial: 4
Enter coeff and exp: 8 7
Enter coeff and exp: -2 5
Enter coeff and exp: 1 4
Enter coeff and exp: 2 1
The polynomial you have entered is: 8x^7 + -2x^5 + 1x^4 + 2x^1 + 


Product of the two polynomials is: 56x^12 + -14x^10 + 7x^9 + -10x^7 + 14x^6 + 6x^5 + -3x^4 + 10x^3 + -6x^1 + 

*/
