/*
Exp No. 8
Token Processing in queue
2-2-15
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void disp(int,int);
int token;
struct node{
		int tno;
		char cname[20];
		struct node* n;
	};
struct node h;
struct node *ptr;

int empty(int num)
{
	if(h.n==NULL)
	{
		if(num!=0)
		{	printf("\nQueue Empty................!\n");
		}
		return 1;
	}
	else
		return 0;
}

void add(struct node ob)
{
	printf("Adding token- %d to queue............",ob.tno);
	struct node* p;
	if(empty(0))
	{
		ptr=h.n;
		ptr=malloc(sizeof h);
		ptr->n=NULL;
		ptr->tno=ob.tno;
		strcpy(ptr->cname,ob.cname);
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
		p->tno=ob.tno;
		strcpy(p->cname,ob.cname);
		ptr->n=p;
	}
	printf("DONE\n");
	disp(1,0);
}

int del()
{
	int p;
	disp(0,1);
	ptr=h.n;
	p=ptr->tno;
	h.n=ptr->n;
	if(empty(0))
		token=1;
	return p;
}

void disp(int f,int g)
{
	int i=1;
	ptr=h.n;
	if(g==1)
	{	printf("Token no. : %d\n",ptr->tno);
		printf("Name      : %s\n",ptr->cname);
	}
		while(ptr->n!=NULL)
		{
			ptr=ptr->n;
			i++;
		}
	if(f==1)
		printf("%d customers  in queue\n",i);
}

void main()
{
	struct node obj;
	int c,num;
	token=1;
	//printf("\n%d\n",token);
	h.n=NULL;
	do
	{
		printf("1. Add\n2. Delete\n3. Display\n4. Exit\n\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("\ninput name : ");
				scanf("%s",obj.cname);
				obj.tno=token;
				//token+=1;
				//printf("\n%d\n",token);
				obj.n=NULL;
				add(obj);
				token+=1;
				break;
			case 2:ptr=h.n;
				if(!empty(1))
				{
					printf("token - %d  deleted..\n",del());
				}
				break;
			case 3:
				if(!empty(1))
				disp(1,1);
				ptr=h.n;
				break;
		}
	}while(c!=4);
}


            /*   OUTPUT
1. Add
2. Delete
3. Display
4. Exit

1

input name : jas
Adding token- 1 to queue............DONE
1 customers  in queue
1. Add
2. Delete
3. Display
4. Exit

1

input name : ins
Adding token- 2 to queue............DONE
2 customers  in queue
1. Add
2. Delete
3. Display
4. Exit

1

input name : thab
Adding token- 3 to queue............DONE
3 customers  in queue
1. Add
2. Delete
3. Display
4. Exit

1

input name : shu
Adding token- 4 to queue............DONE
4 customers  in queue
1. Add
2. Delete
3. Display
4. Exit

3
Token no. : 1
Name      : jas
4 customers  in queue
1. Add
2. Delete
3. Display
4. Exit

3
Token no. : 1
Name      : jas
4 customers  in queue
1. Add
2. Delete
3. Display
4. Exit

2
Token no. : 1
Name      : jas
token - 1  deleted..
1. Add
2. Delete
3. Display
4. Exit

3
Token no. : 2
Name      : ins
3 customers  in queue
1. Add
2. Delete
3. Display
4. Exit

2
Token no. : 2
Name      : ins
token - 2  deleted..
1. Add
2. Delete
3. Display
4. Exit

3
Token no. : 3
Name      : thab
2 customers  in queue
1. Add
2. Delete
3. Display
4. Exit

4
*/
