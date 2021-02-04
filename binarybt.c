//binary search tree
#include <stdio.h>
#include<stdlib.h>
#define size 25

/* A binary tree node has data, left child and right child */
struct NODE {
	int data;
	struct NODE* left;
	struct NODE*right;
};
typedef struct NODE  node;
 node* newNode(int data)
{
	 node*n;
	n = (node *)malloc(sizeof( node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return (n);
}

node *stack[size];int top=-1;
int isempty()
{ return(top==-1);}
void push(node *item)
{        stack[++top]=item;
 }
node *pop()
{ if(!isempty())
       return(stack[top--]);
}
node *stack1[size];int top1=-1;
int isempty1()
{ return(top1==-1);}
void push1(node *item)
{        stack1[++top1]=item;
 }
node *pop1()
{ if(!isempty1())
       return(stack1[top1--]);
}
node * insertbsearch(int item,node *r)
{  
   node *t,*par,*curr;
   t=newNode(item);
   if(r==NULL)
      r=t;
   else
       { par=NULL;curr=r;
         while(curr!=NULL)
         { par=curr;
           if(item <curr->data)
               curr=curr->left;
           else
               curr=curr->right;
          }
          if(item < par->data)
             par->left=t;
          else
            par->right=t;
        }

    return(r);
}

// An iterative process to print preorder traversal of Binary tree

void preorder(node *r)
{
	
	if (r != NULL)
    {
	     printf("%d  ", r->data);
   	     preorder(r->left);
	     preorder(r->right);
	  }
}



void inorder(node *r)
{
if (r != NULL)
    {    inorder(r->left);
	     printf("%d  ", r->data);
   	     inorder(r->right);
	  }
    
}
void postorder(node *r)
{
if (r != NULL)
    {    postorder(r->left);
	     postorder(r->right);
	     printf("%d  ", r->data);
	  }
    
}
void iterativePreorder(node* root)
{
	node *p;
	if (root == NULL)
		return;
	push(root);
    printf("\n iterative \n");
	while (!isempty())
    {
	       p= pop();
	      printf("%d  ", p->data);
   	     if (p->right !=NULL)
	         push(p->right);
         if (p->left!=NULL)
	         push(p->left);
	}
}
void inOrderI(node *root) 
{ 
	 
	node *curr = root; 

	while (curr != NULL || !isempty()) 
	{ 
		
		while (curr != NULL) 
		{ 
			push(curr); 
			curr = curr->left; 
		} 

		/* Current must be NULL at this point */
		curr = pop(); 
		printf("%d   ", curr->data); 
		curr = curr->right; 
	}
} 
void postOrderIterative(node* root) 
{ 
    if (root == NULL) 
        return; 
  
    
    // push root to first stack 
    push( root); 
    node* curr; 
  
    // Run while first stack is not empty 
    while (!isempty()) { 
        // Pop an item from s1 and push it to s2 
        curr = pop(); 
        push1(curr); 
  
        // Push left and right children of removed item to s1 
        if (curr->left) 
            push( curr->left); 
        if (curr->right) 
            push(curr->right); 
    } 
  
    // Print all elements of second stack 
    while (!isempty1()) { 
        curr = pop1(); 
        printf("%d ", curr->data); 
    } 
} 
int main()
{    node *root=NULL;
     int item=1;
     while(1)
	{   
	  printf("enter a values or  -1 to terminate\n");
                     scanf("%d",&item);
                     if(item==-1)
                       break;
                     root=insertbsearch(item, root);
                    }
    preorder(root);
	iterativePreorder(root);
	printf("\ninorder\n");
	inorder(root);
	printf("\ninorder iterative\n");
	inOrderI(root);
	
	printf("\npostorder\n");
	postorder(root);
	printf("\npostorder  iterative\n");
    postOrderIterative(root);
     return 0;
}