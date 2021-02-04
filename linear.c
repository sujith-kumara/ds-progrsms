//linear search using function
#include<stdio.h>
void linearsearch(int a[],int n)
{
 int i,key,flag=0;
 printf("Enter the element to be searched");
 scanf("%d",&key);
 for(i=0;i<n;i++)
  {
   if(a[i]==key)
    {
     flag= 1;
      break;
    }
  }
  if(flag==1)
   {
    printf("%d is present at location%d\n",key,i+1);
   }
  else
   {
    printf("Search is not successful\n");
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
  linearsearch(a,n);
 }