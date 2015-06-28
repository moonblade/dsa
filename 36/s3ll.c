/*
        Ex No. 25
        Menu driver program to create linked list in LIFO and FIFO order.
        25/09/2014
        S3R 036 Mohamed Insaf K
*/


#include <stdio.h>
#include <stdlib.h>

struct node{
        int val;
        struct node *next;
        };
struct node *s, *r, *f;

void menu();
void q_push();
void q_pop();
void q_display();
void s_push();
void s_pop();
void s_display();

int main(void)
{
        int  choice;
        s=NULL;
        r=NULL;
        f=NULL;
        do{
                printf("1. FIFO\n2. LIFO\n3. Exit \nPlease Choose\n");
                scanf("%d", &choice);
                if(choice==1)
                {
                        do{
                                menu();
                                scanf("%d", &choice);
                                        switch(choice)
                                        {
                                                case 1:
                                                        q_push();
                                                        break;
                                                case 2:
                                                        q_pop();
                                                        break;
                                                case 3:
                                                        q_display();
                                                        break;
                                                case 4:
                                                        return 0;
                                                default:
                                                        printf("Please try again\n");
                                        }
                        }while(choice!=4);
                }else if(choice==2)
                {
                        do{
                                menu();
                                scanf("%d", &choice);
                                        switch(choice)
                                        {
                                                case 1:
                                                        s_push();
                                                        break;
                                                case 2:
                                                        s_pop();
                                                        break;
                                                case 3:
                                                        s_display();
                                                        break;
                                                case 4:
                                                        return 0;
                                                default:
                                                        printf("Please try again\n");
                                        }
                        }while(choice!=4);
                }
                else if(choice==3)
                        return 0;
                else
                        printf("Wrong option, try again\n");
        }while(1);
}



void menu()
{
        printf("\n1. Add \n2. Pop \n3. Display \n4. Exit\nPlease Choose\n");
}

void s_push()
{
        struct node *t;
        int v;
        printf("Enter the value\n");
        scanf("%d", &v);
        t = (struct node *)malloc(sizeof(struct node));
        t->val=v;
        t->next=s;
        s=t;
}

void s_pop()
{
        int v;
        struct node *t;
        if(s!=NULL)
        {
                t=s;
                s=s->next;
                v=t->val;
                free(t);
                printf("%d is poped. \n", v);
        }
        else
                printf("List is empty. \n");
}
void s_display()
{
        if(s!=NULL)
        {
                struct node *t;
                t=s;
                while( t!=NULL )
                {
                        printf("%d, ", t->val);
                        t=t->next;
                }
        }else
                printf("List is empty.\n");
}

void q_push()
{
        struct node *t;
        int val;
        printf("Enter the value\n");
        scanf("%d", &val);
        t = (struct node *)malloc(sizeof(struct node *));
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

void q_pop()
{
        int v;
        struct node *t;
        if(f!=NULL)
        {
                v = f->val;
                t=f;
                f=f->next;
                free(t);
                printf("%d is poped\n", v);
        }
        else
                printf("List is empty\n");
}

void q_display()
{
        struct node *t;
        t=f;
        if(!t)
                printf("List is empty\n");
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
 
/*        OUTPUT
 1)
 1. FIFO
 2. LIFO
 3. Exit 
 Please Choose
 1
 
 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 1
 Enter the value
 10
 
 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 1
 Enter the value
 20
 
 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 1
 Enter the value
 30
 
 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 1
 Enter the value
 40
 
 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 1
 Enter the value
 50
 
 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 3
 front - 10, 20, 30, 40, 50,  - rear
 
 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 2
 10 is poped 

 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 3
 front - 20, 30, 40, 50,  - rear

 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 4

2)
 1. FIFO
 2. LIFO
 3. Exit 
 Please Choose
 2
 
 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 1
 Enter the value
 10 

 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 1
 Enter the value
 20

 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 1
 Enter the value
 30
 
 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 3
 30, 20, 10, 
 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 2
 30 is poped. 

 1. Add 
 2. Pop 
 3. Display 
 4. Exit
  Please Choose
 2
 20 is poped. 

 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 2
 10 is poped.  

 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 2
 List is empty. 

 1. Add 
 2. Pop 
 3. Display 
 4. Exit
 Please Choose
 4

*/
