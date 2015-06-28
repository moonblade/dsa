/*
	Experiment No:02
	Multiple stack of variable size
	MUHAMMED THABJEEL
	S4 R 40
	Date:02-02-2015
*/
#include<stdio.h>
#define max 5
int top1=-1,top2=max,stk[100],flag=0;
void wrong(),empty();
void push(int,int);
int pop(int);
void display(int);
void main()
{
	int val,s,opt=0;
	while(opt!=4)
		{
			printf("\nPlease Enter your option...!");
			printf("\n1. PUSH\t2. POP\t3. DISPLAY\t4. EXIT\n");
			scanf("%d",&opt);
			switch(opt)
				{
					case 1:
						printf("Enter the element to be pushed\n");
						scanf("%d",&val);
						printf("To which stack you want to push the element srtack 1 or 2?\n");
						scanf("%d",&s);
						if(s==1||s==2)
							push(val,s);
						else
							wrong();
						break;
					case 2:
						printf("From which stack you want to pop?\n");
						scanf("%d",&s);
						if(s==1||s==2)
							val=pop(s);
						else
							wrong();
						if(flag==0)
							printf("The Element popped is: %d\n",val);
						break;
					case 3:
						printf("Which stack you want to display? enter 1 or 2\n");
						scanf("%d",&s);
						if(s==1||s==2)
							display(s);
						else
							wrong();
						break;
					case 4:
						break;
					default:
						wrong();
				}
		}

}

void push(int k,int s)
{
	if(top2==top1+1)
		printf("The stack is full...!\n");
	else
	{
		if(s==1)
			stk[++top1]=k;
		else
			stk[--top2]=k;
	}
}

int pop(int s)
{
	flag=0;
	if(s==1)
	{
		if(top1==-1)
			empty();
		else
			return(stk[top1--]);
	}
	else
	{
		if(s==2)
		{
			if(top2==max)
				empty();
			else
				return(stk[top2++]);
		}
		else
			wrong();
	}
}

void wrong()
{
	printf("You have Entered wrong option...!\n");
}

void empty()
{
	flag=1;
	printf("Stack is Empty..!\n");
}

void display(int s)
{
	int i;
	if(s==1)
	{
		if(top1==-1)
			empty();
		else
		{
			printf("The Elements of the stack1 are:\n");
			for(i=top1;i>=0;i--)
			{
				printf("%d\t",stk[i]);
			}
		}
	}
	if(s==2)
	{
		if(top2==max)
			empty();
		else
		{
			printf("The Elements in the stack2 are:\n");
			for(i=top2;i<max;i++)
			{
				printf("%d\t",stk[i]);

			}
		}
	}
}

/*
  ***************SAMPLE OUTPUT***************

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
1
Enter the element to be pushed
1
To which stack you want to push the element srtack 1 or 2?
1

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
1
Enter the element to be pushed
2
To which stack you want to push the element srtack 1 or 2?
1

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
1
Enter the element to be pushed
3
To which stack you want to push the element srtack 1 or 2?
1

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
1
Enter the element to be pushed
10
To which stack you want to push the element srtack 1 or 2?
2

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
1
Enter the element to be pushed
20
To which stack you want to push the element srtack 1 or 2?
2

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
1
Enter the element to be pushed
8
To which stack you want to push the element srtack 1 or 2?
1
The stack is full...!

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
8
You have Entered wrong option...!

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
1
Enter the element to be pushed
8
To which stack you want to push the element srtack 1 or 2?
1
The stack is full...!

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
3
Which stack you want to display? enter 1 or 2
1
The Elements of the stack1 are:
3	2	1
Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
3
Which stack you want to display? enter 1 or 2
2
The Elements in the stack2 are:
20	10
Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
2
From which stack you want to pop?
2
The Element popped is: 20

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
3
Which stack you want to display? enter 1 or 2
2
The Elements in the stack2 are:
10
Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
2
From which stack you want to pop?
1
The Element popped is: 3

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
3
Which stack you want to display? enter 1 or 2
1
The Elements of the stack1 are:
2	1
Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. EXIT
4

*/
