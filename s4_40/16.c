/*
BINU S
ROLL NO.: 64
EXPERIMENT NO.: 16
DATE: 04-03-2015
IMPLEMENTATION OF CIRCULAR LINKEDLIST
*/

#include<stdio.h>
#include<stdlib.h>

struct node
 {
	int val;
	struct node* next;
 };

typedef struct node node;

void ins_end(node* header, int nw);
void ins_key(node* header, int key, int nw);
int del_key(node* header, int key, int *val);
void display(node* header, int index);
int isempty(node* header);
node* new_node();

int main()
 {
	node* header=new_node();
	header->next=header;

        printf( "  MENU  "
                "\n^^^^^^^^"
		"\n1. INSERT AT END"
		"\n2. INSERT AFTER KEY"
		"\n3. DELETE KEY"
		"\n4. DISPLAY"
		"\n5. DISPLAY FROM NODE NUMBER"
		"\n6 .EXIT");

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
                        case 2: printf("ENTER THE NEW VALUE, KEY: ");
                                scanf("%d %d", &new, &key);
                                ins_key(header, key, new);
                                break;
                        case 3: printf("ENTER THE KEY: ");
                                scanf("%d", &key);
				if(isempty(header))
					printf("LINKEDLIST EMPTY....\n");
				else if(!del_key(header, key, &val))
                                        printf("KEY NOT FOUND...\n");
                                else
                                        printf("THE REMOVED ELEMENT IS %d\n",val);
                                break;
                        case 4: display(header, 1);
                                break;
                        case 5: printf("ENTER THE INDEX: ");
                                scanf("%d", &key);
				display(header, key);
                                break;
			case 6: exit(0);
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
		return ptr;
 }

void ins_end(node *header, int nw)
 {
	node *pptr, *nptr;

	nptr=header->next;
	pptr=header;

	while(nptr!=header)
	 {
		pptr=nptr;
		nptr=nptr->next;
	 }

	node *ptr=new_node();
	ptr->val=nw;
	ptr->next=nptr;
	pptr->next=ptr;
 }

void ins_key(node *header, int key, int nw)
 {
	node *pptr=header->next;

	while(pptr!=header && pptr->val!=key)
		pptr=pptr->next;

	if(pptr==header)
		printf("KEY NOT FOUND....\n");
	else
	 {
		node* ptr=new_node();
		ptr->val=nw;
		ptr->next=pptr->next;
		pptr->next=ptr;
	 }
 }


int del_key(node* header, int key, int *val)
 {
	node *ptr, *pptr;

	pptr= header;
	ptr= header->next;

	while(ptr!=header && ptr->val!=key)
	 {
		pptr=ptr;
		ptr=ptr->next;
	 }

	if(ptr==NULL)
		return 0;
	else
	 {
		pptr->next=ptr->next;
		*val=ptr->val;
		free(ptr);
		return 1;
	 }
 }

int isempty(node* header)
 {
	return (header->next==header);
 }

void display(node* header, int index)
 {
	if(isempty(header))
	 {
		printf("CIRCULAR LINKEDLIST EMPTY...\n");
		return;
	 }

	node* start=header;

	while(index--)
	 {
		start=start->next;
		if(start==header)
		 {
			printf("INDEX INVALID....\n");
			return;
		 }
	 }

	node* ptr=start;

	printf("ELEMENTS IN THE LINKEDLIST ARE: ");

	do
	 {
		printf("%d  ", ptr->val);
		ptr=ptr->next;
		if(ptr==header)
		 {
			ptr=ptr->next;
		 }
	 }while(ptr!=start);

	printf("\n");

 }
