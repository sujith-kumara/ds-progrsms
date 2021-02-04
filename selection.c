//selection sort using function
#include<stdio.h>
void swap(int*p,int*q)
{
 int temp;
 temp=*p;
 *p=*q;
 *q=temp;
}
void selectionsort(int a[],int n)
{
 int p,q,ind,temp,key;
 for(p=0;p<n-1;p++)
 {
  key=a[p];
  ind=p;
  for(q=p+1;q<n;q++)
  {
   if(a[q]<key)
   {
    key=a[q];
    ind=q;
   }
  }
   swap(&a[p],&a[ind]);
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
  selectionsort(a,n);
  printf("Array after sort\n");
  for(i=0;i<n;i++)
  {
   printf("%d\n",a[i]);
  }
 }
   
    
 