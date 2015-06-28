/*
	Experiment No:03
	Multiple satck of fixed size in an array
	MUHAMMED THABJEEL
	S4 R 40
	Date:09-02-2015
*/
#include<stdio.h>
#define max 10
int stk[max],top[max],num,count,size,pop();
void push(int),display(),wrong();
int main()
{
	int i,opt,val;
	printf("How many stacks you want?\n");
	scanf("%d",&count);
	size=max/count;
	for(i=0;i<count;i++)
		top[i]=-1;
	printf("%d stacks of size %d are created\n",count,size);
	printf("Input stack number\n");
	scanf("%d",&num);
	while(opt!=5)
	{
		printf("\nPlease Enter your option...!");
		printf("\n1. PUSH\t2. POP\t3. DISPLAY\t4. CHANGE THE STACK\t5. EXIT\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:printf("Enter the element to push..!\n");
				scanf("%d",&val);
				push(val);
				break;
			case 2:val=pop();
				if(top[num-1]>-1)
					printf("The element poped is %d",val);
				break;
			case 3:if((top[num-1])!=-1)
					printf("The elements in the stack are\n");
				display();
				break;
			case 4:printf("Input the stack number\n");
				scanf("%d",&num);
				if(num>count)
					wrong();
				break;
			case 5:
				break;
			default:
				wrong();
		}
	}
return 0;
}
void push(int val)
{
	if(top[num-1]==size-1)
		printf("Stack is full........!!\n");
	else
	{
		top[num-1]++;
		stk[top[num-1]]=val;
	}
}
int pop()
{
	int val;
	if(top[num-1]==-1)
		printf("Stack is empty...!");
	else
	{
		val=stk[top[num-1]];
		top[num-1]--;
	}
	return val;
}
void display()
{
	int i;
	if(top[num-1]!=-1)
	{
		for(i=top[num-1];i>=0;i--)
			printf("%d\t",stk[i]);
		printf("\n");
	}
	else
		printf("stack is empty\n");
}
void wrong()
{
	printf("You have Entered wrong option...!\n");
}

/*
  **************SAMPLE OUTPUT***********

How many stacks you want?
3
3 stacks of size 3 are created
Input stack number
1

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
1
Enter the element to push..!
1

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
1
Enter the element to push..!
2

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
3
The elements in the stack are
2	1	

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
4
Input the stack number
2

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
1
Enter the element to push..!
4

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
1
Enter the element to push..!
5

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
3
The elements in the stack are
5	4	

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
1
Enter the element to push..!
6

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
1
Enter the element to push..!
7
Stack is full........!!

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
3
The elements in the stack are
6	5	4

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
2
The element poped is 6
Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
2
The element poped is 5
Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
2

Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
2
Stack is empty...!
Please Enter your option...!
1. PUSH	2. POP	3. DISPLAY	4. CHANGE THE STACK	5. EXIT
5

*/
