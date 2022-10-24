//Bucket sort
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, j, k, n, max, min, *bucket, *a;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    max = a[0];
    min = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    bucket = (int *)malloc((max - min + 1) * sizeof(int));
    for (i = 0; i < max - min + 1; i++)
        bucket[i] = 0;
    for (i = 0; i < n; i++)
        bucket[a[i] - min]++;
    for (i = 0, j = 0; i < max - min + 1; i++)
        for (k = bucket[i]; k > 0; k--)
            a[j++] = i + min;
    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}