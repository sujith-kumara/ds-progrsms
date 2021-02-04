// insertion sort ascending order
#include<stdio.h>
void swap(int*p,int*q)
{
 int temp;
 temp=*p;
 *p=*q;
 *q=temp;
}
void insertionsort(int a[],int n)
{
 int temp,i,j;
 for(i=1;i<n;i++)
 {
  j=i;
  
  while((a[j]<a[j-1])&&j>0)
  {
   swap(&a[j],&a[j-1]);
   j--;
  }
 }
}

 void main()
 {
  int i,n;
  printf("enter number of elements\n");
  scanf("%d",&n);
  int a[n];
  printf("enter numbers\n");
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }
  insertionsort(a,n);
  printf("Array after sort\n");
  for(i=0;i<n;i++)
  {
   printf("%d\n",a[i]);
  }
 }
