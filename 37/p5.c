/*
        Experiment No:5
        QUEUE USING ARRAY
        
*/
#include<stdio.h>
#define max 5
void enque(int);
int deque();
void display();
int search(int);
int a[max],front=-1,rear=-1,flag;
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
                                if((front==-1)||(front>rear))
                                        printf("No elements to Search\n");
                                else
                                {

      printf("Enter the element to search in the queue\n");
                                        scanf("%d",&k);
                                        l=search(k);
                                        if(l==0)
                                                printf("%d is not present in the queue\n",k);
                                        else
                                                printf("%d is present at the position %d\n",k,l);
                                }
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
                if(rear==max-1)
                        printf("Queue is full...!\n");
                else
                        {if(front==-1)
                                front=0;
                        a[++rear]=val;}
        }
        int deque()
  {
                int val;
                if((front==-1)||(front>rear))
                {
                        flag=1;
                        printf("Queue is empty\n");
			front=-1;
			rear=-1;
                }
                else
                     {
			 val=a[front++];
			if(front>rear )
			{
			front=-1;
			rear=-1;
			}
                return val;
		   }	
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
                                return (i-front+1);
                }
                return 0;
  }


             /*   OUTPUT



choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
1
Enter the element to be queued
12
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
2
Element 12 is removed from the queue...!
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
1
Enter the element to be queued
123
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
1
Enter the element to be queued
12
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
3
Elements in the queue are
123	12	
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
4
Enter the element to search in the queue
123
123 is present at the position 1
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Exit
5
*/



