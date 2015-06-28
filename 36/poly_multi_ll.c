/*
	Ex No. 20
	Multiplication of two polynomials using linked list
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
void product(struct node *A, struct node *B, struct node** P);
void display(struct node *start);
void read(struct node **A, int n);

int main()
{
	int n;
	struct node *A, *B, *pdt;
	A = B = pdt = NULL;
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
	product(A, B, &pdt);
	printf("\n Product is: ");
	display(pdt);
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

void product(struct node *A, struct node *B, struct node **P)
{
	struct node *t;
	for(;A != NULL; A = A->next)
		for(t = B; t != NULL; t = t->next)
			insert(t->coeff * A->coeff, t->exp + A->exp, P);
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

/*		SAMPLE OUTPUT

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
