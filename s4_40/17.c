/*
BINU S
ROLL NO.: 64
EXPERIMENT NO.: 17
DATE: 12-03-2015
INSERTION AND DELETION INTO DOUBLY LINKED LIST
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct node
 {
        int val;
        struct node *next;
	struct node *prev;
 };

typedef struct node node;

void ins_end(node* header, int nw);
int del_key(node* header, int key, int *val);
void display(node* header);
int isempty(node* header);
node* new_node();

int main()
 {
        node* header=new_node();

        printf( "  MENU  "
                "\n^^^^^^^^"
                "\n1. INSERT AT END"
                "\n2. DELETE KEY"
                "\n3. DISPLAY"
                "\n4 .EXIT");

        int new, key, op, val;

        do
         {
                printf("\nENTER YOUR OPTION: ");
                scanf("%d", &op);

                switch(op)
                 {
                        case 1: printf("ENTER THE NEW VALUE: ");
                                scanf("%d", &new);
                                ins_end(header, new);
                                break;
                        case 2: printf("ENTER THE KEY: ");
                                scanf("%d", &key);
                                if(isempty(header))
                                        printf("LINKEDLIST EMPTY....\n");
                                else if(!del_key(header, key, &val))
                                        printf("KEY NOT FOUND...\n");
                                else
                                        printf("THE REMOVED ELEMENT IS %d\n",val);
                                break;
                        case 3: display(header);
                                break;
                        case 4: exit(0);
                        default:printf("WRONG INPUT.....\n");
                 }
         }while(1);

 }

node* new_node()
 {
        node *ptr= (node*)malloc(sizeof(node));

        if(ptr==NULL)
         {
                printf("MEMORY UNAVAILABLE...\n");
                exit(1);
         }

        else
	 {
		ptr->next= ptr->prev= NULL;
                return ptr;
	 }
 }

void ins_end(node* header, int nw)
 {
	node *pptr=header;

	while(pptr->next!=NULL)
		pptr=pptr->next;

	node *ptr=new_node();
	ptr->val=nw;
	ptr->prev=pptr;
	pptr->next=ptr;
 }

int del_key(node* header, int key, int *val)
 {
	node *ptr=header->next;

	while(ptr!=NULL && ptr->val!=key)
		ptr=ptr->next;

	if(ptr==NULL)
		return 0;

	else
	 {
		node *pptr, *nptr;
		nptr= ptr->next;
		pptr= ptr->prev;

		pptr->next=nptr;

		if(nptr!=NULL)
			nptr->prev=pptr;

		*val=ptr->val;
		free(ptr);
		return 1;
	 }
 }

void display(node* header)
 {
	if(isempty(header))
	 {
		printf("THE LISTIS EMPTY...\n");
		return;
	 }

	node *pptr, *ptr;
	pptr=header;
	ptr=header->next;

	printf("THE LIST FROM THE FRONT: ");

	while(ptr!=NULL)
	 {
		printf("%d  ", ptr->val);

		pptr=ptr;
		ptr=ptr->next;
	 }

	ptr=pptr;

	printf("\nTHE LIST FROM THE REAR: ");

	while(ptr!=header)
	 {
		printf("%d  ", ptr->val);

		ptr=ptr->prev;
	 }

	printf("\n");
 }

int isempty(node* header)
 {
	return (header->next==NULL);
 }
