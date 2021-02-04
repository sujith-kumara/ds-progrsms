//binary search using funcion
#include<stdio.h>
void binarysearch(int a[],int n)
{
 int i,key,low,mid,high,flag=0;
 printf("Enter the element to be searched\n");
 scanf("%d",&key);
 low=1;
 high=n;
 do
  {
   mid=(high+low)/2;
   if(key<a[mid])
    {
     high=mid-1;
    }
   else if(key>a[mid])
    {
     low=mid+1;
    }
   else
    {
     flag=1;
     break;
    }
   }while(low<=high);
  if(flag==1)
   {
    printf("Search for %d is successful at position %d\n",key,mid+1);
   }
  else
   {
    printf("search is not successful element is not in the given array");
   }
  }

void main()
 {
  int i,j,n;
  printf("enter number of elements\n");
  scanf("%d",&n);
  int a[n];
  printf("enter numbers\n");
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }
  binarysearch(a,n);
 }