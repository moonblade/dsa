#include <stdio.h>
#include <stdlib.h>

void submenu(int);
int main()
{
	int choice, in, data, pos;
	while(1)
	{
		printf("\n1. Insert \n2. Delete \n3. Dsiplay \n4. Exit \nPlease Choose: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				submenu(0);
				scanf("%d", &in);
				printf("Enter the data: ");
				scanf("%d", &data);
				switch(in)
				{
					case 1:
						insert(data, in, 0);
						break;
					case 2:
						printf("Enter position: ");
						scanf("%d", &pos);
						insert(data, in, pos);
						break;
					case 3:
						printf("Enter key: ");
						scanf("%d", &pos);
						insert(data, in, pos);
						break;
					case 4:
						printf("Enter key: ");
						scanf("%d", &pos);
						insert(data, in, pos);
						break;
					default:
						break;
				}
			case 2:
				submenu(1);
				scanf("%d", &in);
				switch(in)
				{
					case 1:
						data = delete(in, 0);
						check(data);
						break;
					case 2:
						printf("Enter position: ");
						scanf("%d", &pos);
						data = delete(in, pos);
						check(data);
						break;
					case 3:
						printf("Enter key: ");
						scanf("%d", &pos);
						data = delete(in, pos);
						check(data);
						break;
					case 4:
						printf("Enter key: ");
						scanf("%d", &pos);
						data = delete(in, pos);
						check(data);
						break;
					case 5:
						printf("Enter key to delete: ");
						scanf("%d", &pos);
						data = delete(in, pos);
						check(data);
						break;
					default:
						break;
				}
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
				break;
			default:
				printf("Wrong option, please try again\n");
		}
	}
	return 0;
}

void submenu(int c)
{
	printf("\n1. at end \n2. at given position \n3. after given key \n4. before given key\n");
	if(c==1)
		printf("5. Delete key\n");
	printf("Please Choose: ");
}


void insert(int data, int choice, int pos)
{
	struct node *n, *t;
	int p1;
	n = (struct node *)malloc(sizeof(struct node));
	n->data = data;
	if( h==NULL )
	{
		h = n;
		h->next = h;
	}
	switch(choice)
	{
		case 1:
			t = h;
			while( t->next != h )	t = t->next;
			t->next = n;
			h->next = h;
			break;
		case 2:
			if(pos <= 1)
			{
				t = h;
				while( t->next != h )	t = t->next;
				t->next = n;
				n->next = h
				h = n;
			}
			else
			{
				t = h;
				for( p1=2; p1 < pos && t->next != h; t = t->next, p1++);
				n->next = t->next;
				t->next = n;
			}
			break;
		case 3:
			t = h;
			for(; t->next != h && t->data != pos; t=t->next);
			n->next = t->next;
			t->next = n;
			break;
		case 4:
			t = h;
			if( t->data == pos)
			{
				while(t->next != h)	t=t->next;
				t->next = n;
				n->next = h;
				h = n;
			}
			else
			{
				for(; t->next != h && (t->next)->data != pos; t = t->next);
				n->next = t->next;
				t->next = n;
			}

	}

}
