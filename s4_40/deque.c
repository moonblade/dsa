/*
  	Experiment No:07
  	Double Ended Queue
	MUHAMMED THABJEEL
  	S4 R 40
  	Date: 03/03/2015
*/
#include<stdio.h>
#define MAX 5
void enque(int),display();
int deque(),search(int);
int a[MAX],front=-1,rear=-1,flag=0,q;
void main()
{
  int ch=0,k,l;
	while(ch!=6)
	  {
	    printf("choose your option..!\n");
	    while((q!=1)&&(q!=2))
		{
		  printf("1.Input Restricted\t2.Output Restricted\n");
		  scanf("%d",&q);
		  if((q!=1)&&(q!=2))
		    printf("Wrong option\n");
		}
	    printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Search\t5.Change the type\t6.Exit\n");
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
		    printf("1.Input Restricted\t2.Output Restricted\n");
		    scanf("%d",&q);
		    break;
		  case 6:
		    break;
		  default:
		    printf("You've entered wrong option, please try again.........!\n");
		}
	  }
}

void enque(int val)
{
  int s;
   if(q==2)
    {
      printf("To which end of the queue you want to insert %d..?\n",val);
      printf("1.FRONT\t\t2.REAR\n");
      scanf("%d",&s);
      if(s==1)
	{
	  if(front==0)
	    printf("Element can't be inserted in front\n");
	  else
	    {
	      if(front==-1)
		{
		  front=1;
		  rear=0;
		}
	      a[--front]=val;
	      printf("%d is added to queue\n",val);
	    }
	}
    }
   if((q==1)||(q==2&&s==2))
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
}
int deque()
{
  int val,s;
  flag=0;
  if(q==1)
    {
      while(s!=1&&s!=2)
	{
	  printf("From which end you want to dequeu..?\n");
	  printf("1.FRONT\t\t2.REAR\n");
	  scanf("%d",&s);
	  if(s!=1&&s!=2)
	    printf("wrong option...please try again\n");
	}
      if(s==2)
	{
	  if(front==-1||(front>rear))
	    {
	      printf("Queue is empty\n");
	      flag=1;
	    }
	  else
	    {
	      val=a[rear--];
	      return val;
	    }
	}
    }
  if(q==2||(q==1&&s==1))
    {
      if(front==-1||(front>rear))
	{
	  printf("Queue is empty..!\n");
	  flag=1;
	}
      else
	{
	  val=a[front++];
	  return val;
	}
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
	return i-front+1;
    }
  return 0;
}

/*
  ***********SAMPLE OUTPUT************

choose your option..!
1.Input Restricted	2.Output Restricted
1
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Change the type	6.Exit
1
Enter the element to be queued
10
10 is added to queue
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Change the type	6.Exit
1
Enter the element to be queued
20
20 is added to queue
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Change the type	6.Exit
3
Elements in the queue are
10	20	
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Change the type	6.Exit
2
From which end you want to dequeu..?
1.FRONT		2.REAR
2
Element 20 is removed from the queue...!
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Change the type	6.Exit
3
Elements in the queue are
10	
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Change the type	6.Exit
5
1.Input Restricted	2.Output Restricted
2
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Change the type	6.Exit
1
Enter the element to be queued
20
To which end of the queue you want to insert 20..?
1.FRONT		2.REAR
2
20 is added to queue
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Change the type	6.Exit
3
Elements in the queue are
10	20	
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Change the type	6.Exit
1
Enter the element to be queued
30
To which end of the queue you want to insert 30..?
1.FRONT		2.REAR
1
Element can't be inserted in front
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Change the type	6.Exit
2
Element 10 is removed from the queue...!
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Change the type	6.Exit
1
Enter the element to be queued
30
To which end of the queue you want to insert 30..?
1.FRONT		2.REAR
1
30 is added to queue
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Change the type	6.Exit
3
Elements in the queue are
30	20
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Change the type	6.Exit
4
Enter the element to searched
30
30 is present at the position 1
choose your option..!
1.Enqueue	2.Dequeue	3.Display	4.Search	5.Change the type	6.Exit
6

*/

