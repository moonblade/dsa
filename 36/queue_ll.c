/*
        Ex No. 9
	Implementation of queue using linked list
        23/02/2015
        S4R 036 Mohamed Insaf K
*/


#include <stdio.h>
#include <stdlib.h>

struct node{
        int val;
        struct node *next;
        };
struct node *r, *f;

void push(int );
int pop();
void display();

int main(void)
{
	int  choice, val;
	r=NULL;
	f=NULL;
	printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n\n");
	do{
		printf("Please choose: ");
		scanf("%d", &choice);
		switch(choice)
		{
			 case 1:
				printf("Enter the value to be enqueued\n");
				scanf("%d", &val);
				push(val);
				break;
			case 2:
				if((val=pop())!=-1)
					printf("%d dequeued\n", val);
				else
					printf("Queue underflow\n");
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("Wrong option please try again\n");
		}
	}while(choice !=4);
	return 0;
}

void push(int val)
{
        struct node *t;
        t = (struct node *)malloc(sizeof(struct node ));
        t->val=val;
        t->next=NULL;
        if(f==NULL)
        {
                f=t;
                r=t;
        }
        else
        {
                r->next=t;
                r=t;
        }
}

int pop()
{
        int v;
        struct node *t;
        if(f!=NULL)
        {
                v = f->val;
                t=f;
                f=f->next;
                free(t);
		return v;
        }
        else
		return -1;
}

void display()
{
        struct node *t;
        t=f;
        if(!t)
                printf("Queue is empty\n");
        else
        {
                printf("front - ");
                while(t!=NULL)
                {
                        printf("%d, ", t->val);
                        t=t->next;
                }
                printf(" - rear\n");
        }
}

/*	SAMPLE OUTPUT


1. Enqueue
2. Dequeue
3. Display
4. Exit

Please choose: 1
Enter the value to be enqueued
1
Please choose: 1
Enter the value to be enqueued
2
Please choose: 1
Enter the value to be enqueued
3
Please choose: 1
Enter the value to be enqueued
4
Please choose: 3
front - 1, 2, 3, 4,  - rear
Please choose: 2
1 dequeued
Please choose: 3
front - 2, 3, 4,  - rear
Please choose: 2
2 dequeued
Please choose: 2
3 dequeued
Please choose: 2
4 dequeued
Please choose: 2
Queue underflow
Please choose: 3
Queue is empty
Please choose: 4

*/
