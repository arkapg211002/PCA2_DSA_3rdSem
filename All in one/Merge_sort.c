//Merge sort
#include<stdio.h>
#include<stdlib.h>
void merge(int *p,int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int *L,*R;
    L=(int *)malloc(n1*sizeof(int));
    R=(int *)malloc(n2*sizeof(int));
    for(i=0;i<n1;i++)
    {
        L[i]=p[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=p[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
        {
            p[k]=L[i];
            i++;
        }
        else 
        {
            p[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        p[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        p[k]=R[j];
        j++;
        k++;
    }

}
void merge_sort(int *p,int l,int r)
{
    int m;
    if(l<r)
    {
        m=l+(r-l)/2;
        merge_sort(p,l,m);
        merge_sort(p,m+1,r);
        merge(p,l,m,r);
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
    merge_sort(p,0,n-1);
    printf("\nThe sorted array is:");
    for(int i=0;i<n;i++)
    {
        printf("\t%d",p[i]);
    }
}