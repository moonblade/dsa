/*
	Ex No. 10 Implement Priority queue using linked list
	S4R 036 Mohamed Insaf K
	09/02/2015
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	int rank;
	struct node *next;
}*f, *r;

void push(int, int);
int pop();
void display();

int main()
{
	int choice, val, rank;
	f=r= NULL;
	printf("1. Push\n2. Pop\n3. Display\n4. Exit");
	while(1)
	{
		printf("\nPlease Choose: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Input value and rank\n");
				scanf("%d%d", &val, &rank);
				push(val, rank);
				break;
			case 2:
				val = pop();
				if(val == -1)
					printf("Priority Queue underflow");
				else
					printf("%d is poped", val);
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
				break;
			default:
				printf("Wrong option, please try again");
				break;
		}
	}
	return 0;
}


void push(int v, int rank)
{
	struct node *t, *x;
	t = (struct node *)malloc(sizeof(struct node));
	t->val = v;
	t->rank = rank;
	if( !f )
	{
		f=t;
		r=f;
		r->next = NULL;
	}
	else
	{
		if( f->rank > rank)
		{
			t->next = f;
			f=t;
		}
		else
		{
			x=f;
			while( (x->next != NULL) && ((x->next)->rank <= rank) )
				x = x->next;
			t->next = x->next;
			x->next = t;
			if( t->next == NULL)
				r=t;
		}
	}
}

int pop()
{
	struct node *t;
	int val;
	if (!f)
		return -1;
	else
	{
		t = f;
		val = f->val;
		f = f->next;
		free(t);
		return val;
	}
}

void display()
{
	struct node *t;
	if(!f)
		printf("Priority Queue is empty");
	else
	{
		t = f;
		printf("Front - ");
		while (t != NULL)
		{
			printf("%d (%d), ", t->val, t->rank);
			t = t->next;
		}
		printf("\b\b - Rear");
	}
}

/*	SAMPLE OUTPUT

1. Push
2. Pop
3. Display
4. Exit
Please Choose: 1
Input value and rank
1 2

Please Choose: 1
Input value and rank
10 8

Please Choose: 1
Input value and rank
12 1

Please Choose: 3
Front - 12 (1), 1 (2), 10 (8) - Rear
Please Choose: 1
Input value and rank
5 2

Please Choose: 1
Input value and rank
14 1

Please Choose: 3
Front - 12 (1), 14 (1), 1 (2), 5 (2), 10 (8) - Rear
Please Choose: 2
12 is poped
Please Choose: 2
14 is poped
Please Choose: 2
1 is poped
Please Choose: 2
5 is poped
Please Choose: 2
10 is poped
Please Choose: 2
Priority Queue underflow
Please Choose: 3
Priority Queue is empty
Please Choose: 4

*/
