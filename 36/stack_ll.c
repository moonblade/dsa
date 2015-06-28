/*
	Ex no. 4
	Implementation of stack using linked list
	S4R 036 Mohamed Insaf K
	11/12/2014
*/

#include <stdio.h>
#include <stdlib.h>

void push(int );
int pop(void);
void display();
int search(int);

struct node{
		int val;
		struct node *next;
	}*s;

int main(void)
{
	int choice, val, pos;
	printf("\n1. Push\n2. Pop\n3. Display\n4. Search\n5. Exit\n");
	do
	{
		printf("Please Choose: ");
		scanf("%d", &choice);
		switch(choice)
		{
			 case 1:
				printf("Enter the value to be pushed\n");
				scanf("%d", &val);
				push(val);
				break;
			case 2:
				if((val=pop())!=-1)
					printf("%d poped\n", val);
				else
					printf("Stack underflow\n");
				break;
			case 3:
				if(s==NULL)
					printf("Stack is empty\n");
				else
					display();
				break;
			case 4:
				if(s==NULL)
					printf("Stack is empty\n");
				else
				{
					printf("Enter the value to be searched\n");
					scanf("%d", &val);
					pos=search(val);
					if(pos==-1)
						printf("Stack is empty\n");
					else if(pos==-2)
						printf("Couldn't find the element in the stack\n");
					else
						printf("Found %d in the stack\n", val);
				}
				break;
			case 5:
				break;
			default:
				printf("Wrong option please try again\n");
		}
	}while(choice !=5);
	return 0;
}

void push(int val)
{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	if(t!=NULL)
	{
		t->val=val;
		t->next=s;
		s=t;
		printf("Successfully pushed %d to the stack\n", val);
	}
	else
		printf("Stack overflow");
}

int pop()
{
	struct node *t;
	int val;
	if(s==NULL)
		return -1;
	else
	{
		t=s;
		val=s->val;
		s=s->next;
		free(t);
		return val;
	}

}

void display()
{
	struct node *t;
	printf("Stack is - ");
	for(t=s;t!=NULL;t=t->next)
	{
		printf("%d, ", t->val);
	}
	printf("\n");
}

int search(int key)
{
	struct node *t;
	if(s==NULL)
		return -1;
	else
	{
		for(t=s;t!=NULL;t=t->next)
		{
			if(t->val==key)
				return 1;
		}
		return -2;
	}
}

/* 	SAMPLE OUTPUT

1. Push
2. Pop
3. Display
4. Search
5. Exit
Please Choose: 1
Enter the value to be pushed
2
Successfully pushed 2 to the stack
Please Choose: 1
Enter the value to be pushed
3
Successfully pushed 3 to the stack
Please Choose: 1
Enter the value to be pushed
4
Successfully pushed 4 to the stack
Please Choose: 3
Stack is - 4, 3, 2, 
Please Choose: 2
4 poped
Please Choose: 4
Enter the value to be searched
3
Found 3 in the stack
Please Choose: 4 
Enter the value to be searched
9
Couldn't find the element in the stack
Please Choose: 2
3 poped
Please Choose: 2
2 poped
Please Choose: 2
Stack underflow
Please Choose: 3
Stack is empty
Please Choose: 4
Stack is empty
Please Choose: 5


*/
