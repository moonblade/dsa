/*
PROGRAM 7   
implement dequeue
mohammed jasim e 
s1337
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
	int choice,result,qChoice;
	char ans='y';

	q.rear=-1;
	q.front=-1;

	int qMenu();
	int menu();
	int enqueue(int);
	int dequeue(int);
	void display();
	int search();

	qChoice=qMenu();

	do
	{
		choice=menu();

		switch(choice)
		{
			case 1:
				result=enqueue(qChoice);

				if(result)
					printf("\nSuccessfully enqueued!!");
			break;
			case 2:
				result=dequeue(qChoice);

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
				qChoice=qMenu();
			break;
			case 6:
				return 0;
			break;
		}


	}
	while(ans=='y');

	return 0;
}


int qMenu()
{
	int qChoice;

	printf("\t\t\t MENU \n\n\t\t 1. Input Restricted Queue \n\t\t 2. Output Restricted Queue \n\n\t Enter choice : ");
	scanf("%d",&qChoice);

	return qChoice;
}


//Function to display menu
int menu()
{
	int ch;

	printf("\n\n\t\t\t MENU \n\n");
	printf("\t\t 1. Enqueue \n\t\t 2. Dequeue \n\t\t 3. Display \n\t\t 4. Search \n\t\t 5. Change Queue type \n\t\t 6. Exit \n\n\t");
	printf("Enter your choice : ");
	scanf("%d",&ch);

	return ch;
}


//Function to check overflow
int overflow()
{
	if(q.rear==4)
		return 1;
	else
		return 0;
}


//Function to enqueue elements
int enqueue(int qChoice)
{
	int i,ch,uCheck;
	char ele[10];

	if(overflow())
	{
		printf("\n The Queue is FULL!!");
		return 0;
	}

	printf("\nEnter the element to insert : ");
	scanf(" %[^\n]s",ele);

	uCheck=underflow();

	if(qChoice==1)
		strcpy(q.data[++q.rear],ele);
	else
	if(qChoice==2)
	{
		printf("\n Input element at :	   1. Front	2. Rear \nChoice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				for(i=q.rear;i>=q.front;i--)
					strcpy(q.data[i+1],q.data[i]);

				strcpy(q.data[0],ele);
				q.rear++;
			break;
			case 2:
				strcpy(q.data[++q.rear],ele);
			break;

		}




	}

	if(uCheck)
		q.front=q.rear=0;

	return 1;
}



//Function to check underflow
int underflow()
{
	if(q.rear==-1)
		return 1;
	else
		return 0;
}


//Function to dequeue elements
dequeue(int qChoice)
{
	int i,ch;

	if(underflow())
	{
		printf("\n The Queue is EMPTY!!");
		return 0;
	}

	if(qChoice==2)
	{
		printf("The element dequeued is %s",q.data[0]);

		for(i=0;i<q.rear;i++)
			strcpy(q.data[i],q.data[i+1]);

		q.rear--;
	}
	else
	if(qChoice==1)
	{
		printf("\n Delete element from :	   1. Front	2. Rear \nChoice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("The element dequeued is %s",q.data[0]);

				for(i=0;i<q.rear;i++)
					strcpy(q.data[i],q.data[i+1]);

		;

				q.rear--;
			break;
			case 2:


				printf("The element dequeued is %s",q.data[q.rear]);

				q.rear--;
			break;

		}
	}

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
		printf("\n The Queue is : \t");
		for(i=0;i<=q.rear;i++)
			printf(" %s \t",q.data[i]);
	}
}


//Function to search the queue
int search()
{
	char ele[10];
	int i,check=0;

	printf("\n Enter the element to search : ");
	scanf(" %[^\n]s",ele);

	for(i=0;i<=q.rear;i++)
		if(!(strcmp(ele,q.data[i])))
		{
			printf("The element is present in position %d \n",i+1);
			check++;
		}

	return check;
}




     /*     OUTPUT
 MENU 

		 1. Input Restricted Queue 
		 2. Output Restricted Queue 

	 Enter choice : 1


			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 1

Enter the element to insert : 123

Successfully enqueued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 2

 Delete element from :	   1. Front	2. Rear 
Choice : 1
The element dequeued is 123
Successfully dequeued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 1

Enter the element to insert : 123

Successfully enqueued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 1

Enter the element to insert : 222

Successfully enqueued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 1

Enter the element to insert : 313

Successfully enqueued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 3

 The Queue is : 	 123 	 222 	 313 	

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 2

 Delete element from :	   1. Front	2. Rear 
Choice : 1
The element dequeued is 123
Successfully dequeued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 2

 Delete element from :	   1. Front	2. Rear 
Choice : 2
The element dequeued is 313
Successfully dequeued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 1

Enter the element to insert : 1234

Successfully enqueued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 1

Enter the element to insert : 325

Successfully enqueued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 1465


			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 3

 The Queue is : 	 222 	 1234 	 325 	

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 3

 The Queue is : 	 222 	 1234 	 325 	

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 3

 The Queue is : 	 222 	 1234 	 325 	

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 3

 The Queue is : 	 222 	 1234 	 325 	

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 
3

 The Queue is : 	 222 	 1234 	 325 	

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 5
			 MENU 

		 1. Input Restricted Queue 
		 2. Output Restricted Queue 

	 Enter choice : 2


			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 1

Enter the element to insert : 12354

 Input element at :	   1. Front	2. Rear 
Choice : 2

Successfully enqueued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 1

Enter the element to insert : 254

 Input element at :	   1. Front	2. Rear 
Choice : 2

Successfully enqueued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 1

 The Queue is FULL!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 2554


			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 1

 The Queue is FULL!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 1225


			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 3

 The Queue is : 	 222 	 1234 	 325 	 12354 	 254 	

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 2
The element dequeued is 222
Successfully dequeued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 2
The element dequeued is 1234
Successfully dequeued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 2
The element dequeued is 325
Successfully dequeued!!

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 3

 The Queue is : 	 12354 	 254 	

			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 4

 Enter the element to search : 12354
The element is present in position 1 


			 MENU 

		 1. Enqueue 
		 2. Dequeue 
		 3. Display 
		 4. Search 
		 5. Change Queue type 
		 6. Exit 

	Enter your choice : 6
*/

