/*
	Ex No. 5
	Implementation of queue using array
	S4R 036 Mohamed Insaf K
	29/12/2014
*/

#define MAX 100
#include <stdio.h>

int push(int [], int);
int pop(int []);
void display(int []);
int search(int [], int );

int f,r, max;

int main(void)
{
	int choice, q[MAX], val, pos;
	f=r=0;
	printf("Enter the size of queue\n");
	scanf("%d", &max);
	printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Search\n5. Exit\n");
	do{
		printf("Please choose: ");
		scanf("%d", &choice);
		switch(choice)
		{
			 case 1:
				printf("Enter the value to be pushed\n");
				scanf("%d", &val);
				if(push(q, val))
					printf("%d enqueued\n", val);
				else
					printf("Queue overflow\n");
				break;
			case 2:
				if((val=pop(q))!=-1)
					printf("%d dequeued\n", val);
				else
					printf("Queue underflow\n");
				break;
			case 3:
				display(q);
				break;
			case 4:
				if(r-1<f)
					printf("Queue is empty\n");
				else
				{
					printf("Enter the value to be searched\n");
					scanf("%d", &val);
					pos=search(q, val);
					if(pos==-1)
						printf("Queue is empty\n");
					else if(pos==-2)
						printf("Couldn't find the element in the queue\n");
					else
						printf("Found %d at %d in the queue\n", val, pos+1);
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


int push(int q[], int val)
{
	if(r<max)
	{
		q[r++]=val;
		return 1;
	}
	else
		return 0;
}


int pop(int q[])
{
	if(r-1>=f)
		return(q[f++]);
	else
		return -1;
}


void display(int q[])
{
	int i;
	if(r-1>=f)
	{
		printf("Front - ");
		for(i=f;i<r;i++)
			printf("%d, ", q[i]);
		printf(" - Rear\n");
	}
	else
		printf("Queue is empty\n");
}


int search(int q[], int val)
{
	int i;
	if(r-1>=f)
	{
		for(i=f;i<r;i++)
			if(q[i]==val)
				return (i-f);
		return -2;
	}
	else
		return -1;
}

/*	SAMPLE OUTPUT
Enter the size of queue
4

1. Enqueue
2. Dequeue
3. Display
4. Search
5. Exit
Please choose: 1
Enter the value to be pushed
1
1 enqueued
Please choose: 1
Enter the value to be pushed
2
2 enqueued
Please choose: 1
Enter the value to be pushed
3
3 enqueued
Please choose: 1
Enter the value to be pushed
4
4 enqueued
Please choose: 1
Enter the value to be pushed
5
Queue overflow
Please choose: 3
Front - 1, 2, 3, 4,  - Rear
Please choose: 2
1 dequeued
Please choose: 4
Enter the value to be searched
3
Found 3 at 2 in the queue
Please choose: 4
Enter the value to be searched
7
Couldn't find the element in the queue
Please choose: 2
2 dequeued
Please choose: 2
3 dequeued
Please choose: 2
4 dequeued
Please choose: 2
Queue underflow
Please choose: 3
Queue is empty
Please choose: 4
Queue is empty
Please choose: 5
*/
