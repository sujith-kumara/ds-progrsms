//quicksort

#include <stdio.h>
#include<stdio.h>
void swap(int *p,int *q)
{
int t;
t=*p;
*p=*q;
*q= t;
}

int partition( int a[],int f,int l)
{ int key=a[f],i=f+1,j=l;
do
{ while(i<j && a[i]<key)
   i++;
  while(j>f && a[j]>key)
   j--;
   if(i<j)
    swap(&a[i],&a[j]);
}while(i<j);
swap(&a[j],&a[f]);
return(j); 
}
void qsort(int a[],int l,int r)
{ int m;
  if(l<r)
   {
     m=partition(a,l,r);
     qsort(a,l,m-1);
     qsort(a,m+1,r);
    }
  } 
void printnum(int x[],int n)
{
  int i;
   for(i=0;i<n;i++)
    printf("\n  %d",x[i]);
}
void main()
{int n,i,a[100];
printf("\nEnter N\n");
scanf("%d",&n);
printf("enter the elements to be sorted");
for(i=0;i<n;i++)
   scanf("%d",&a[i]);
qsort(a,0,n-1);
for(i=0;i<n;i++)
printf("   %d",a[i]);

}