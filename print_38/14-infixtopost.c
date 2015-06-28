/*
   Exp 14:
   Convert Infix Expression to Postfix and Evaluate
   24-02-2015
   S3 R 38 Mohammed Nisham
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 20

//defining stack
struct stacks
{
  int a[max];
  int t;
};
typedef struct stacks stack;
stack s;


void decision(char);
int push(int);
int  pop();
void display();
void evaluate(char);
int menu();

int flag,pftop;
char infix[max],postfix[max];

void main()
{
   while(1)
     {
       s.t=-1;
       pftop=-1;
       int i=-1;
       printf("Enter infix Expresssion : ");
       scanf("%s",infix);
       strcat(infix,")");
       while(infix[++i]!='\0')
	 {
	   char current=infix[i];
	   decision(current);
	 }
       postfix[++pftop]='\0';
       if (s.t!=-1)
	 {
	   printf("Invalid Input");
	   return;
	 }
       else
	 {
	   printf("Postfix Expressin : %s",postfix);
	   i=-1;
      while(postfix[++i]!='\0')
	{
	  char current=postfix[i];
	  evaluate(current);
	}
	 }
       printf("\nResult : %d\n\n",pop());
     }
}
int instack(char ch)
{
   if (ch=='+' || ch=='-')
      return 1;
   else if (ch=='*' || ch=='/')
      return 2;
   else if(ch=='^')
      return 3;
   else if (ch=='(')
     return 0;
   else
      return -1;
}
int incoming(char ch)
{
   if (ch=='+' || ch=='-')
      return 1;
   else if (ch=='*' || ch=='/')
      return 2;
   else if(ch=='^')
      return 4;
   else if (ch=='(')
     return 10;
   else
      return -1;
}
void decision(char cur)
{
   if (cur>='0'&&cur<='9')
      postfix[++pftop]=cur;
   else if(cur=='(')
      push(cur);
   else if (cur=='*' || cur=='/' ||cur=='+' || cur=='-' || cur=='^')
   {
      int dostuff=1;
      do
      {
         char popped=pop();
         if (flag)
         {
            if (incoming(cur)<=instack(popped))
	      {
               postfix[++pftop]=popped;
	      }
            else if (popped=='(')
	      {
		push(popped);
               dostuff=0;
	      }
            else
            {
               push(popped);
               dostuff=0;
            }
         }
         else
            dostuff=0;
      }
      while(dostuff==1);
      push(cur);
   }
   else if(cur==')')
   {
      int dostuff=1;
      do
      {
         char popped=pop();
         if (flag)
         {
            if (popped=='(')
               dostuff=0;
            else
               postfix[++pftop]=popped;
         }
         else
            dostuff=0;
      }
      while(dostuff==1);
   }
}

void evaluate(char cur)
{
   if (cur>='0'&&cur<='9')
     push(cur-'0');
   else if(cur=='+')
   {
      int num1=pop();
      int num2=pop();
      int result=num2+num1;
      push(result);
   }
   else if(cur=='-')
   {
      int num1=pop();
      int num2=pop();
      int result=num2-num1;
      push(result);
   }
   else if(cur=='*')
   {
      int num1=pop();
      int num2=pop();
      int result=num2*num1;
      push(result);
   }
   else if(cur=='/')
   {
      int num1=pop();
      int num2=pop();
      int result=num2/num1;
      push(result);
   }
   else if(cur=='^')
   {
      int num1=pop();
      int num2=pop();
      int result=pow(num2,num1);
      push(result);
   }
}
int push(int val)
{
   if (s.t==max-1)
   {
      printf("Overflow\n");
      return 1;
   }
   else
   {
      s.t++;
      s.a[s.t]=val;
      return 0;
   }
}


int pop()
{
   flag=1;
   if(s.t==-1)
   {
      flag=0;
      return;
   }
   else
   {
      s.t--;
      return(s.a[s.t+1]);
   }
}

void display()
{
   int i=s.t;
   printf("\n");
   for(i=s.t;i>=0;--i)
      printf("%c",s.a[i]);
   printf("\n");
}

/* OUTPUT
Enter infix Expresssion : 2+3*(4+5)+(6*(7/9))
Postfix Expressin : 2345+*+679/*+
Result : 29

Enter infix Expresssion : 2*5+6/2-9/3
Postfix Expressin : 25*62/+93/-
Result : 10

Enter infix Expresssion : 2*3*8*9+4*5/2
Postfix Expressin : 23*8*9*45*2/+
Result : 442


*/
