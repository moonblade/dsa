/*
       Ex No. 8
       Implementation of token processing at bank counter
       S4R 036  Mohamed Insaf K
       03-02-2015
*/
#include <stdio.h>
#include <stdlib.h>


struct Customer
{
       char name[100];
       int acc;
};

struct node{
       struct Customer customer;
       struct node *next;
}*f, *r;

void add_customer(struct Customer );
void delete_customer();
void display();
void read(char *);

int count;

int main(void)
{
       struct Customer temp;
       int choice, val;
       f = r = NULL;
       count = 0;
       printf("\n\n1. Add new customer to the queue\n"
       "2. Delete the customer in the front\n"
       "3. Display the details of the customer in the front\n"
       "4. Exit\n");
       while(1)
       {
              printf("\nPlease Choose: ");
              scanf("%d", &choice);
              switch(choice)
              {
                     case 1:
                            printf("Number of customers in the queue: %d\n", count);
                            printf("Enter customer name and account number\n");
                            read(temp.name);
                            scanf("%d", &temp.acc);
                            add_customer(temp);
                            break;
                     case 2:
                            delete_customer();
                            printf("Number of customers remaining: %d", count);
                            break;
                     case 3:
                            display();
                            break;
                     case 4:
                            return 0;
                            break;
                     default:
                            printf("Wrong option please try again\n");
              }
       }

}

void read(char *name)
{
       int ch;
       while( (ch=getchar()) == '\n'); //Flush stdin
       do
       {
              *(name++) = ch;
       }while( (ch = getchar()) != '\n');
       *name = '\0';
}
void add_customer(struct Customer customer)
{

       struct node *t;
       t = (struct node *)malloc( sizeof(struct node ));
       t->customer = customer;
       if( f== NULL)
       {
              f = t;
              r = t;
       }
       else
       {
              r->next = t;
              r = t;
       }
       r->next = NULL;
       count++;
}

void delete_customer()
{
       if ( f == NULL )
              printf("No more customers to delete\n");
       else
       {
              struct node *t;
              printf("Deleted ");
              display();
              t = f;
              f = f->next;
              free(t);
              count--;
       }
}

void display()
{
       if( f != NULL )
       {
              printf("Customer: \tName: %s\tAccount Number: %d\n",f->customer.name, f->customer.acc);
       }
       else
              printf("No customers found\n");
}

/*       SAMPLE OUTPUT
1. Add new customer to the queue
2. Delete the customer in the front
3. Display the details of the customer in the front
4. Exit

Please Choose: 1
Number of customers in the queue: 0
Enter customer name and account number
John AB
1001

Please Choose: 1
Number of customers in the queue: 1
Enter customer name and account number
Moh Jasim
1012

Please Choose: 3
Customer:        Name: John AB       Account Number: 1001

Please Choose: 2
Deleted Customer:        Name: John AB       Account Number: 1001
Number of customers remaining: 1
Please Choose: 2
Deleted Customer:        Name: Moh Jasim       Account Number: 1012
Number of customers remaining: 0
Please Choose: 2
No more customers to delete
Number of customers remaining: 0
Please Choose: 3
No customers found

Please Choose: 4
*/
