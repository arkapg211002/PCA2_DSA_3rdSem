#include<stdio.h>
#include<stdlib.h>
int horner(int *p,int n,int x)
{
    if(n==0)
    {
        return p[0];
    }
    else{
        return horner(p,n-1,x)*x+p[n];
    }
}
void main()
{
    int n;
    int *p;
    int x;
    printf("\nEnter degree of polynomial:");
    scanf("%d",&n);
    
    p=(int *)malloc((n+1)*sizeof(int));
    printf("\nEnter coefficients of polynomial:");
    for(int i=0;i<=n;i++)
    {
        printf("\nEnter coefficient of x^%d:",(n-i));
        scanf("%d",&p[i]);
    }
    printf("\nEnter value of x:");
    scanf("%d",&x);
    printf("\nResult is:%d",horner(p,n,x));
}