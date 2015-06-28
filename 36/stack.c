/*
	Ex No.1 
	Implementation of stack using array
	S4R 036 Mohamed Insaf K
	11/12/2014
*/

#define MAX 100
#include <stdio.h>

int push(int [], int);
int pop(int []);
void display(int []);
int search(int [], int );

int s, max;

int main(void)
{
	int choice, stack[MAX], val, pos;
	s=-1;
	printf("Enter the size of stack\n");
	scanf("%d", &max);
	max--;
	printf("\n1. Push\n2. Pop\n3. Display\n4. Search\n5. Exit\n");
	do{
		printf("Please choose: ");
		scanf("%d", &choice);
		switch(choice)
		{
			 case 1:
				printf("Enter the value to be pushed: ");
				scanf("%d", &val);
				if(push(stack, val))
					printf("Successfully pushed %d to the stack\n", val);
				else
					printf("Stack overflow\n");
				break;
			case 2:
				if((val=pop(stack))!=-1)
					printf("%d poped\n", val);
				else
					printf("Stack underflow\n");
				break;
			case 3:
				display(stack);
				break;
			case 4:
				if(s<0)
					printf("Stack is empty\n");
				else
				{
					printf("Enter the value to be searched: ");
					scanf("%d", &val);
					pos=search(stack, val);
					if(pos==-1)
						printf("Stack is empty\n");
					else if(pos==-2)
						printf("Couldn't find the element in the stack\n");
					else
						printf("Found %d at %d from the top\n", val, s-pos+1);
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


int push(int stack[], int val)
{
	if(s<max)
	{
		stack[++s]=val;
		return 1;
	}
	else
		return 0;
}


int pop(int stack[])
{
	if(s>=0)
		return(stack[s--]);
	else
		return -1;
}


void display(int stack[])
{
	int i;
	if(s>=0)
	{
		printf("Stack is - ");
		for(i=s;i>=0;i--)
			printf("%d, ", stack[i]);
		printf("\n");
	}
	else
		printf("Stack is empty\n");
}


int search(int stack[], int val)
{
	int i;
	if(s>=0)
	{
		for(i=0;i<=s;i++)
			if(stack[i]==val)
				return i;
		return -2;
	}
	else
		return -1;
}
/*	OUTPUT

Enter the size of stack
3

1. Push
2. Pop
3. Display
4. Search
5. Exit
Please choose: 1
Enter the value to be pushed: 1
Successfully pushed 1 to the stack
Please choose: 1
Enter the value to be pushed: 2
Successfully pushed 2 to the stack
Please choose: 1
Enter the value to be pushed: 3
Successfully pushed 3 to the stack
Please choose: 1
Enter the value to be pushed: 4
Stack overflow
Please choose: 3
Stack is - 3, 2, 1, 
Please choose: 2
3 poped
Please choose: 2
2 poped
Please choose: 3
Stack is - 1, 
Please choose: 4
Enter the value to be searched: 1
Found 1 at 1 from the top
Please choose: 4
Enter the value to be searched: 6
Couldn't find the element in the stack
Please choose: 2
1 poped
Please choose: 2
Stack underflow
Please choose: 3
Stack is empty
Please choose: 4
Stack is empty
Please choose: 1
Enter the value to be pushed: 56
Successfully pushed 56 to the stack
Please choose: 3
Stack is - 56, 
Please choose: 5
*/
