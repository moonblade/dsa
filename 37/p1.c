/*     Exp no:1
        Implementation of stack using array
        6/1/2015
        s4  37
        */
        #include<stdio.h>
        int top;
        void push(int array[100],int max,int val)
        {
                if(top==max)
                printf("stack overflow\n");
                else 
                {
                array[top+1]=val;
                top++;
                }
        }
        int pop(int array[100])
      {
                int val;
                if(top==-1)
                {
                printf("stack underflow\n");
                val=-1;
                }
                else
                {
                val=array[top];
                top--;
                }
                return val;
        }
        void display(int array[100])
        {
                int i;
                if(top==-1)
                printf("stack underflow\n");
                else 
                {
                i=top;
                while(i!=-1)
                        {
                        printf("%d ",array[i]);
                        i--;
                        }
                printf("\n");
                }
        }
      int search(int array[100],int key)
        {
        int i;
        i=top;
        while(i!=-1)
                {
                if(key==array[i])
                return i;
                i--;
                }
        return -1;
        }

void main()
{
        int max,ch,array[100],val,v,key,pos;
        top=-1;
        printf("enter size\n");
        scanf("%d",&max);
        max=max-1;
        printf("choose option \n");
        printf("1:push\n2:pop\n3:display\n4:search\n5:exit\n");
        do
        {
         printf("Input choice \n");

   scanf("%d",&ch);
        switch(ch)
        {
                case 1:printf("enter the elements to be pushed\n");
                scanf("%d",&val);
                push(array,max,val);
                break;
        case 2:v=pop(array);
              if(v==-1)
                printf("stack underflow\n");
                else 
                printf("%d is popped\n",v);
                break;
        case 3:display(array);
                break;
        case 4:if(top==-1)
                printf("stack underflow\n");
                else 
                {
                printf("enter key value\n");
                scanf("%d",&key);
                if((pos=search(array,key))==-1)
                printf("couldn't find %d\n",key);
                else 
                printf("found at position %d\n",pos+1);
                }
                break;
        default:break;
        }
        }while(ch!=5);
}



     /*   output
enter size
5
choose option 
1:push
2:pop
3:display
4:search
5:exit
Input choice 
1
enter the elements to be pushed
2
Input choice 
1
enter the elements to be pushed
5
Input choice 
1
enter the elements to be pushed
4
Input choice 
1
enter the elements to be pushed
6
Input choice 
1
enter the elements to be pushed
2
Input choice 
1
enter the elements to be pushed
1
stack overflow
Input choice 
3
2 6 4 5 2 
Input choice 
4
enter key value
5
found at position 2
Input choice 
4
enter key value
6
found at position 4
Input choice 
1
enter the elements to be pushed
9
stack overflow
Input choice 
4
enter key value
9
couldn't find 9
Input choice 
2
2 is popped
Input choice 
2
6 is popped
Input choice 
2
4 is popped
Input choice 
2
5 is popped
Input choice 
2
2 is popped
Input choice 
3
stack underflow
Input choice 
2
stack underflow
stack underflow

*/
