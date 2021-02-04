//heapsort

#include<stdio.h>
int left(int i)
{return(2*i);}
int right(int i)
{return(2*i+1);}
void swap(int *p,int *q)
{
int t;
t=*p;
*p=*q;
*q= t;
}
void heapify(int a[],int i, int size)
{int lar=i,l,r;
  l=left(i);r=right(i);
  if(a[l]>a[lar] && l<=size)
    lar=l;
  if(a[r]>a[lar] && r<=size)
    lar=r;
  if(lar!= i)
   {swap(&a[lar],&a[i]);heapify(a,lar,size);}
}  
void buildheap(int a[],int n)
{ int i;
  for(i=n/2 ; i>=1; i--)
   heapify(a,i,n);
}
void hsort(int a[],int n)
{int i,size=n;
 buildheap(a,n);

 for(i=1;i<n;i++)
  {swap(&a[1],&a[size]);
   size--;heapify(a,1,size);}
}



void main()
{int n,i,a[100];
printf("\nEnter N\n");
scanf("%d",&n);
printf("Enter  %d elements\n",n);
for(i=1;i<=n;i++)
   scanf("%d",&a[i]);
 
hsort(a,n);
for(i=1;i<=n;i++)
printf(" \n  %d",a[i]);

}