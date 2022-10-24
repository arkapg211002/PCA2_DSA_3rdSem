//.Interpolation Search
#include<stdio.h>
#include<stdlib.h>
void interpolation_search(int *p,int n,int x,int l,int r);
void main()
{
    int n;
    int *p;
    int x;
    printf("\nEnter number of elements:");
    scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int));
    printf("\nThe array elements are:");
    for(int i=0;i<n;i++)
    {
        printf("\nEnter element at position %d:",i);
        scanf("%d",&p[i]);
    }
    printf("\nEnter element to be searched for:");
    scanf("%d",&x);
    interpolation_search(p,n,x,0,n-1);
    printf("Element not found");
}
void interpolation_search(int *p,int n,int x,int l,int r)
{
    int m=l+((x-p[l])*(r-l))/(p[r]-p[l]);
    if(l>r)
    {
        return;
    }
    if(p[m]==x)
    {
        printf("Element found at position %d",m);
        exit(0);
    }
    else if(p[m]>x)
    {
        interpolation_search(p,n,x,l,m-1);
    }
    else
    {
        interpolation_search(p,n,x,m+1,r);
    }
}
