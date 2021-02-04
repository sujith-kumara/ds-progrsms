#include <stdio.h>
#include <stdlib.h>
#define  size 50
struct NODE {
  int vertex;
  struct NODE* next;
};

typedef struct NODE node;
int Q[size];
int f=-1,r=-1;
int isemptyQ()
{ return(f==-1);}
int isfullQ()
 { return( f==(r+1)%size);}
void insertQ(int p)
{ if(isemptyQ())
    f=r=0;
  else
     if(isfullQ())
       {printf("Error Q full"); exit(0);}
     else
      r=(r+1)%size;
  Q[r]=p;
}

 int deleteQ()
  { int p;
    if(isemptyQ())
     { printf(" Q empty ");exit(0);}
    else
      { p= Q[f];
        if(f==r)
          f=r=-1;
        else
          f=(f+1)%size;
       }
  return (p);
    }
node *G[50]; int visited[50];
void BFS(int vertex)
{node *curr;int adj,ver;
 visited[vertex]=1;
 printf(" %d ", vertex);
 insertQ(vertex);
 while(!isemptyQ())
   {  ver=deleteQ();
      curr=G[ver];
      while(curr!=NULL)
        { adj=curr->vertex;
          if(!visited[adj] )
           {
            visited[adj]=1;
            printf(" %d ", adj);
            insertQ(adj);
            }
          curr=curr->next;
         }
    }
    
}

void DFS( int vertex)
 {
   node* curr;int adj; 
   visited[vertex] = 1;
   printf(" %d ", vertex);
   curr=G[vertex];
   while(curr != NULL)
    { adj= curr->vertex;
      if(!visited[adj] )
         DFS(adj);
      curr=curr->next;
     }
  }

// Create a node
  node* createNode(int v) {
  node* newNode = (node *)malloc(sizeof(node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}


// Add edge
void addEdge( int src, int dest) {
  // Add edge from src to dest
  node* newNode = createNode(dest);
  newNode->next = G[src];
  G[src]=newNode;
  // Add edge from dest to src  for undirected graph
newNode = createNode(src);
  newNode->next = G[dest];
  G[dest] = newNode;
}

// Print the graph
void printGraph(int nv) {
  int v;node* temp;
  for (v = 0; v < nv; v++) {
    temp = G[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  int i,j,v1,v2,E,V;
    printf("\t\t\tGraphs\n");
    printf("Enter the no of edges:");
    scanf("%d",&E);
    printf("Enter the no of vertices:");
    scanf("%d",&V);
    for(i=0;i<V;i++)
    {
     G[i]=NULL;   
    }
    /*    creating edges :P    */
    for(i=0;i<E;i++)
    {
        printf("Enter the edges (format: V1 V2) : ");
        scanf("%d%d",&v1,&v2);
        addEdge(v1,v2);
    }
  
  printGraph(V);

  BFS(0);

  return 0;
}