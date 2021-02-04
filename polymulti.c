//polynomial multiplication
#include<stdio.h>
#include<stdlib.h>
struct link{
    int coeff,pow;
    struct link *next;
};
typedef struct link poly;
poly *res;// specific for multiplication
poly *newnode()
{
    poly *tmp;
    tmp=(poly*)malloc(sizeof(poly));
    tmp->next=NULL;
    return tmp;
}
poly *readpoly()
{
    int flag;
    poly *temp,*head;
    temp=newnode();
    head=temp;
    do{
        printf("Enter the coefficient & power");
        scanf("%d",&(temp->coeff));
        scanf("%d",&(temp->pow));
        printf("continue adding more terms to the list Y-1,N-0");
        scanf("%d",&flag);
        if(flag)
        {
            temp->next=newnode();
            temp=temp->next;
        }

    }while(flag);
    return head;
}
void displaypoly(poly *node)
{
while(node!=NULL)
{
    printf("%d X^%d",node->coeff,node->pow);
    node=node->next;
    if(node!=NULL)
    {
        printf("+");
    }

}
}//same for polynomial multiplication and addition
//polynomial multiplication starts here
void addterm(int coef,int expo)
{
    poly *prev,*curr=res;
    prev=NULL;
    while(curr!=NULL && curr->pow>expo)//skip all terms with greater exponent than the current expo
    {
        prev=curr;
        curr=curr->next;
    }
    if(curr!=NULL && curr->pow==expo)//if a term with same expo in resultant poly,no need to create a newnode  simply add coeff
    {
        curr->coeff=curr->coeff+coef;
    }
    else
    {
        curr=newnode();
        curr->coeff=coef;
        curr->pow=expo;
    
      if(prev==NULL)//if it is the first node
      {
        curr->next=res;
        res=curr; 
      }
      else
      {
        curr->next=prev->next;
        prev->next=curr;
      }
    }

}
void mulpoly(poly *p1 ,poly *p2)
{
    int coef,expo;
    poly *curr;
    while(p2!=NULL)
    {
        curr=p1;
        while(curr!=NULL)
        {
            coef=curr->coeff * p2->coeff; //calculating coef and expo of new term
            expo=curr->pow+p2->pow;
            addterm(coef,expo);
            curr=curr->next;
        }p2=p2->next;
    }
}
int main()
{
    int ch;
    poly *poly1,*poly2;
    res=NULL;
    do{
        printf("create first expression");
        poly1=readpoly();
        printf("First expression is\n");
        displaypoly(poly1);
        printf("\n Enter the second expression\n");
        poly2=readpoly();
        printf("The second Expression is\n");
        displaypoly(poly2);
        mulpoly(poly1,poly2);
        printf("\nThe resultant polynomial is\n");
        displaypoly(res);
        printf("\n add two more expressions?Y-1,N-0");
        scanf("%d",&ch);
    }while(ch);
    return 0;
}
