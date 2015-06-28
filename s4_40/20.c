/*
BINU S
ROLL NO.: 64
EXPERIMENT NO.: 20
DATE: 18-03-2015
MULTIPLICATION OF POLINOMIALS USING LINKEDLIST
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct node
 {
	int coeff, exp;
	struct node *next;
 };

typedef struct node node;

node* new_node();
void read(node* beg);
void mult(node* pol1, node *pol2, node *prod);
void show(node* pol);

int main()
 {
	node *pol1, *pol2, *prod;

	pol1=new_node();
	pol2=new_node();
	prod=new_node();

	read(pol1);
	read(pol2);

	mult(pol1, pol2, prod);

	printf("THE FIRST POLINAMIAL IS: ");
	show(pol1);
	printf("THE SECOND POLINAMIAL IS: ");
	show(pol2);
	printf("THE RESULTANT POLINAMIAL IS: ");
	show(prod);
 }

node* new_node()
 {
	node *ptr= (node*) malloc(sizeof(node));

	if(ptr==NULL)
	 {
		printf("MEMORY NOT AVAILABLE...\n");
		exit(1);
	 }

	else
	 {
		ptr->next=NULL;
		return ptr;
	 }
 }

void read(node* header)
 {
	int n;
	printf("ENTER THE NUMBER OF TERMS: ");
	scanf("%d", &n);

	printf("ENTER THE ELEMENTS (IN THE FORM \"CO-EFF,EXP\" IN THE DESCENDING ORDER OF EXPONENTS:\n");

	node *temp;
	node *ptr=header;

	int i;
	for(i=0; i!=n; ++i)
	 {
		temp=new_node();
		scanf("%d,%d", &temp->coeff, &temp->exp);

		ptr->next=temp;
		ptr=temp;
	 }
 }

void mult(node* pol1, node *pol2, node *prod)
 {
	node *ptr1, *ptr2, *ptr, *pptr, *temp;

	ptr1= pol1->next;

	while(ptr1!=NULL)
	 {
		ptr2= pol2->next;

		while(ptr2!=NULL)
		 {
			temp=new_node();
			temp->coeff= (ptr1->coeff) * (ptr2->coeff);
			temp->exp  = (ptr1->exp) + (ptr2->exp);

			pptr=prod;
			ptr=prod->next;

			while(ptr!=NULL && ptr->exp>temp->exp)
			 {
				pptr=ptr;
				ptr=ptr->next;
			 }

			if(ptr==NULL || ptr->exp<temp->exp)
			 {
				pptr->next=temp;
				temp->next=ptr;
			 }

			else
			 {
				ptr->coeff = (ptr->coeff) + (temp->coeff);
				free(temp);

				if(ptr->coeff == 0)
				 {
					pptr->next = ptr->next;
					free(ptr);
				 }
			 }

			ptr2=ptr2->next;
		 }

		ptr1=ptr1->next;
	 }
 }

void show(node* header)
 {
	node* ptr=header->next;

	if(ptr==NULL)
		printf("0");

	while(ptr != NULL)
	 {
		printf("%d X^ %d", ptr->coeff, ptr->exp);

		ptr=ptr->next;

		if(ptr!=NULL)
			printf(" + ");
	 }

	printf("\n");
 }
