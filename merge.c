//mergesort

#include<stdio.h>
void smerge( int a[],int f,int s,int l)
{ int i=f,j=s,k=0, t[100];
  while(i<s && j<=l)
   {  
    if(a[i]<a[j])
      t[k++]=a[i++];
    else
       t[k++]=a[j++];
    }
while(i<s) t[k++]=a[i++];
while( j<=l) t[k++]=a[j++];
for(i=f,j=0;j<k;)
a[i++]=t[j++];
}
void msort(int a[],int l,int r)
{int m;
if(l<r)
 { m=(l+r)/2;
   //printf("\nF-msort(a,%d,%d)",l,m);
   msort(a,l,m);
  // printf("\nS-msort(a,%d,%d)",l,m);
   msort(a,m+1,r);
  //printf("\nsmerge(a,%d,%d,%d)",l,m+1,r);
   smerge(a,l,m+1,r);}
}

void main()
{int n,i,a[100];
printf("enter the no of elements to besorted");
scanf("%d",&n);
printf("enter the elements");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
 //printf("\nMain-msort(a,%d,%d)",0,n-1);
msort(a,0,n-1);
for(i=0;i<n;i++)
printf("   %d",a[i]);

}