/*
	Experiment No:04
	Stack Using Linked List
	MUHAMMED THABJEEL
	S4 R 40
	Date:22-02-2015
*/
#include<stdio.h>
#include<stdlib.h>
struct stack
	{
		int data;
		struct stack *prev;
	};
typedef struct stack stack;
stack *top=NULL;
int flag=1,pop(),push(int);
void display();
void main()
	{
		int opt,val;
		while(opt!=4)
		{
			printf("Enter your option\n");
			printf("1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
			scanf("%d",&opt);
			switch(opt)
			{
				case 1:
					printf("Enter the element to be pushed\n");
					scanf("%d",&val);
					if(push(val)==1)
						printf("The element %d is pushed succesfully\n",val);
					else
						printf("No memory available\n");
					break;
				case 2:
					val=pop();
					if(flag==1)
						printf("The element %d is poped\n",val);
					break;
				case 3:
					if(top!=NULL){
							printf("The elements in the stack are\n");
							display();
							}
					else
						printf("Stack is empty....!\n");
					break;
				case 4:
					break;
				default:
					printf("You have entered wrong option, please Try again.....!");
			}
		}
}
int push(int val)
{
	stack *temp;
	temp=(stack *)malloc(sizeof(stack));
	if(temp==NULL)
		return 0;
	temp->data=val;
	temp->prev=top;
	top=temp;
	return 1;
}

int pop()
{
	int k;
	flag=1;
	if(top==NULL)
		{
			printf("Stack is empty...!\n");
			flag=0;
		}
	else
	{
		k=top->data;
		top=top->prev;
	}
	return k;
}

void display()
{
	stack *ptr;
	ptr=top;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->prev;
	}
	printf("\n");
}

/*
  *****************SAMPLE OUTPUT************
Enter your option
1. PUSH
2. POP
3. DISPLAY
4. EXIT
1
Enter the element to be pushed
1
The element 1 is pushed succesfully
Enter your option
1. PUSH
2. POP
3. DISPLAY
4. EXIT
1
Enter the element to be pushed
2
The element 2 is pushed succesfully
Enter your option
1. PUSH
2. POP
3. DISPLAY
4. EXIT
1
Enter the element to be pushed
3
The element 3 is pushed succesfully
Enter your option
1. PUSH
2. POP
3. DISPLAY
4. EXIT
1
Enter the element to be pushed
4
The element 4 is pushed succesfully
Enter your option
1. PUSH
2. POP
3. DISPLAY
4. EXIT
1
Enter the element to be pushed
5
The element 5 is pushed succesfully
Enter your option
1. PUSH
2. POP
3. DISPLAY
4. EXIT
3
The elements in the stack are
5	4	3	2	1	
Enter your option
1. PUSH
2. POP
3. DISPLAY
4. EXIT
2
The element 5 is poped
Enter your option
1. PUSH
2. POP
3. DISPLAY
4. EXIT
2
The element 4 is poped
Enter your option
1. PUSH
2. POP
3. DISPLAY
4. EXIT
2
The element 3 is poped
Enter your option
1. PUSH
2. POP
3. DISPLAY
4. EXIT
2
The element 2 is poped
Enter your option
1. PUSH
2. POP
3. DISPLAY
4. EXIT
2
The element 1 is poped
Enter your option
1. PUSH
2. POP
3. DISPLAY
4. EXIT
2
Stack is empty...!
Enter your option
1. PUSH
2. POP
3. DISPLAY
4. EXIT
4

*/
