/*
	Ex No. 7
	Implementation of deque
	S4R 036 Mohamed Insaf K
	02-03-2015
*/

#define MAX 4
#include <stdio.h>

int q[MAX], f, r;

int pushR(int );
int pushF(int );
int popF();
int popR();
void display();
void menu(int );
void initialise();

int main(void)
{
	int choice, type, val;
	initialise();
	while(1)
	{
		printf("1. Entry restricted deque\n2. Exit restricted deque\n3. Exit\nPlease Choose: ");
		scanf("%d", &type);
		if(type == 1)
		{
			menu(type);
			do
			{
				printf("\nPlease choose: ");
				scanf("%d", &choice);
				switch(choice)
				{
					case 1:
						printf("Input value: ");
						scanf("%d", &val);
						if(pushR(val))
							printf("Enqueued");
						else
							printf("Queue overflow");
						break;
					case 2:
						if(val=popF())
							printf("%d dequed", val);
						else
							printf("Queue underflow");
						break;
					case 3:
						if(val=popR())
							printf("%d dequed", val);
						else
							printf("Queue underflow");
						break;
					case 4:
						display();
						break;
					case 5:
						break;
					default:
						printf("Wrong option please try again");
				}
			}while(choice != 5);
		}
		else if(type == 2)
		{
			menu(type);
			do
			{
				printf("\nPlease choose: ");
				scanf("%d", &choice);
				switch(choice)
				{
					case 1:
						printf("Input value: ");
						scanf("%d", &val);
						if(pushR(val))
							printf("Enqueued");
						else
							printf("Queue overflow");
						break;
					case 2:
						if(val=popF())
							printf("%d dequed", val);
						else
							printf("Queue underflow");
						break;
					case 3:
						printf("Input value: ");
						scanf("%d", &val);
						if(pushF(val))
							printf("Enqueued");
						else
							printf("Queue overflow");
						break;
					case 4:
						display();
						break;
					case 5:
						break;
					default:
						printf("Wrong option please try again");
				}
			}while(choice != 5);
		}
		else if(type == 3)
			return 0;
		else
			printf("Wrong option, please try again\n");
	}
}

void menu(int c)
{
	printf("1. Enqueue at rear\n"
		"2. Dequeue at front\n");
	if( c == 1 )
		printf("3. Dequeue at rear");
	else
		printf("3. Enqueue at front");
	printf("\n4. Display\n"
		"5. Go back to previous menu\n");
}
void initialise()
{
	f = r = -1;
}

int pushF(int val)
{
	if( f>0 )
	{
		q[--f] = val;
		return 1;
	}
	else if( f==-1 )
	{
		q[++f] = val;
		++r;
		return 1;
	}
	else
		return 0;
}

int pushR(int val)
{
	if( f==-1 )
		f++;
	if( r < MAX - 1)
	{
		q[++r]=val;
		return 1;
	}
	else
		return 0;
}

int popF()
{
	int val;
	if(f<r)
		return q[f++];
	else if( f==r && f!=-1)
	{
		val = q[f];
		initialise();
		return val;
	}
	else
		return 0;
}



int popR()
{
	int val;
	if(r>f)
		return q[r--];
	else if( f==r && f!=-1)
	{
		val = q[r];
		initialise();
		return val;
	}
	else
		return 0;
}

void display()
{
	int i;
	if(f != -1)
	{
		printf("Front - ");
		for( i = f; i <= r; ++i)
			printf("%d, ", q[i]);
		printf("- Rear");
	}
	else
		printf("Queue is empty");
}



/*	SAMPLE OUTPUT

1. Entry restricted deque
2. Exit restricted deque
3. Exit
Please Choose: 1
1. Enqueue at rear
2. Dequeue at front
3. Dequeue at rear
4. Display
5. Go back to previous menu

Please choose: 1
Input value: 1
Enqueued
Please choose: 1
Input value: 2
Enqueued
Please choose: 1
Input value: 3
Enqueued
Please choose: 4
Front - 1, 2, 3, - Rear
Please choose: 1
Input value: 4
Enqueued
Please choose: 1
Input value: 5
Queue overflow
Please choose: 4
Front - 1, 2, 3, 4, - Rear
Please choose: 2
1 dequed
Please choose: 3
4 dequed
Please choose: 4
Front - 2, 3, - Rear
Please choose: 5
1. Entry restricted deque
2. Exit restricted deque
3. Exit
Please Choose: 2
1. Enqueue at rear
2. Dequeue at front
3. Enqueue at front
4. Display
5. Go back to previous menu

Please choose: 4
Front - 2, 3, - Rear
Please choose: 1
Input value: 10
Enqueued
Please choose: 3
Input value: 1
Enqueued
Please choose: 4
Front - 1, 2, 3, 10, - Rear
Please choose: 3
Input value: 5
Queue overflow
Please choose: 1
Input value: 6
Queue overflow
Please choose: 4
Front - 1, 2, 3, 10, - Rear
Please choose: 2
1 dequed
Please choose: 2
2 dequed
Please choose: 2
3 dequed
Please choose: 2
10 dequed
Please choose: 2
Queue underflow
Please choose: 4
Queue is empty
Please choose: 5
1. Entry restricted deque
2. Exit restricted deque
3. Exit
Please Choose: 3
*/
