/*
BINU S
ROLL NO.: 64
EXPERIMENT NO.: 18
DATE: 12-03-2015
ADDITION OF POLINOMIALS USING LINKEDLIST
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
void add(node* pol1, node *pol2, node *sum);
void show(node* pol);

int main()
 {
	node *pol1, *pol2, *sum;

	pol1=new_node();
	pol2=new_node();
	sum=new_node();

	read(pol1);
	read(pol2);

	add(pol1, pol2, sum);

	printf("THE FIRST POLINAMIAL IS: ");
	show(pol1);
	printf("THE SECOND POLINAMIAL IS: ");
	show(pol2);
	printf("THE RESULTANT POLINAMIAL IS: ");
	show(sum);
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

void add(node* pol1, node *pol2, node *sum)
 {
	node *ptr1, *ptr2, *ptr, *temp;

	ptr1= pol1->next;
	ptr2= pol2->next;
	ptr= sum;

	while(ptr1!=NULL && ptr2!=NULL)
	 {
		temp=new_node();

		if(ptr1->exp > ptr2->exp)
		 {
			temp->coeff=ptr1->coeff;
			temp->exp=ptr1->exp;

			ptr->next=temp;
			ptr=temp;
			ptr1=ptr1->next;
		 }
		if(ptr1->exp < ptr2->exp)
		 {
			temp->coeff=ptr2->coeff;
			temp->exp=ptr2->exp;

			ptr->next=temp;
			ptr=temp;
			ptr2=ptr2->next;
		 }
		else
		 {
			temp->coeff=ptr1->coeff + ptr2->coeff;
			temp->exp=ptr1->exp;

			if(temp->coeff!=0)
			 {
				ptr->next=temp;
				ptr=temp;
			 }

			else
				free(temp);

			ptr1=ptr1->next;
			ptr2=ptr2->next;
		 }
	 }

	while(ptr1!=NULL)
	 {
		ptr->next=new_node();
		ptr=ptr->next;

		ptr->coeff=ptr1->coeff;
		ptr->exp=ptr1->exp;

		ptr1=ptr1->next;
	 }

	while(ptr2!=NULL)
	 {
		ptr->next=new_node();
		ptr=ptr->next;

		ptr->coeff=ptr2->coeff;
		ptr->exp=ptr2->exp;

		ptr2=ptr2->next;
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
