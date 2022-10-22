#include<stdio.h>
#include<stdlib.h>
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
    for(int i=0;i<n;i++)
    {
        if(p[i]==x)
        {
            printf("\nElement found at position %d",i);
            exit(0);
        }
    }
    printf("\nElement not found");
}