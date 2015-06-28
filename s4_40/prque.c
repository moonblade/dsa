/*
  Ex.NO:10
  Priority Queue
  MUHAMMED THABJEEL
  S4 R 40
  17/03/2015
*/
#include<stdio.h>
#include<malloc.h>
#define MAX 5
struct que{
  int data;
  int prior;
  struct que *next;
};
typedef struct que que;
void enque(int,int),display();
int deqeu(),flag=1;
que *front=NULL,*rear=NULL;
int main()
{
  int ch=0,k,p;
  while(ch!=4)
    {
      flag=1;
      printf("chose your option..!\n");
      printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n");
      scanf("%d",&ch);
      switch(ch)
	{
	case 1:
	  printf("Enter the element followed by its rank\n");
	  scanf("%d%d",&k,&p);
	  enque(k,p);
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
void enque(int k,int p)
{
  que *temp,*ptr;
  temp=(que*)malloc(sizeof(que));
  if(temp==NULL)
    printf("Memory full...Unable to add\n");
  else
    {
      temp->data=k;
      temp->prior=p;
      if(front==NULL)
	{
	  temp->next=NULL;
	  front=temp;
	  rear=temp;
	}
      else
	{
	  if((front->prior)>p)
	    {
	      temp->next=front;
	      front=temp;
	    }
	  else
	    {
	      ptr=front;
	      while((ptr->next)!=NULL)
		{
		  if(((ptr->next)->prior)>p)
		    break;
		  ptr=ptr->next;
		}
	      temp->next=ptr->next;
	      ptr->next=temp;
	    }
	  printf("The element %d is added to queue\n",k);
	}
    }
}
int deque()
{
  int val;
  que *temp;
  if(front==NULL)
    {
      printf("Queue is Empty...!\n");
      flag=0;
    }
  else
    {
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
  else
    {
      ptr=front;
      printf("Elements in the queue are:\n");
      while(ptr!=NULL)
	{
	  printf("%d (%d)\t",ptr->data,ptr->prior);
	  ptr=ptr->next;
	}
      printf("\n");
    }
}

