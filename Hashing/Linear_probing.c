//Linear probing
#include<stdio.h>
#include<stdlib.h>
void insert(int *n,int *a);
void search(int *n,int *a);
void display(int *n,int *a);

void insert(int *n,int *a)
{
    int i,key;
    int hk;
    printf("\nEnter key to be inserted:");
    fflush(stdin);
    scanf("%d",&key);
    fflush(stdin);
    hk=key%(*n);
    for(i=0;i<*n;i++)
    {
        if(a[(hk+i)%(*n)]==0)
        {
            a[(hk+i)%(*n)]=key;
            break;
        }
    }
    if(i==*n)
    {
        printf("\nElement cannot be inserted");
    }
}
void search(int *n,int *a)
{
    int i,key;
    int hk;
    printf("\nEnter key to be searched:");
    fflush(stdin);
    scanf("%d",&key);
    fflush(stdin);
    hk=key%(*n);
    for(i=0;i<*n;i++)
    {
        if(a[(hk+i)%(*n)]==key)
        {
            printf("\nElement found at index %d",(hk+i)%(*n));
            break;
        }
    }
    if(i==*n)
    {
        printf("\nElement not found");
    }
}
void display(int *n,int *a)
{
    int i;
    printf("\nelements in the hash table are \n");
    for (i = 0; i < *n; i++)
        printf("\nat index %d \t value = %d", i, a[i]);
}
void main()
{
    int ch,i;
    int n;
    int *a;

    printf("\nEnter size of the hash table:");
    fflush(stdin);
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        a[i]=0;
    }
    while(1)
    {
        printf("\n1.Insert 2.Display 3.Search 4.Exit\n");
        fflush(stdin);
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert(&n,a);
                break;
            case 2:
                display(&n,a);
                break;
            case 3:
                search(&n,a);
                break;
            case 4:
                exit(0);

        }
    }

}