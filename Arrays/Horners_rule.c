/*C program to implement horners rule*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n;
    int *p;
    int x;
    int i;
    printf("\nEnter the degree of the polynomial:");
    scanf("%d",&n);
    p=(int *)malloc((n+1)*sizeof(int));
    printf("\nEnter the coefficients of the polynomial:");
    for(i=0;i<=n;i++)
    {
        printf("\nEnter coefficient of x^%d:",(n-i));
        scanf("%d",&p[i]);
    }
    printf("\nEnter the value of x:");
    scanf("%d",&x);
    int res=p[0];
    for(i=1;i<=n;i++)
    {
        res=res*x+p[i];
    }
    printf("\nResult is:%d",res);

}