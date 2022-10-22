//Bubble sort
#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int *p, int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void main()
{
    int n;
    int *p;
    printf("\nEnter number of elements:");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    printf("\nThe array elements are:");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter element at position %d:", i);
        scanf("%d", &p[i]);
    }
    bubble_sort(p, n);
    printf("\nThe sorted array is:");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", p[i]);
    }
}