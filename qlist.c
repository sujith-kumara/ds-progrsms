//queue using linkedlist

#include<stdio.h>
#include<malloc.h>
struct link
  {
    int item;
    struct link *next;
  } ;

typedef struct link node;

node *newnode(int val)
{  node *p;
   p=(node *)malloc(sizeof(node));
   p->item=val;
   p->next=NULL;
}
node *front=NULL,*rear=NULL;
void displayQueue()
 { 
   node *curr;
   curr=front;
   while(curr!=NULL)
   { printf("%d  -  ", curr->item);curr=curr->next;}
  }
int isempty()
{ if(front==NULL)
    return(1);
  else
    return(0);
}
void insert(int val)
{ node *p;
   p=newnode(val);
   if(rear==NULL) /* if the queue empty */
      front=rear=p;
   else
      {rear->next=p;
       rear=p;}
  }


int delete()
{ node *curr=front;
  int item;
  if(!isempty())
  {
    item=curr->item;
    if(front==rear) /* if it is the only item */
       front=rear=NULL;
    else
       front=front->next;
    free(curr);
    return(item);
   }
   else
     printf("queue is empty");
}


int main()
 {
  int ch,po,it;
           
   do
     { printf("\n1. insert\n2. delete\n3. display \n5.quit\n");
       scanf("%d",&ch);
       switch(ch)
       { case 1:printf("value to be inserted: ");
                scanf("%d",&po); insert(po);break;
         case 2:if(!isempty())
                  {printf("Item Deleted: %d",delete());}
		     else
		        printf("Empty\n");
		     break;
	 case 3:displayQueue();break;
         case 5:break;
          default:printf("Invalid choice");
        }
    }while(ch!=5);

}