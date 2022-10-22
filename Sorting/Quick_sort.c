//Quick Sort
#include<stdio.h>
#include<stdlib.h>
void swap(int *p,int i,int j)
{
    int t=p[i];
    p[i]=p[j];
    p[j]=t;
}
void quick(int *p,int l,int r)
{
    int i,last;
    if(l>=r)return;
    last=l;
    swap(p,l,(l+r)/2);
    for(i=l+1;i<=r;i++)
    {
        if(p[l]>p[i])
        {
            swap(p,++last,i);
        }
    }
    swap(p,last,l);
    quick(p,l,last-1);
    quick(p,last+1,r);
}
void main()
{
    int n;
    int *p;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int));
    printf("\nEnter the elements:");
    for(int i=0;i<n;i++)
    {
        printf("\nEnter element at position %d:",i);
        scanf("%d",&p[i]);
    }
    quick(p,0,n-1);
    printf("\nThe sorted array is:");
    for(int i=0;i<n;i++)
    {
        printf("\t%d",p[i]);
    }
}