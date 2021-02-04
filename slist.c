//singly linked list without declaring head as global

#include<stdio.h>
#include<malloc.h>
struct NODE
  {
    int item;
    struct NODE *link;
  } ;
typedef struct NODE node;

node *newnode(int val)
{  node *p;
   p=(node *)malloc(sizeof(node));
   p->item=val;
   p->link=NULL;
}

void displaylist(node *h)
 { 
   node *curr;
   curr=h;
   while(curr!=NULL)
   { printf("%d  -  ", curr->item);curr=curr->link;}
  }

node * insertfirst(node *h,int val)
{ node *p;
   p=newnode(val);
   p->link=h;
   return(p);
}

node * insertbefore(node *h,int item1,int val)
{ node *curr=h,*prev=NULL,*p;
  while(curr!=NULL && curr-> item != item1)
    {prev=curr;curr=curr->link;}
  if(curr==NULL)
     {printf("Item Not Found\n");return(h);}
  else
      { p=newnode(val);
        p->link= curr;
        if(curr==h)
          h=p;
        else
          prev->link=p;
        return(h);
       }
}

void insertafter(node *h,int item1,int val)
{ node *curr=h,*p;
  while(curr!=NULL && curr-> item != item1)
    {curr=curr->link;}
  if(curr==NULL)
     printf("Item Not Found\n");
  else
       {p=newnode(val);
       p->link= curr->link;
       curr->link=p;
       }
}


int main()
 {
  int ch,po,it;
    node *head=NULL;       
   do
     { printf("\n1. insert first\n2. Insert after\n3. display \n4. insert before\n5.quit");
       scanf("%d",&ch);
       switch(ch)
       { case 1:printf("value to be inserted first:");
                scanf("%d",&po);head= insertfirst(head,po);break;
         case 2:printf("enter item after which an element is inserted ");
                scanf("%d",&it);
                printf("value to be inserted:");
                scanf("%d",&po);insertafter(head,it,po);break;
	case 4:printf("enter item ");
                scanf("%d",&it);
                printf("value to be inserted:");
                scanf("%d",&po);head=insertbefore(head,it,po);break;
         case 3:displaylist(head);break;
         case 5:break;
          default:printf("Invalid choice");
        }
    }while(ch!=5);

}