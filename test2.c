#include<stdio.h>
#include<stdlib.h>
#define size 50
struct NODE
{
    int vertex;
    struct NODE* next;
};
typedef struct NODE node;
int q[size];
int f=-1,r=-1;
int isempty()
{return(f==-1);}
int isfull()
{
    return(f==(r+1)%size);
}
void insert(int p)
{
    if(isfull())
     { printf("Error queue is full");
     exit(0);}
    else
     {
         if(isempty())
           f=r=0;
         else
           r=(r+1)%size;
        q[r]=p;
     }
}
int delete()
{
    int p;
    if(isempty())
    {
        printf("Error q is Empty");
        exit(0);
    }
    else
    {
        p=q[f];
        if(f==r)
          f=r=-1;
        else 
          f=(f+1)%size;
        
    }
    return p;
}
node *G[50];int visited[50];
void BFS(int vertex)
{
   node *curr;int adj,ver;
   visited[vertex]=1;
   printf("%d",vertex);
   insert(vertex);
   while(!isempty())
   {
       ver=delete();
       curr=G[ver];
       while(curr!=NULL)
       {
           adj=curr->vertex;
           if(!visited[adj])
           {
               visited[adj]=1;
               printf("%d",adj);
               insert(adj);
           }
           curr=curr->next;
       }
   }
}
void DFS(int vertex)
{
    node* curr;int adj;
    visited[vertex]=1;
    printf("%d",vertex);
    curr=G[vertex];
    while(curr!=NULL)
    {
        adj=curr->vertex;
        if(!visited[adj])
           DFS(adj);
        curr=curr->next;
    }
}
node* createnode(int v)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->vertex=v;
    newnode->next=NULL;
    return newnode;
}
void addedge(int src,int dest)
{
    node* newnode=createnode(dest);
    newnode->next=G[src];
    G[src]=newnode;

    newnode=createnode(src);
    newnode->next=G[dest];
    G[dest]=newnode;
}
void printgraph(int nv)
{
    int v;node* temp;
    for(v=0;v<nv;v++)
    {
        temp=G[v];
        printf("Adjacency list of vertex %d\n",v);
        while(temp)
        {
         printf("%d->",temp->vertex);
         temp=temp->next;
        }
        printf("|n");
    }
}
int main()
{
    int i,v1,v2,V,E;
    printf("\t\tGraph\n");
    printf("Enter the number of edges");
    scanf("%d",&E);
    printf("Enter the number of vertices");
    scanf("%d",&V);
    for(i=0;i<V;i++)
    {
        G[i]=NULL;
    }
    for(i=0;i<E;i++)
    {
        printf("Enter the edges (format: v1 v2)");
        scanf("%d%d",&v1,&v2);
        addedge(v1,v2);
    }
    printgraph(V);
    BFS(0);
    return 0;
}