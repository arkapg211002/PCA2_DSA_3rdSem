//selection sort
#include <stdio.h>
#include <stdlib.h>
void selection_sort(int *p, int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (p[j] < p[min])
            {
                min = j;
            }
        }
        temp = p[i];
        p[i] = p[min];
        p[min] = temp;
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
    selection_sort(p, n);
    printf("\nThe sorted array is:");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", p[i]);
    }
}
