/*
  Ex 17:
  Double linked linked list
  17-3-2015
  S4 R 38 Mohammed Nisham K
*/

#include<stdio.h>
#include<stdlib.h>
#define max 5
struct nodes
{
  int val;
  struct nodes *next;
  struct nodes *last;
}*f,*r,*t,*h,*p;
typedef struct nodes node;

node* newnode()
{
  p=(node*)malloc(sizeof(node));
  p->next=NULL;
  p->last=NULL;
  p->val=0;
  return p;
}
void in(int,int);
int  del(int);
void display(int);
int menu();
int seach(int);
int menu();

int flag;
int length=0;

void main()
{
  h=NULL;
  printf("MENU \n1.Insert at begining \n2.Insert at end \n3.Insert at given position \n4.Insert after given key \n5.Insert before given key \n");
  printf("6.Delete from begining \n7.Delete from end \n8.Delete from given position \n9.Delete after key \n10.Delete before key \n11.Delete key\n");
  printf("12.Display \n13.display in reverse \n14.Exit");
  while(1)
    {
      int opt=menu();
      int num,pnum,pos,key;
      if(opt>0 && opt <=5)
	{
	  printf("\nEnter number to input : ");
	  scanf("%d",&num);
	  switch(opt)
	    {
	    case 1:
	      in(num,0);
	      break;
	    case 2:
	      in(num,length);
	      break;
	    case 3:
	      printf("Enter posision to insert at : ");
	      scanf("%d",&pos);
	      in(num,pos);
	      break;
	    case 4:
	      printf("Enter key to insert after : ");
	      scanf("%d",&key);
	      pos=search(key);
	      if(pos==-1)
		{
		  printf("Not found");
		  break;
		}
	      in(num,pos);
	      break;
	    case 5:
	      printf("Enter key to insert before : ");
	      scanf("%d",&key);
	      pos=search(key);
	      if(pos==-1)
		{
		  printf("Not found");
		  break;
		}
	      in(num,pos-1);
	      break;
	    }
	} else
	{
	  switch(opt)
	    {
	    case 6:
	      pnum=del(1);
	      if (flag==1)
		printf("%d has been deleted",pnum);
	      break;
	    case 7:
	      pnum=del(length);
	      if (flag==1)
		printf("%d has been deleted",pnum);
	      break;
	    case 8:
	      printf("\nEnter position less than %d : ",length);
	      scanf("%d",&pos);
	      pnum=del(pos);
	      if (flag==1)
		printf("%d has been deleted",pnum);
	      break;
	    case 9:
	      printf("\nEnter key to delete after : ");
	      scanf("%d",&key);
	      pos=search(key);
	      if(pos==-1)
		{
		  printf("Not found");
		  break;
		}
	      pnum=del(pos+1);
	      if (flag==1)
		printf("%d has been deleted",pnum);
	      break;
	    case 10:
	      printf("\nEnter key to delete before : ");
	      scanf("%d",&key);
	      pos=search(key);
	      if(pos==-1)
		{
		  printf("Not found");
		  break;
		}
	      pnum=del(pos-1);
	      if (flag==1)
		printf("%d has been deleted",pnum);
	      break;
	    case 11:
	      printf("\nEnter key to delete : ");
	      scanf("%d",&key);
	      pos=search(key);
	      if(pos==-1)
		{
		  printf("Not found");
		  break;
		}
	      pnum=del(pos);
	      if (flag==1)
		printf("%d has been deleted",pnum);
	      break;
	    case 12:
	      display(1);
	      break;
	    case 13:
	      display(2);
	      break;
	    case 14:
	      return;
	      break;
	    default:
	      printf("Incorrect option\n");
	    }
	}
    }
}

//insert at given position, if gtr than length, insert at end
void in(int val,int pos)
{
  p=newnode();
  p->val=val;
  t=h;
  int i=1;
  while(i<pos && t!=NULL)
    {
      if(t->next==NULL)
        break;
      t=t->next;
      i++;
    }
  if(t!=NULL)
    {
      if(pos==0)
	{
	  p->next=h;
	  h->last=p;
	  h=p;
	  length++;
	  return;
	}
      p->next=t->next;
      p->last=t;
      if(t->next!=NULL)
         t->next->last=p;
      t->next=p;
    }
  else
    {
      p->next=t;
      h=p;
    }
  length++;
}

//delete from given position, if gtr than length, delete from end
int del(int pos)
{
  if(pos>length)
    {
      printf("Enter valid Value\n");
      flag=0;
    }
  else
    {
      flag=1;
      if(h==NULL || length==0)
	{
	  h=NULL;
	  printf("Underflow\n");
	  flag=0;
	  return;
	}
      else
	{
	  p=h;
	  int i=1;
	  while(i<pos && p!=NULL)
	    {
	      p=p->next;
	      i++;
	    }
	  int k;
	  if(p!=NULL)
	    {
	      k=p->val;
              if(p->last!=NULL)
   	         p->last->next=p->next;
              if(p->next!=NULL)
                 p->next->last=p->last;
	    }
	  if(pos<=1)
	    {
	      h=h->next;
	    }
	  if(p!=NULL)
	    free(p);
	  length--;
	  return(k);
	}
    }
}

//search for a given key and return its posititon
int search(int key)
{
  p=h;
  int fl=0,pos=0;
  while(p!=NULL)
    {
      pos++;
      if(p->val==key)
	{
	  fl=1;
	  break;
	}
      p=p->next;
    }
  if(fl)
    return pos;
  else
    return -1;
}

//display the list
void display(int mode)
{
  if(length==0)
    {
      printf("Empty\n");
      return;
    }
  printf("Contents : ");
  p=h;
  if(mode!=1)
    {
       while(p!=NULL)
       {
          if(p->next==NULL)
             break;
          p=p->next;
       }
       while(p!=NULL)
       {
	  printf("%d ",p->val);
	  p=p->last;
	}
      printf("\n");
      return;
    }
  while(p!=NULL)
    {
      printf("%d ",p->val);
      p=p->next;
    }
  printf("\n");
}

int menu()
{
  int opt;
  printf("\nEnter an option : ");
  scanf("%d",&opt);
  if(opt>14 || opt <0)
    {
      printf("Enter a valid option");
      opt=menu();
    }
  return opt;
}


/* OUTPUT
  MENU 
1.Insert at begining 
2.Insert at end 
3.Insert at given position 
4.Insert after given key 
5.Insert before given key 
6.Delete from begining 
7.Delete from end 
8.Delete from given position 
9.Delete after key 
10.Delete before key 
11.Delete key
12.Display 
13.display in reverse 
14.Exit
Enter an option : 1

Enter number to input : 10

Enter an option : 2

Enter number to input : 20

Enter an option : 2

Enter number to input : 30

Enter an option : 2

Enter number to input : 40

Enter an option : 12
Contents : 10 20 30 40 

Enter an option : 13
Contents : 40 30 20 10 

Enter an option : 7
40 has been deleted
Enter an option : 13
Contents : 30 20 10 

Enter an option : 11

Enter key to delete : 20
20 has been deleted
Enter an option : 12
Contents : 10 30 

Enter an option : 13
Contents : 30 10 

Enter an option : 4

Enter number to input : 50
Enter key to insert after : 30

Enter an option : 12
Contents : 10 30 50 

Enter an option : 14 
*/
