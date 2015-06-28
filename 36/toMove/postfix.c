/*
   Ex No. 14
   Infix to postfix and hence evaluate it
   S4R 036 Mohamed Insaf K
   09/03/2015
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 500

struct node{
   int val;
   struct node *next;
};
int push(int, struct node **);
int pop(struct node **);
int priority(char );
int power(int, int);

int main(void)
{
   char ch, postfix[MAX];
   char *t = postfix;
   int val, choice, temp;
   int R, L, result;
   struct node *stack1 = NULL;
   printf("Enter infix expressions: ");
   while( (ch = getchar()) != '\n')
   {
      if( ch >= '0' && ch <='9' )
         *(t++) = ch;
      else if( ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' )
      {
         if(stack1 == NULL || priority(stack1->val) < priority(ch))
         {
            push(ch, &stack1);
         }
         else
         {
            do
            {
                                   *(t++) = pop(&stack1);
            }while( stack1 != NULL && priority(stack1->val) >= priority(ch) );
            push(ch, &stack1);
         }
      }
      else if( ch=='(')
         push(ch, &stack1);
      else if( ch==')' )
      {
         temp = 0;
         while( stack1!=NULL && (temp=pop(&stack1)) != '(' )
            *(t++) = temp;
         if( temp != '(' )
         {
            printf("Invalid expression given\n");
            return 0;
         }
      }
   }
   while(stack1!=NULL)
   {
      *(t++) = pop(&stack1);
   }
   *t = '\0';
   printf("\nPostfix expression is:\t%s\n", postfix);

   //Evaluation of postfix
   for( t=postfix; *t != '\0'; t++)
   {
      if( *t >= '0' && *t <='9' )
      {
         push( *t -'0', &stack1);
      }
      else
      {
         R =  pop(&stack1);
         L =  pop(&stack1);
         switch(*t)
         {
         case '+':   result = L+R; break;
         case '-':   result = L-R; break;
         case '*':   result = L*R; break;
         case '/':   result = L/R; break;
         case '^':   result = power(L, R); break;
         }
         push(result, &stack1);
      }
   }
   printf("Result of the expression is %d\n", pop(&stack1));

   return 0;
}


int push(int val, struct node **top)
{
   struct node *temp;
   temp = (struct node *)malloc(sizeof(struct node));
   if( temp != NULL)
   {
      temp->val = val;
      temp->next = *top;
      *top = temp;
      return 1;
   }
   return 0;
}

int pop(struct node **top)
{
   int val;
   struct node *temp;
   if( *top != NULL)
   {
      val = (*top)->val;
      temp = *top;
      *top = (*top)->next;
      free(temp);
      return val;
   }
   else
      return -1;
}

int priority(char s)
{
   if( s=='(' )
      return 1;
   else if( s=='+' || s=='-')
      return 5;
   else if( s=='*' || s=='/')
      return 6;
   else if( s=='^')
      return 9;
   else
      return 0;
}

int power(int base, int power)
{
   int result=1;
   for(; power != 0; power--)
      result *= base;
   return result;
}


/*   SAMPLE OUTPUT

1)
Enter infix expressions: ((1+2)*3-5)

Postfix expression is:   12+3*5-
Result of the expression is 4

2)
Enter infix expressions: 1+5*9-4

Postfix expression is:   159*+4-
Result of the expression is 42

3)
Enter infix expressions: (5*7+2))
Invalid expression given.

4)
Enter infix expressions: ((1+2)^5)

Postfix expression is:   12+5^
Result of the expression is 243

*/
