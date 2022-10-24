//Insertion sort
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n;
    int *p;
    int i,j,key;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int));
    printf("Enter the elements:");
    for(i=0;i<n;i++)
    {
        printf("\nEnter element at position %d:",i);
        scanf("%d",&p[i]);

    }
    for(i=1;i<n;i++)
    {
        key=p[i];
        j=i-1;
        while(j>=0 && p[j]>key)
        {
            p[j+1]=p[j];
            j=j-1;
        }
        p[j+1]=key;
    }
    printf("The sorted array is:");
    for(i=0;i<n;i++)
    {
        printf("\t%d",p[i]);
    }
    
}