/*
	Ex.NO:09
	Queue Using Linked List
	MUHAMMED THABJEEL
	S4 R 40
	Date:23-02-2015
*/
#include<stdio.h>
#include<malloc.h>
#define MAX 5
struct que{
		int data;
		struct que *next;
		};
typedef struct que que;
void enque(int),display();
int deqeu(),flag=1;
que *front=NULL,*rear=NULL;
int main()
{
	int ch=0,k;
	while(ch!=4){
			flag=1;
			printf("chose your option..!\n");
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
					if(flag==1)
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
void enque(int k)
	{
		que *temp;
		temp=(que*)malloc(sizeof(que));
		if(temp==NULL)
				printf("Memory full...Unable to add\n");
		else{
			temp->next=NULL;
			temp->data=k;
			if(front==NULL){
					front=temp;
					rear=temp;
					}
			else{
				rear->next=temp;
				rear=temp;
				}
			printf("The element %d is added to queue\n",k);
			}
	}
int deque()
	{
		int val;
		que *temp;
		if(front==NULL){
				printf("Queue is Empty...!\n");
				flag=0;
				}
		else{
			val=front->data;
			temp=front;
			front=front->next;
			free(temp);
			return (val);
			}
	}
void display()
	{
		que *ptr;
		if(front==NULL)
			printf("Queue is Empty....!\n");
		else{
			ptr=front;
			printf("Elements in the queue are:\n");
			while(ptr!=NULL){
						printf("%d\t",ptr->data);
						ptr=ptr->next;
					}
			printf("\n");
			}
	}

/*
  ***************SAMPLE OUTPUT***************

chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
1
Enter the element to be queued
1
The element 1 is added to queue
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
1
Enter the element to be queued
2
The element 2 is added to queue
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
1
Enter the element to be queued
3
The element 3 is added to queue
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
1
Enter the element to be queued
4
The element 4 is added to queue
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
1
Enter the element to be queued
5
The element 5 is added to queue
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
1
Enter the element to be queued
6
The element 6 is added to queue
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
1
Enter the element to be queued
7
The element 7 is added to queue
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
3
Elements in the queue are:
1	2	3	4	5	6	7	
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
2
Element 1 is removed from the queue...!
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
2
Element 2 is removed from the queue...!
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
2
Element 3 is removed from the queue...!
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
2
Element 4 is removed from the queue...!
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
3
Elements in the queue are:
5	6	7	
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
2
Element 5 is removed from the queue...!
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
2
Element 6 is removed from the queue...!
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
2
Element 7 is removed from the queue...!
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
2
Queue is Empty...!
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
3
Queue is Empty....!
chose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Exit
4

*/
