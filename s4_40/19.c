/*
BINU S
ROLL NO.: 64
EXPERIMENT NO.: 19
DATE: 19-03-2015
MULTIPLICATION OF POLINOMIALS USING ARRAY
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct
 {
	int coeff;
	int exp;
 } term;

void read(term pol[], int *n);
void mult(term pol1[], term pol2[], term prod[], int n1, int n2, int *n);
void show(term pol[], int n);

int main()
 {
	int n1, n2, n;
	term pol1[MAX], pol2[MAX], prod[MAX];

	read(pol1, &n1);
	read(pol2, &n2);

	mult(pol1, pol2, prod, n1, n2, &n);

        printf("THE FIRST POLINAMIAL IS: ");
	show(pol1, n1);
        printf("THE SECOND POLINAMIAL IS: ");
	show(pol2, n2);
        printf("THE RESULTANT POLINAMIAL IS: ");
	show(prod, n);

	return 0;
 }

void read(term pol[], int *n)
 {
	printf("ENTER THE NUMBER OF TERMS: ");
	scanf("%d", n);

	printf("ENTER THE TERMS IN DESCENDING ORDER OF EXP \'coeff,exp\': \n");

	int i;
	for(i=0; i!=*n; ++i)
		scanf("%d,%d", &pol[i].coeff, &pol[i].exp);
 }


void mult(term pol1[], term pol2[], term prod[], int n1, int n2, int *n)
 {
	term temp, next;

	int i, j, k;
	*n=0;

	for(i=0; i!=n1; ++i)
	 {
		for(j=0; j!=n2; ++j)
		 {
			next.coeff= pol1[i].coeff * pol2[j].coeff;
			next.exp  = pol1[i].exp   + pol2[j].exp;

			k=0;
			while(k!=*n && prod[k].exp > next.exp)
				k++;

			if(prod[k].exp==next.exp)
			 {
				prod[k].coeff += next.coeff;

				if(prod[k].coeff==0)
				 {
					while(k!= (*n)-1)
					 {
						prod[k]=prod[k+1];
					 }

					*n = *n-1;
				 }
			 }

			else
			 {
				while(k!=*n)
				 {
					temp=prod[k];
					prod[k]=next;
					next=temp;

					k++;
				 }

				prod[*n]=next;

				*n = *n+1;
			 }
		 }
	 }
 }

void show(term pol[], int n)
 {
        int i;

        if(n==0)
                printf("0");

        for(i=0; i<n; ++i)
         {
                printf("%d X^ %d", pol[i].coeff, pol[i].exp);

                if(i != n-1)
                        printf(" + ");
         }

        printf("\n");
 }

