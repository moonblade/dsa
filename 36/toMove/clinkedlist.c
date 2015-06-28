/*
   Ex No. 16
   Implementation of Circular Linked list
   S4R 036 Mohamed Insaf K
   30-03-2015
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
   int data;
   struct node *next;
}*h=NULL;


void submenu(int);
void insert(int, int, int);
int delete(int, int);
void check(int);
void display();

int main()
{
   int choice, in, data, pos;
   while(1)
   {
      printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit \nPlease Choose: ");
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
            break;
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
            printf("Enter starting position: ");
            scanf("%d", &pos);
            display(pos);
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
   printf("\n\t1. at end \n\t2. at given position \n\t3. after given key \n");
   if(c==1)
   {
      printf("\t4. Delete key\n");
   }
   else
      printf("\t4. before given key\n");
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
         while( t->next != h )   t = t->next;
         t->next = n;
         n->next = h;
         break;
      case 2:
         if(pos <= 1)
         {
            t = h;
            while( t->next != h )   t = t->next;
            t->next = n;
            n->next = h;
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
            while(t->next != h)   t=t->next;
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

int delete(int choice, int pos)
{
   struct node *t, *t2;
   int data, p1;
   if( h == NULL )
      return -1;
   switch(choice)
   {
      case 1:
         t = h;
         while( (t->next)->next !=h)   t = t->next;
         data= (t->next)->data;
         t2 = t->next;
         t->next = t2->next;
         if( t2==h )
            h = NULL;
         free(t2);
         return data;
         break;
      case 2:
         if(pos == 1)
         {
            t=h;
            while(t->next != h)    t = t->next;
            t2 = h;
            data = h->data;
            h = h->next;
            t->next = h;
            if( t2==h )
               h = NULL;
            free(t2);
            return data;
         }
         else if(pos>1)
         {
            t = h;
            for( p1 = 2; p1<pos && t->next != h; t = t->next, p1++);
            if( (p1==2 || p1<=pos) && t->next == h )
            {
               return -1;
            }
            t2 = t->next;
            t->next = t2->next;
            data = t2->data;
            if( t2 == h)
               h = NULL;
            free(t2);
            return data;
         }
         else
            return -1;
         break;
      case 3:
         t=h;
         for(; t->data != pos && t->next != h; t= t->next);
         t2 = t->next;
         if( t->data == pos)
         {
            data = t2->data;
            t->next = t2->next;
            if( t2== h)
            {
               if(h->next == t2)
                  h = NULL;
               else
                  h = h->next;
            }

            free(t2);
            return data;
         }
         else
            return -1;
         break;
      case 4:
         t = h;
         while( (t->next)->data != pos && t->next != h)   t = t->next;
         if( (t->next)->data == pos)
         {
            t2 = t->next;
            data = t2->data;
            t->next = t2->next;
            if( t2==h )
               if(h->next == h)
                  h = NULL;
               else
                  h = h->next;
            return data;
         }
         else
            return -1;
         break;
         default:
            break;
   }
}

void check(int data)
{
   if(data == -1)
      printf("Couldn't delete\n");
   else
      printf("Deleted %d\n", data);
}

void display(int pos)
{
   struct node *t;
   int temp;
   t = h;
   if( !t )
   {
      printf("Empty list\n");
      return;
   }
   if(pos<=0)
   {
      printf("position doesn't exisit\n");
      return;
   }
   for(temp = pos; temp > 1 && t->next != h;temp--, t = t->next);
   //after executing loop; temp > 1 true means the position exceeds size of list
   if( temp > 1)
   {
      printf("position exceeds size of list\n");
      return;
   }
   for(; t->next!=h; t=t->next)
      printf("%d, ", t->data);
   printf("%d, ", t->data);
   for(temp=1, t=t->next; temp < pos; t=t->next, temp++)
      printf("%d, ", t->data);
}

/*      SAMPLE OUTPUT

1. Insert 
2. Delete 
3. Display 
4. Exit 
Please Choose: ^C
s1336@linux-server:~/s4$ clear

s1336@linux-server:~/s4$ ./a.out

1. Insert 
2. Delete 
3. Display 
4. Exit 
Please Choose: 1

   1. at end 
   2. at given position 
   3. after given key 
   4. before given key
Please Choose: 1 
Enter the data: 1

1. Insert 
2. Delete 
3. Display 
4. Exit 
Please Choose: 1

   1. at end 
   2. at given position 
   3. after given key 
   4. before given key
Please Choose: 1
Enter the data: 2

1. Insert 
2. Delete 
3. Display 
4. Exit 
Please Choose: 1

   1. at end 
   2. at given position 
   3. after given key 
   4. before given key
Please Choose: 1
Enter the data: 3

1. Insert 
2. Delete 
3. Display 
4. Exit 
Please Choose: 1

   1. at end 
   2. at given position 
   3. after given key 
   4. before given key
Please Choose: 1
Enter the data: 4

1. Insert 
2. Delete 
3. Display 
4. Exit 
Please Choose: 3
Enter starting position: 1
1, 2, 3, 4, 
1. Insert 
2. Delete 
3. Display 
4. Exit 
Please Choose: 2

   1. at end 
   2. at given position 
   3. after given key 
   4. Delete key
Please Choose: 1
Deleted 4

1. Insert 
2. Delete 
3. Display 
4. Exit 
Please Choose: 3
Enter starting position: 2
2, 3, 1, 
1. Insert 
2. Delete 
3. Display 
4. Exit 
Please Choose: 3
Enter starting position: 1
1, 2, 3, 
1. Insert 
2. Delete 
3. Display 
4. Exit 
Please Choose: 4
*/
