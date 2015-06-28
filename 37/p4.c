/*	program 4
IMPLEMENTATION OF STACK USING LINKED LIST
04/02/2015
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Stack defined as a structure
struct stack
{
	struct stack *next;
	char data[10];
};

struct stack *top=NULL;

//Main function
int main()
{
	int choice,result;
	char ans='y';

	int menu();	int push();
	int pop();
	void display();
	int search();

	do
	{
		choice=menu();

		switch(choice)
		{
			case 1:
				result=push();

				if(result)
					printf("\nSuccessfully pushed to stack!!");
			break;
			case 2:
				result=pop();

				if(result)
					printf("\nSuccessfully popped from stack!!");
			break;
			case 3:
				if(top==NULL)
				{
					printf("\nThe Stack is EMPTY!!");
					break;
				}

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
	printf("\t\t 1. Push \n\t\t 2. Pop \n\t\t 3. Display \n\t\t 4. Search \n\t\t 5. Exit \n\n\t");
	printf("Enter your choice : ");
	scanf("%d",&ch);

	return ch;
}

//Function to push elements to stack
int push()
{
	char val[10];

	printf("\nEnter the element to insert : ");
	scanf(" %[^\n]s",val);

	struct stack *s=malloc(sizeof(struct stack));

	strcpy(s->data,val);

	if(top==NULL)
	{
		top=s;
		top->next=NULL;
		return 1;
	}

	s->next=top;
	top=s;

	return 1;
}

//Function to pop elements from stack
int pop()
{
	if(top==NULL)
	{
		printf("\n The Stack is EMPTY!!");
\		return 0;
	}

	top=top->next;

	return 1;
}


//Function to display the stack
void display()
{
	struct stack *s;
	s=top;

	while(s!=NULL)
	{
		printf(" %s \n",s->data);
		s=s->next;
	}

}


//Function to search the stack
int search()
{
	int pos=1,check=0;
	char ele[10];
	struct stack *s;
	s=top;

	printf("Enter the element to search : ");
	scanf(" %[^\n]",ele);

	while(s!=NULL)
	{
		if(strcmp(s->data,ele)==0)
		{
			printf("The element is present in position %d \n",pos);
			check++;
		}
		pos++;
		s=s->next;
	}

	return check;
}


      /*         OUTPUT


			 MENU 

		 1. Push 
		 2. Pop 
		 3. Display 
		 4. Search 
		 5. Exit 

	Enter your choice : 1

Enter the element to insert : 12

Successfully pushed to stack!!

			 MENU 

		 1. Push 
		 2. Pop 
		 3. Display 
		 4. Search 
		 5. Exit 

	Enter your choice : 1

Enter the element to insert : 222

Successfully pushed to stack!!

			 MENU 

		 1. Push 
		 2. Pop 
		 3. Display 
		 4. Search 
		 5. Exit 

	Enter your choice : 2

Successfully popped from stack!!

			 MENU 

		 1. Push 
		 2. Pop 
		 3. Display 
		 4. Search 
		 5. Exit 

	Enter your choice : 3
 12 


			 MENU 

		 1. Push 
		 2. Pop 
		 3. Display 
		 4. Search 
		 5. Exit 

	Enter your choice : 4
Enter the element to search : 12
The element is present in position 1 


		


			 MENU 

		 1. Push 
		 2. Pop 
		 3. Display 
		 4. Search 
		 5. Exit 

	Enter your choice : 4
Enter the element to search : 121

 The element is not present

			 MENU 

		 1. Push 
		 2. Pop 
		 3. Display 
		 4. Search 
		 5. Exit 

	Enter your choice : 5
*/


