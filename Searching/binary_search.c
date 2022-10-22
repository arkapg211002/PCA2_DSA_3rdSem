//Binary search
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n;
    int *p;
    int i;
    int x;
    int l,u,m;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int));
    printf("\nEnter the elements:");
    for(i=0;i<n;i++)
    {
        printf("\nEnter element at position %d:",i);
        scanf("%d",&p[i]);
    }
    printf("\nThe array elements are:");
    for(i=0;i<n;i++)
    {
        printf("\nElement at position %d is %d",i,p[i]);
    }
    printf("\nEnter element to be searched for:");
    scanf("%d",&x);
    l=0;
    u=n-1;
    while(l<=u)
    {
        m=(l+u)/2;
        if(p[m]==x)
        {
            printf("\nelement found at position %d",m);
            exit(0);
        }
        else if(p[m]>x)
        {
            u=m-1;
        }
        else
        {
            l=m+1;
        }

    }
    printf("\nElement not found");


}