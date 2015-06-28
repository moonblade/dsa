/*
EXP NO: 15
Operations on singly linked list
DATE: 24-03-2015
NO:37
mohammed jasim e

*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node *next;
};
void insert_beg(int);
void insert_end(int);
int delet_beg();
int delet_end();
void display();
int choice(int);
void insert_pos(int);
int delet_pos(int);
struct node *top;
int main()
{
	int num,ch;
        top=NULL;
        while(1)
        {
        printf("\n1.Insertion \n2.Deletion  \n3.EXIT\n");
        printf("\nEnter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1:
                        num=choice(1);
                        break;
                case 2:
                        num=choice(2);
                        break;

                case 3:
                        return 1;
                default:
                        printf("\n invalid choice");
        }
        }

}

void insert_beg(int a)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	if(new==NULL)
		printf("Overflow");
	else
	{
		new->next=top;
		new->val=a;
		top=new;
	}
}
void insert_end(int a)
{
        struct node *new,*ptr,*preptr;
        new=(struct node *)malloc(sizeof(struct node));
        if(new==NULL)
                printf("Overflow");
        else
        {
               ptr=top;
               if(ptr == NULL)
               {
                        new->next=top;
                        new->val=a;
                        top=new;
               }
               else
               {
                       while(ptr->next != NULL)
                       {
                               ptr=ptr->next;
                       }
               ptr->next=new;
               new->val=a;
               new->next=NULL;
               }
        }
}
void insert_pos(int a)
{
        struct node *new,*ptr,*preptr;
        int i,ch;
        new=(struct node *)malloc(sizeof(struct node));
        if(new==NULL)
                printf("Overflow");
        else
        {
               ptr=top;
               preptr=ptr;
               while(ptr != NULL)
               {
                      if(ptr->val == a)
                             break;
                      preptr=ptr;
                      ptr=ptr->next;
               }
               if(ptr == NULL)
                      printf("\nElement not found !!!!!");
               else
               {
                      printf("\nEnter the element to be insert :");
                      scanf("%d",&i);
                      printf("\n1.Before \n2.After\nEnter choice :");
                      scanf("%d",&ch);
                      if(ch == 1)
                      {
                             if(ptr == top)
                             {
                                   top=new;
                                   new->val=i;
                                   new->next=ptr;
                             }
                             else
                             {
                                   preptr->next=new;
                                   new->val=i;
                                   new->next=ptr;
                             }
                      }
                      else
                      {
                             new->val=i;
                             new->next=ptr->next;
                             ptr->next=new;
                      }
               }
        }
}
int delet_beg()
{
	struct node *ptr;
	int a;
	ptr=top;
	if(ptr==NULL)
		return -1;
	else
	{
		top=top->next;
		a=ptr->val;
		free(ptr);
		return a;
	}
}
int delet_end()
{
        struct node *ptr,*preptr;
        int a;
        ptr=top;
        if(ptr==NULL)
                return -1;
        else
        {
               preptr=ptr;
               while(ptr->next != NULL)
                       {
                               preptr=ptr;
                               ptr=ptr->next;
                       }
               a=ptr->val;
               preptr->next=NULL;
               free(ptr);
               return(a);
        }
}

void display()
{
	struct node *ptr;
	ptr=top;
	if(ptr==NULL)
                printf("Underflow");
	else
	{
		while(ptr!=NULL)
		{
			printf("%d \t",ptr->val);
			ptr=ptr->next;
		}
	}
}
int choice(int op)
{
        int pos,ch,num;
        if(op == 1)
        {
              printf("\n1.Insert at begining \n2.insert at end \n3.insert at a position \n4.Display \n5.return \n");
              while(1)
              {
              printf("\nEnter your choice :");
              scanf("%d",&ch);
              switch(ch)
              {
                case 1:
                        printf("Enter a number :");
                        scanf("%d",&num);
                        insert_beg(num);
                        break;
                case 2:
                        printf("Enter a number :");
                        scanf("%d",&num);
                        insert_end(num);
                        break;
                case 3:
                        printf("Enter a number  :");
                        scanf("%d",&num);
                        insert_pos(num);
                        break;
                case 4:
                        display();
                        break;
                case 5:
                        return 1;
                default:
                        printf("Invalid option !!!!!\n");
              }
              }

      }
      if(op == 2)
      {
              printf("\n1.delete at begining \n2.delete at end \n3.delete at a position \n4.Display \n5.return \n");
              while(1)
              {
              printf("\nEnter your choice :");
              scanf("%d",&ch);
              switch(ch)
              {
                case 1:
                        num=delet_beg();
                        if(num==-1)
                                printf("Underflow\n");
                        else
                                printf("The value is : %d\n",num);
                        break;
                case 2:
                        num=delet_end();
                        if(num==-1)
                                printf("Underflow\n");
                        else
                                printf("The value is : %d\n",num);
                        break;
                case 3:
                       printf("\nEnter the position :");
                       scanf("%d",&num);
                        num=delet_pos(num);
                        if(num==-1)
                                printf("Underflow\n");
                        else
                                printf("The value is : %d\n",num);
                        break;
                case 4:
                        display();
                        break;
                case 5:
                        return 1;
                default:
                        printf("Invalid option !!!!!\n");
              }
              }
      }
}

int delet_pos(int p)
{
        struct node *ptr,*preptr;
        int a,i;
        i=1;
        ptr=top;
        preptr=ptr;
        if(ptr==NULL)
                return -1;
        else if(p == 1)
        {
                top=top->next;
                a=ptr->val;
                free(ptr);
                return a;
        }
        else
        {
                while(i < p)
                        {
                              preptr=ptr;
                              ptr=ptr->next;
                              i=i+1;
                        }
                        a=ptr->val;
                        preptr->next=ptr->next;
                        free(ptr);
                        return a;
        }
        return -1;

}









/*  OUTPUT






1.Insertion 
2.Deletion  
3.EXIT

Enter your choice :1

1.Insert at begining 
2.insert at end 
3.insert at a position 
4.Display 
5.return 

Enter your choice :1
Enter a number :12

Enter your choice :1
Enter a number :11

Enter your choice :1
Enter a number :13

Enter your choice :1
Enter a number :10

Enter your choice :4
10 	13 	11 	12 	
Enter your choice :2
Enter a number :20 

Enter your choice :2
Enter a number :21

Enter your choice :4
10 	13 	11 	12 	20 	21 	
Enter your choice :3
Enter a number  :50

Element not found !!!!!
Enter your choice :4
10 	13 	11 	12 	20 	21 	
Enter your choice :5

1.Insertion 
2.Deletion  
3.EXIT

Enter your choice :2

1.delete at begining 
2.delete at end 
3.delete at a position 
4.Display 
5.return 

Enter your choice :3

Enter the position :5
The value is : 20

Enter your choice :4
10 	13 	11 	12 	21 	
Enter your choice :1
The value is : 10

Enter your choice :4
13 	11 	12 	21 	
Enter your choice :2
The value is : 21

Enter your choice :4
13 	11 	12 	
Enter your choice :3

Enter the position :2
The value is : 11

Enter your choice :4
13 	12 	
   */

