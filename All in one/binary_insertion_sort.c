//Binary Insertion Sort
#include<stdio.h>
#include<stdlib.h>
int binarysearch(int *p,int a,int l,int r)
{
    int m;
    if(l>=r)
    {
        return (a>p[l])?l+1:l;
    }
    m=(l+r)/2;
    if(a==p[m])
    {
        return m+1;
    }
    else if(a>p[m])
    {
        return binarysearch(p,a,m+1,r);
    }
    else return binarysearch(p,a,l,m-1);
}
void binaryinsertionsort(int *p,int n)
{
    int i,j,k,loc;
    for(i=1;i<n;i++)
    {
        k=p[i];
        j=i-1;
        loc=binarysearch(p,k,0,j);
        while(j>=loc)
        {
            p[j+1]=p[j];
            j=j-1;
        }
        p[j+1]=k;
    }
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
    binaryinsertionsort(p,n);
    printf("\nThe sorted array is:");
    for(int i=0;i<n;i++)
    {
        printf("\t%d",p[i]);
    }

}
