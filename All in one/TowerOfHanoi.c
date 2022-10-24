//Tower Of Hanoi
#include<stdio.h>
#include<stdlib.h>
void initialisation(int *stepcount)
{
    *stepcount=0;
}
void tower(int *stepcount,int n,char s,char a,char t)
{
    if(n>0)
    {
        tower(stepcount,n-1,s,t,a);
        printf("Step no %d : Move disk %d from %c to %c\n",++(*stepcount),n,s,t);
        tower(stepcount,n-1,a,s,t);
    }
}
void main()
{
    int n,stepcount;
    printf("\nEnter number of disks:");
    scanf("%d",&n);
    initialisation(&stepcount);
    tower(&stepcount,n,'A','B','C');
}