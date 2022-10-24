//Count Sort
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, j, k, n, *a, *b, max = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > max)
            max = a[i];
    }
    b = (int *)malloc((max + 1) * sizeof(int));
    for (i = 0; i <= max; i++)
        b[i] = 0;
    for (i = 0; i < n; i++)
        b[a[i]]++;
    i = 0;
    j = 0;
    while (i <= max)
    {
        if (b[i] > 0)
        {
            a[j] = i;
            b[i]--;
            j++;
        }
        else
            i++;
    }
    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}