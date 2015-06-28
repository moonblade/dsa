/*
	Ex No. 6 Implementation of Circular queue using array
	S4R 036 Mohamed Insaf K
	02/02/2015
*/

#define MAX 100
#include <stdio.h>

int push(int [], int);
int pop(int []);
void display(int []);

int f,r, max;

int main(void)
{
	int choice, q[MAX], val, pos;
	f=r=0;
	printf("Enter the size of CIRCULAR queue\n");
	scanf("%d", &max);
	max++;
	printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
	while(1)
	{
		printf("Please choose: ");
		scanf("%d", &choice);
		switch(choice)
		{
			 case 1:
				printf("Enter the value\n");
				scanf("%d", &val);
				if(push(q, val))
					printf("%d Enqueued\n", val);
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
				return 0;
			default:
				printf("Wrong option please try again\n");
		}
	}
	return 0;
}


int push(int q[], int val)
{
	if( (r+1)%max !=f)
	{
		q[r++]=val;
		r %= max;
		return 1;
	}
	else
		return 0;
}


int pop(int q[])
{
	int ret;
	if( f != r )
	{
		ret = q[f++];
		f %= max;
		return ret;
	}
	else
		return -1;
}


void display(int q[])
{
	int i;
	if( f != r )
	{
		printf("Front - ");
		for(i=f;i != r;)
		{
			printf("%d, ", q[i]);
			i++;
			i %= max;

		}
		printf(" - Rear\n");
	}
	else
		printf("Queue is empty\n");
}

/*	SAMPLE OUTPUT

Enter the size of CIRCULAR queue
4

1. Enqueue
2. Dequeue
3. Display
4. Exit
Please choose: 1
Enter the value
1
1 Enqueued
Please choose: 1
Enter the value
2
2 Enqueued
Please choose: 1
Enter the value
3
3 Enqueued
Please choose: 1
Enter the value
4
4 Enqueued
Please choose: 2
1 dequeued
Please choose: 3
Front - 2, 3, 4,  - Rear
Please choose: 1
Enter the value
10
10 Enqueued
Please choose: 3
Front - 2, 3, 4, 10,  - Rear
Please choose: 2
2 dequeued
Please choose: 2
3 dequeued
Please choose: 1
Enter the value
10
10 Enqueued
Please choose: 1
Enter the value
15
15 Enqueued
Please choose: 1
Enter the value
16
Queue overflow
Please choose: 3
Front - 4, 10, 10, 15,  - Rear
Please choose: 2
4 dequeued
Please choose: 2
10 dequeued
Please choose: 2
10 dequeued
Please choose: 2
15 dequeued
Please choose: 2
Queue underflow
Please choose: 3
Queue is empty
Please choose: 4


*/
