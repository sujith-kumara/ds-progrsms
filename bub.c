//bubblesort 2 using same function
#include<stdio.h>
void swap(int*p,int*q)
{
 int temp;
 temp=*p;
 *p=*q;
 *q=temp;
}
void bubblesort(int a[],int n)
{
 int i,j,temp;
 for(i=0;i<n;i++)
 {
  
  for(j=0;j<n-i-1;j++)
  {
   if(a[j]>a[j+1])
    {
     swap(&a[j],&a[j+1]);
    }
   }
  }
  printf("Array after sort\n");
  for(i=0;i<n;i++)
  {
   printf("%d\n",a[i]);
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
  bubblesort(a,n);
 }