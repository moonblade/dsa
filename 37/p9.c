/*
Exp No. 9
Implementation of queue using linked list
2-2-15
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
		int a;
		struct node* n;
	};
struct node h;
struct node *ptr;

int empty(int num)
{
	if(h.n==NULL)
	{
		if(num!=0){printf("\nQueue Empty..!\n");}
		return 1;
	}
	else
		return 0;
}

void add(int num)
{
	struct node* p;
	if(empty(0))
	{
		ptr=h.n;
		ptr=malloc(sizeof h);
		ptr->n=NULL;
		ptr->a=num;
		h.n=ptr;
	}
	else
	{
		ptr=h.n;
		while(ptr->n!=NULL)
		{
			ptr=ptr->n;
		}
		p=malloc(sizeof h);
		p->n=NULL;
		p->a=num;
		ptr->n=p;
	}
}

int del()
{
	int p;
	ptr=h.n;
	p=ptr->a;
	h.n=ptr->n;
	return p;
}

void disp()
{
	ptr=h.n;
	printf("Content of Queue is :\n");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->a);
		ptr=ptr->n;
	}
	printf("\n");
}

void search(int k)
{
	int i=1,f=0;
	ptr=h.n;
	while(ptr!=NULL)
	{
		if(k==ptr->a)
		{
			printf("found at position %d\n",i);
			f=1;
		}
		i++;
		ptr=ptr->n;
	}
	if(f==0)
		printf("Key not found !\n");
}

void main()
{
	int c,num;
	h.n=NULL;
	do
	{
		printf("1. Add\n2. Delete\n3. Display\n4. Search\n5. Exit\n\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("\nInput number : ");
				scanf("%d",&num);
				add(num);
				break;
			case 2:if(!empty(1))
				{
					printf("deleted number is : %d\n",del());
				}
				break;
			case 3:
				if(!empty(1))
				disp();
				break;
			case 4:printf("Enter key to search : ");
				scanf("%d",&num);
				if(!empty(1))
					search(num);
				break;
		}
	}while(c!=5);
}
    




               /*  OUTPUT
1. Add
2. Delete
3. Display
4. Search
5. Exit

1

Input number : 12
1. Add
2. Delete
3. Display
4. Search
5. Exit

1

Input number : 1
1. Add
2. Delete
3. Display
4. Search
5. Exit

1

Input number : 2222
1. Add
2. Delete
3. Display
4. Search
5. Exit

3
Content of Queue is :
12 1 2222 
1. Add
2. Delete
3. Display
4. Search
5. Exit

3
Content of Queue is :
12 1 2222 
1. Add
2. Delete
3. Display
4. Search
5. Exit

2
deleted number is : 12
1. Add
2. Delete
3. Display
4. Search
5. Exit

4
Enter key to search : 222
Key not found !
1. Add
2. Delete
3. Display
4. Search
5. Exit

4
Enter key to search : 1
found at position 1
1. Add
2. Delete
3. Display
4. Search
5. Exit

5
*/

