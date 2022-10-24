/*Write a C program to input a matrix and check whether it is 
sparse or not. If it is a sparse matrix, display it in 3 tuple form and find the transpose.*/

#include<stdio.h>
#include<stdlib.h>
void main()
{
    int r,c;
    int **p;
    int i,j;
    int count=0;
    printf("\nEnter number of rows:");
    scanf("%d",&r);
    printf("\nEnter number of columns:");
    scanf("%d",&c);
    p=(int **)malloc(r*sizeof(int *));
    for(i=0;i<r;i++)
    {
        p[i]=(int *)malloc(c*sizeof(int));
    }
    printf("\nEnter elements of matrix:");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("\nEnter element at position [%d][%d]:",i,j);
            scanf("%d",&p[i][j]);
            if(p[i][j]==0)
            {
                count++;
            }
        }
    }
    printf("\nMatrix is:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",p[i][j]);
        }
        printf("\n");
    }
    if(count>(r*c)/2)
    {
        printf("\nMatrix is sparse");
        printf("\n3 tuple form is:\n");
        printf("\nRow\tColumn\tValue");
        printf("\n%d\t%d\t%d",r,c,((r*c)-count));
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(p[i][j]!=0)
                {
                    printf("\n%d\t%d\t%d",i,j,p[i][j]);
                }
            }
        }
        printf("\nTranspose of matrix is:");
        for(i=0;i<c;i++)
        {
            for(j=0;j<r;j++)
            {
                printf("%d\t",p[j][i]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nMatrix is not sparse");
    }

    
}