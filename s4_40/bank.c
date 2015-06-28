/*
	Ex.NO:08
	Tocken Processing in a Bank
	MUHAMMED THABJEEL
	S4 R 40
	23/02/2015
*/
#include<stdio.h>
#include<malloc.h>
#define MAX 5
struct customer{
		int no;
		char name[30];
		char sex ;
		struct customer *next;
		};
typedef struct customer customer;
void add(),dlt(),display();
int count=0,curr=0;
customer *front=NULL,*rear=NULL;
int main()
{
	int ch=0,falg=0;
	while(ch!=4){
			printf("chose your option..!\n");
			printf("1.Add a customer\t2.Remove customer\t3.Display\t4.Exit\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					add();
					break;
				case 2:
					dlt();
					break;
				case 3:
					display();
					break;
				case 4:
					break;
				default:
					printf("You've entered wrong option, please try again.........!\n");
			}
	}
	}
void add()
	{
		customer *temp;
		temp=(customer*)malloc(sizeof(customer));
		if(temp==NULL)
				printf("Memory full...Unable to add\n");
		else{
			if(front==NULL){
					front=temp;
					rear=temp;
					}
			else{
				temp->next=NULL;
				rear->next=temp;
				rear=temp;
				}
				printf("Enter the name of the customer\n");
				scanf(" %[^\n]",temp->name);
				printf("Enter the account number of %s\n",temp->name);
				scanf("%d",&temp->no);
				printf("Enter the Gender(M or F)\n");
				scanf(" %c",&temp->sex);
				printf("Account number %d is added to queue as Tocken no. %d\n",temp->no,++count);
				printf("Number of customers remaining in the queue: %d\n",++curr);
			}
	}
void dlt()
	{
		customer *temp;
		temp=(customer*)malloc(sizeof(customer));
		if(rear==NULL)
			printf("Queue is Empty...!\n");
		else{
			temp=front;
			printf("Account number %d is removed from the queue\n",temp->no);
			printf("Number of customers remaining in the queue: %d\n",--curr);
			free(front);
			front=temp->next;
			}
	}
void display()
	{
		if(front==NULL)
			printf("Queue is Empty....!\n");
		else{
			printf("DETAILS OF THE CURRENT CUSTOMER\n");
			printf("NAME:\t%s\n",front->name);
			printf("Ac.No:\t%d\n",front->no);
			printf("Gender:\t%c\n",front->sex);
			}
	}
/*
***************SAMPLE OUTPUT*************

chose your option..!
1.Add a customer	2.Remove customer	3.Display	4.Exit
1
Enter the name of the customer
Michel jackson
Enter the account number of Michel jackson
1001
Enter the Gender(M or F)
M
Account number 1001 is added to queue as Tocken no. 1
Number of customers remaining in the queue: 1
chose your option..!
1.Add a customer	2.Remove customer	3.Display	4.Exit
1
Enter the name of the customer
Wayne Rooney
Enter the account number of Wayne Rooney
1005
Enter the Gender(M or F)
M
Account number 1005 is added to queue as Tocken no. 2
Number of customers remaining in the queue: 2
chose your option..!
1.Add a customer	2.Remove customer	3.Display	4.Exit
3
DETAILS OF THE CURRENT CUSTOMER
NAME:	Michel jackson
Ac.No:	1001
Gender:	M
chose your option..!
1.Add a customer	2.Remove customer	3.Display	4.Exit
2
Account number 1001 is removed from the queue
Number of customers remaining in the queue: 1
chose your option..!
1.Add a customer	2.Remove customer	3.Display	4.Exit
3
DETAILS OF THE CURRENT CUSTOMER
NAME:	Wayne Rooney
Ac.No:	1005
Gender:	M
chose your option..!
1.Add a customer	2.Remove customer	3.Display	4.Exit
2
Account number 1005 is removed from the queue
Number of customers remaining in the queue: 0
chose your option..!
1.Add a customer	2.Remove customer	3.Display	4.Exit
4

*/
