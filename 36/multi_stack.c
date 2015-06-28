/*
	Ex No. 2 Implementation of stack using array
	S4R 036 Mohamed Insaf K
	29/12/2014
*/

#define MAX 5
#include <stdio.h>

int push(int [], int, int);
int pop(int [], int);
void display(int [], int);
int search(int [], int, int);

int top1, top2;

int main(void)
{
	int choice, stack[MAX], val, pos, curr;
	top1=-1;
	top2=MAX;
	printf("MULTIPLE STACK:\nTotal size of the stack is %d\n", MAX);
	do{
		printf("Please Choose\n1. Stack1\n2. Stack2\n3. Exit\n");
		scanf("%d", &curr);
		if(curr==1 || curr==2)
		{
			printf("\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Go to previous menu\n");
			do{
				printf("Please Choose: ");
				scanf("%d", &choice);
				switch(choice)
				{
					 case 1:
						printf("Enter the value to be pushed: ");
						scanf("%d", &val);
						if(push(stack, val, curr))
							printf("Successfully pushed %d to the Stack%d\n", val, curr);
						else
							printf("Stack overflow\n");
						break;
					case 2:
						if((val=pop(stack, curr))!=-1)
							printf("%d poped\n", val);
						else
							printf("Stack underflow\n");
						break;
					case 3:
						display(stack, curr);
						break;
					case 4:
						break;
					default:
						printf("Wrong option please try again\n");
				}
			}while(choice !=4);
		}
		else if(curr != 3)
			printf("Wrong option please try again\n");
	}while(curr!=3);
	return 0;
}


int push(int stack[], int val, int curr)
{

	if(curr==1)
		if(top1+1<top2)
		{
			stack[++top1]=val;
			return 1;
		}
		else
			return 0;
	if(curr==2)
		if(top2-1>top1)
		{
			stack[--top2]=val;
			return 1;
		}
		else
			return 0;
}


int pop(int stack[], int curr)
{
	if(curr==1)
		if(top1>=0)
			return(stack[top1--]);
		else
			return -1;
	if(curr==2)
		if(top2<MAX)
			return(stack[top2++]);
		else
			return -1;
}


void display(int stack[], int curr)
{
	int i;
	if(curr==1)
		if(top1>=0)
		{
			printf("Stack is - ");
			for(i=top1;i>=0;i--)
				printf("%d, ", stack[i]);
			printf("\n");
		}
		else
			printf("Stack is empty\n");
	if(curr==2)
		if(top2<MAX)
		{
			for(i=top2;i<MAX;i++)
				printf("%d, ", stack[i]);
			printf("\n");
		}
		else
			printf("Stack is empty\n");
}
