//stack using linkedlist

#include<stdio.h>
#include<malloc.h>
struct link
  {
    int item;
    struct link *next;
  } ;

typedef struct link node;
node *top=NULL;
node *newnode(int val)
{  node *p;
   p=(node *)malloc(sizeof(node));
   p->item=val;
   p->next=NULL;
}

void displaystack()
 { 
   node *curr;
   curr=top;
   while(curr!=NULL)
   { printf("%d  -  ", curr->item);curr=curr->next;}
  }
int isempty()
{ if(top==NULL)
    return(1);
  else
    return(0);
}
void push(int val)
{ node *p;
   p=newnode(val);
   p->next=top;
   top=p;
}


int pop()
{ node *curr=top;
  int item;
  if(!isempty())
  {
    item=top->item;
    top=top->next;
    free(curr);
    return(item);
   }
   else
     printf("stack empty");
}


int main()
 {
  int ch,po,it;
           
   do
     { printf("\n1. push\n2. pop\n3. display \n5.quit\n");
       scanf("%d",&ch);
       switch(ch)
       { case 1:printf("value to be inserted: ");
                scanf("%d",&po); push(po);break;
         case 2:if(!isempty())
                  {printf("Item poped : %d",pop());}
		else
		   printf("Empty\n");
		break;
	 case 3:displaystack();break;
         case 5:break;
          default:printf("Invalid choice");
        }
    }while(ch!=5);

}
