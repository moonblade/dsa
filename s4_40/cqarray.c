/*
	Experiment No:06
	CIRCULAR QUEUE
	MUHAMMED THABJEEL
	S4 R 40
	Date: 03/03/2015
*/
#include<stdio.h>
#define MAX 5
void enque(int),display();
int deque();
int a[MAX],front=-1,rear=-1,flag=0;
void main()
{
	int ch=0,k;
	while(ch!=4)
	{
		flag=0;
		printf("choose your option..!\n");
		printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element to be queued\n");
				scanf("%d",&k);
				enque(k);
				break;
			case 2:
				k=deque();
				if(flag==0)
					printf("Element %d is removed from the queue...!\n",k);
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

	void enque(int val)
	{
		if((front==0&&rear==MAX-1)||(front==rear+1))
							printf("Queue is full...!\n");
		else
		{
			if(front==-1)
			{
				front=0;
				rear=0;
			}
			else
				if(rear==MAX-1)
					rear=0;
				else
					rear++;
			a[rear]=val;
		}
	}
	int deque()
	{
		int val;
		flag=0;
		if(front==-1)
			{
				printf("Queue is empty..!\n");
				flag=1;
			}
		else
			{
				val=a[front];
				if(front==rear)
				{
					front=-1;
					rear=-1;
				}
				else
					if(front==MAX-1)
						front=0;
					else
						front++;
				return val;
			}
	}
	void display()
	{
		int fp=front,rp=rear;
		if(front==-1)
			printf("Queue is empty....!\n");
		else
			printf("The elements in the queue are:\n");
			if(fp<=rp)
			{
				while(fp<=rp)
					printf("%d\t",a[fp++]);
				printf("\n");
			}
			else
			{
				while(fp<=MAX-1)
				{
					printf("%d\t",a[fp++]);
				}
				fp=0;
				while(fp<=rp)
				{
					printf("%d\t",a[fp++]);
				}
				printf("\n");
			}
	}
/*
  *****************SAMPLE OUTPUT***************

choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
4
s1340@linux-server:~/s4$ ./a.out
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
1
Enter the element to be queued
10
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
1
Enter the element to be queued
20
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
1
Enter the element to be queued
30
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
1
Enter the element to be queued
40
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
1
Enter the element to be queued
50
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
1
Enter the element to be queued
60
Queue is full...!
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
3
The elements in the queue are:
10	20	30	40	50
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
2
Element 10 is removed from the queue...!
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
1
Enter the element to be queued
60
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
3
The elements in the queue are:
20	30	40	50	60
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
4

*/

