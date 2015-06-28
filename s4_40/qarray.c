/*
	Experiment No:05
	QUEUE USING ARRAY
	MUHAMMED THABJEEL
	S4 R 40
	Date:06-01-2015
*/
#include<stdio.h>
#define MAX 5
void enque(int),display();
int deque();
int search();
int a[MAX],front=-1,rear=-1,flag;
void main()
{
	int ch=0,k,l;
	while(ch!=5)
	{
		flag=0;
		printf("choose your option..!\n");
		printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Search\t5.Exit\n");
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
				if((front==-1)||(front>rear))
					printf("Nothing to display!!");
				else
				{
					printf("Elements in the queue are\n");
					display();
				}
				printf("\n");
				break;
			case 4:
				printf("Enter the element to searched\n");
				scanf("%d",&k);
				l=search(k);
				if(l==0)
					printf("%d is not present in the queue\n",k);
				else
					printf("%d is present at the position %d\n",k,l);
				break;
			case 5:
				break;
			default:
				printf("You've entered wrong option, please try again.........!\n");
		}
	}
}

	void enque(int val)
	{
		if(rear==MAX-1)
			printf("Queue is full...!\n");
		else
		{
			if(front==-1)
				front=0;
			a[++rear]=val;
			printf("%d is added to queue\n",val);
		}
	}
	int deque()
	{
		int val;
		if((front==-1)||(front>rear))
		{
			flag=1;
			printf("Queue is empty\n");
		}
		else
			val=a[front++];
		return val;
	}
	void display()
	{
		int i;
		for(i=front;i<=rear;i++)
			printf("%d\t",a[i]);
	}
	int search(int val)
	{
		int i;
		for(i=front;i<=rear;i++)
		{
			if(a[i]==val)
				return i-front+1;
		}
		return 0;
	}

/*
  **************SAMPLE OUTPUT***************

choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
1
Enter the element to be queued
10
10 is added to queue
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
1
Enter the element to be queued
20
20 is added to queue
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
1
Enter the element to be queued
30
30 is added to queue
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
1
Enter the element to be queued
40
40 is added to queue
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
1
Enter the element to be queued
50
50 is added to queue
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
1
Enter the element to be queued
60
Queue is full...!
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
3
Elements in the queue are
10	20	30	40	50	
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
2
Element 10 is removed from the queue...!
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
3
Elements in the queue are
20	30	40	50	
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
2
Element 20 is removed from the queue...!
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
3
Elements in the queue are
30	40	50	
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
2
Element 30 is removed from the queue...!
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
3
Elements in the queue are
40	50	
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
4
Enter the element to searched
50
50 is present at the position 2
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
4
Enter the element to searched
4
4 is not present in the queue
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
2
Element 40 is removed from the queue...!
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
2
Element 50 is removed from the queue...!
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
2
Queue is empty
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
3
Nothing to display!!
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
5

*/
