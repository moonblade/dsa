/*
	Experiment NO:01
	Implementation of stack using array
	MUHAMMED THABJEEL M P
	S4 R 40
	DATE:11-12-214
*/
#include<stdio.h>
#define max 5
int a[max], top=-1;
void push(int);
int pop();
void display();
int search(int);
void main()
{
	int val;
	int opt=0;
	while(opt!=5)
		{
			printf("\nPlease enter your option...!");
			printf("\n1.PUSH\t2.POP\t3.DISPLAY\t4.SEARCH\t5.EXIT\n");
			scanf("%d",&opt);
			switch(opt)
				{
					case 1:
						printf("Enter the element to be pushed\n");
						scanf("%d",&val);
						push(val);
						break;
					case 2:
						val=pop();
						if(top>-1)
							printf("The element poped is %d",val);
						break;
					case 3:
						if(top!=-1)
							printf("The elements in the stack are\n");
						display();
						break;
					case 4:
						printf("Enter the element to be searched\n");
						scanf("%d",&val);
						if(search(val)==0)
							printf("%d is not present in the stack",val);
						else
							printf("%d is present at the position %d",val,search(val));
					case 5:
						break;
					default:
						printf("You have entered wrong option, please Try again.....!");
				}
		}
}
void push(int val)
{
	if(top==max-1)
		printf("Stack is full........!!\n");
	else
	{
		top++;
		a[top]=val;
	}
}
int pop()
{
	int val;
	if(top==-1)
		printf("Stack is empty...!");
	else
	{
		val=a[top];
		top--;
	}
	return val;
}
void display()
{
	int i;
	if(top!=-1)
	{
		for(i=top;i>=0;i--)
		{
			printf("%d\t",a[i]);
		}
	}
	else
		printf("stack is empty\n");
}
int search(int val)
{
	int i;
	for(i=0;i<=top;i++)
	{
		if(a[i]==val)
			return (i+1);
	}
	return 0;
}

/*
  *************SAMPLE OUTPUT***********

Please enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. SEARCH	5. EXIT
65
You have entered wrong option, please Try again.....!
Please enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. SEARCH	5. EXIT
5
s1340@linux-server:~/s4$ nano stackarr.c 
s1340@linux-server:~/s4$ cc stackarr.c 
s1340@linux-server:~/s4$ ./a.out

Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
1
Enter the element to be pushed
1

Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
1
Enter the element to be pushed
2

Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
1
Enter the element to be pushed
3

Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
1
Enter the element to be pushed
4

Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
1
Enter the element to be pushed
5

Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
1
Enter the element to be pushed
7
Stack is full........!!

Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
3
The elements in the stack are
5	4	3	2	1	
Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
4
Enter the element to be searched
3
3 is present at the position 3
Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
4
Enter the element to be searched
10
10 is not present in the stack
Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
2
The element poped is 5
Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
2
The element poped is 4
Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
2
The element poped is 3
Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
2
The element poped is 2
Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
2
Stack is empty...!
Please enter your option...!
1.PUSH	2.POP	3.DISPLAY	4.SEARCH	5.EXIT
5

*/
