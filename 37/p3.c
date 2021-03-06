/*   ex  3
implementation of N stack
mohammed jasim */

#include <stdio.h>
#define SIZE 100
#define NUM 30

void push(int [], int, int );
int pop(int [], int);
void display(int [], int);


int n, size;
int top[NUM];

int main(void)
{

        int i, curr, choice, val, pos;
        int stack[SIZE];
        printf("Enter number of stacks\n");
        scanf("%d", &n);
        printf("Enter the size of stack\n");
        scanf("%d", &size);
        for(i=0; i<n; ++i)
                top[i]=-1;
        while(1){
                printf("\n\n");
                for(i=1;i<=n;i++)
                        printf("%d. Stack%d\n", i, i);
                printf("%d. Exit\n", i);
                printf("Choose stack: \n");
                scanf("%d", &curr);
                if(curr==n+1)
                        return 0;
                if(curr<1 || curr >n)
                {
                        printf("Wrong option, please try again\n");
                        continue;
                }
                printf("\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Go to previous menu");
                do{
                        printf("\nPlease choose: ");
                        scanf("%d", &choice);
                        switch(choice)
                        {
                                case 1:
                                        printf("Enter the value: ");
                                        scanf("%d", &val);
                                        push(stack, val, curr);
                                        break;
                                case 2:
                                        if( (val = pop(stack, curr))!=-1 )
                                                printf("%d poped", val);
                                        else
                                                printf("Stack underflow");
                                        break;
                                case 3:
                                        display(stack, curr);
                                        break;
                                case 4:
                                        break;
                                default:
                                        printf("Wrong option");
                                        break;
                        }
                }while(choice!=4);
        }
}


void push(int stack[], int val, int curr)
{
        if(top[curr-1] < size-1)
        {
                stack[ ((curr-1)*size) + (++top[curr-1]) ] = val;
                printf("Pushed to stack%d", curr);
        }
        else
                printf("Stack Overflow");
}

int pop(int stack[], int curr)
{

        if(top[curr-1] >= 0)
        {
                return stack[ ((curr-1)*size) + (top[curr-1]--) ];
        }
        else
                return -1;
}

void display(int stack[], int curr)
{
        int i;
        if(top[curr-1] >= 0)
        {
                printf("Stack is - ");
                for(i= (curr-1)*size + top[curr-1]; i >= (curr-1)*size; --i)
                        printf("%d, ", stack[i]);
        }
        else
                printf("Stack is empty");

}



                    /*   OUTPUT


Enter number of stacks
3
Enter the size of stack
3


1. Stack1
2. Stack2
3. Stack3
4. Exit
Choose stack: 
1
	1. Push
	2. Pop
	3. Display
	4. Go to previous menu
Please choose: 1
Enter the value: 2
Pushed to stack1
Please choose: 1
Enter the value: 12
Pushed to stack1
Please choose: 1
Enter the value: 122
Pushed to stack1
Please choose: 1
Enter the value: 2
Stack Overflow
Please choose: 3
Stack is - 122, 12, 2, 
Please choose: 2
122 poped
Please choose: 4


1. Stack1
2. Stack2
3. Stack3
4. Exit
Choose stack: 
2
	1. Push
	2. Pop
	3. Display
	4. Go to previous menu
Please choose: 1
Enter the value: 1
Pushed to stack2
Please choose: 22
Wrong option
Please choose: 1 
Enter the value: 222 
Pushed to stack2
Please choose: 1
Enter the value: 2222
Pushed to stack2
Please choose: 4


1. Stack1
2. Stack2
3. Stack3
4. Exit
Choose stack: 
3
	1. Push
	2. Pop
	3. Display
	4. Go to previous menu
Please choose: 1
Enter the value: 2
Pushed to stack3
Please choose: 1
Enter the value: 2
Pushed to stack3
Please choose: 1
Enter the value: 22
Pushed to stack3
Please choose: 2
22 poped
Please choose: 4


1. Stack1
2. Stack2
3. Stack3
4. Exit
Choose stack: 
4

*/
