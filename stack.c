// simple stack
#include<stdio.h>
#define max 20
int top=0;
int isempty()
{
 if(top==0)
  return (1);
 else
  return (0);
 }
 int isfull()
  {
   if(top==max)
    return (1);
   else
    return (0);
  }
  void push(int stack[],int item)
   {
    if(!isfull())
     {
     stack[top]=item;
     top++;}
    else
     printf("The stack is full");
    } 
   int pop(int stack[])
    {
     if(!isempty())
      {
      top=top-1;
      return (stack[top]);}
     else
      printf("Stack is empty ");
      return 0;
     }
     int peek(int stack[])
      {
       if(!isempty())
        return (stack[--top]);
       else
        printf("Stack is empty");
        return 0;
       }
      void display(int s[])
      {
       int i;
       printf("The Elements of the stack are");
       for(i=top-1;i>=0;i--)
        printf("\n%d\n",s[i]);
       }
       void main()
       {
        int s[max],choice,ele,b;
        do
        {
         printf("\nEnter your choice\n");
         printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
         scanf("%d",&choice);
         switch(choice)
         {
          case 1:printf("Enter the element to be added\n");
                 scanf("%d",&ele);
                 push(s,ele);
                 break;
          case 2:b=pop(s);
                 if(b==0)
                  break;
                 printf("The top element in the stack is %d\n",b);
                 break;
          case 3:ele=peek(s);
                 printf(" the peekelement is %d\n",ele);
                 break;
          case 4:display(s);
                 
                 break;
          case 5:break;
          default:printf("invalid choice");
          }
         }
          while(choice!=5);
        }
         