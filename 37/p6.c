/*
PROGRAM 6	IMPLEMENTATION OF CIRCULAR QUEUE
*/

#include<stdio.h>
#include<string.h>

//Queue defined as a structure
struct queue
{
	int front;
	int rear;
	char data[5][10];
}q;


//Main function
int main()
{
	int choice,result;
	char ans='y';

	q.front=-1;
	q.rear=-1;

	int menu();
	int enqueue();
	int dequeue();
	void display();
	int search();

	do
	{
		choice=menu();

		switch(choice)
		{
			case 1:
				result=enqueue();

				if(result)
					printf("\nSuccessfully enqueued!!");
			break;
			case 2:
				result=dequeue();

				if(result)
					printf("\nSuccessfully dequeued!!");
			break;
			case 3:
				display();
			break;
			case 4:
				result=search();

				if(!result)
					printf("\n The element is not present");
			break;
			case 5:
				return 0;
			break;
		}


	}
	while(ans=='y');

	return 0;
}


//Function to display menu
int menu()
{
	int ch;

	printf("\n\n\t\t\t MENU \n\n");
	printf("\t\t 1. Enqueue \n\t\t 2. Dequeue \n\t\t 3. Display \n\t\t 4. Search \n\t\t 5. Exit \n\n\t");
	printf("Enter your choice : ");
	scanf("%d",&ch);

	return ch;
}


//Function to check overflow
int overflow()
{
	if(q.rear==4 && q.front==0)
		return 1;
	else
	if(q.rear+1==q.front)
		return 1;
	else
		return 0;
}


//Function to enqueue elements
int enqueue()
{
	if(overflow())
	{
		printf("\n The Queue is FULL!!");
		return 0;
	}

	if(q.rear==4)
		q.rear=0;
	else
	if(underflow())
		q.rear=q.front=0;
	else
		q.rear++;


	printf("\nEnter the element to insert : ");
	scanf(" %[^\n]s",q.data[q.rear]);

	return 1;
}


//Function to check underflow
int underflow()
{
	if(q.rear==-1 && q.front==-1)
		return 1;
	else
		return 0;
}


//Function to dequeue elements
int dequeue()
{
	int i;

	if(underflow())
	{
		printf("\n The Queue is EMPTY!!");
		return 0;
	}

	printf("The element dequeued is %s",q.data[q.front]);

	if(q.front==q.rear)
		q.front=q.rear=-1;
	else
	if(q.front==4)
		q.front=0;
	else
		q.front++;

	return 1;
}


//Function to display the queue
void display()
{
	int i;

	if(underflow())
		printf("\n The Queue is EMPTY!!");
	else
	{
		printf("\n The Queue is : \n\t");
		for(i=q.front;i!=q.rear;i++)
		{
			printf(" %s \n\t",q.data[i]);

			if(i==4)
				i=-1;
		}
		printf(" %s \n\t",q.data[i]);
	}
}


//Function to search the queue
int search()
{
	char ele[10];
	int i,check=0,pos=1;

	printf("\n Enter the element to search : ");
	scanf(" %[^\n]s",ele);

	for(i=q.front;i!=q.rear;i++)
	{
		if(!(strcmp(ele,q.data[i])))
		{
			printf("The element is present in position %d \n",pos);
			check++;
		}

		pos++;

		if(i==4)
			i=-1;
	}

	if(!(strcmp(ele,q.data[i])))
	{
		printf("The element is present in position %d \n",pos);
		check++;
	}



	return check;
}



                   /* OUTPUT




			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Exit 

	Enter your choice : 1

Enter the element to insert : 132

Successfully enqueued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Exit 

	Enter your choice : 1

Enter the element to insert : 1234

Successfully enqueued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Exit 

	Enter your choice : 1

Enter the element to insert : 44564

Successfully enqueued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Exit 

	Enter your choice : 3

 The Queue is : 
	 132 
	 1234 
	 44564 
	

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Exit 

	Enter your choice : 2
The element dequeued is 132
Successfully dequeued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Exit 

	Enter your choice : 4

 Enter the element to search : 1234
The element is present in position 1 


			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Exit 

	Enter your choice : 5
*/
